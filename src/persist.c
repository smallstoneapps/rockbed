/*

RockBed v1.0.0
A suite and methdology for creating Pebble app unit tests.
http://smallstoneapps.github.io/rockbed/

----------------------

The MIT License (MIT)

Copyright © 2014 - 2015 Matthew Tole

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

--------------------

src/persist.c

*/

#include <pebble.h>
#include "pebble_extra.h"
#include "libs/linked-list/linked-list.h"
#include "persist.h"

static bool persist_compare(void* persist1, void* persist2);
static Persist* fake_persist(const uint32_t key);

void persist_reset(void) {
  linked_list_clear(persistence);
}

void persist_clear(void) {
  linked_list_clear(persistence);
}

void persist_init(void) {
  persistence = linked_list_create_root();
}

bool persist_exists(const uint32_t key) {
  return linked_list_contains_compare(persistence, fake_persist(key), persist_compare);
}

int persist_read_data(const uint32_t key, void *buffer, const size_t buffer_size) {
  uint16_t pos = linked_list_find_compare(persistence, fake_persist(key), persist_compare);
  Persist* persist = (Persist*) linked_list_get(persistence, pos);
  if (! persist) {
    return -1;
  }
  if (DATA != persist->type) {
    return -1;
  }
  memcpy(buffer, persist->data, buffer_size);
  return buffer_size;
}

int32_t persist_read_int(const uint32_t key) {
  Persist* persist = (Persist*) linked_list_get(persistence, linked_list_find_compare(persistence, fake_persist(key), persist_compare));
  if (! persist) {
    return -1;
  }
  if (NUMBER != persist->type) {
    return -1;
  }
  return persist->number;
}

status_t persist_write_int(const uint32_t key, const int32_t value) {
  persist_delete(key);
  Persist* persist = malloc(sizeof(Persist));
  persist->key = key;
  persist->type = NUMBER;
  persist->number = value;
  linked_list_append(persistence, persist);
  return 0;
}

int persist_write_data(const uint32_t key, const void *data, const size_t size) {
  persist_delete(key);
  Persist* persist = malloc(sizeof(Persist));
  persist->key = key;
  persist->type = DATA;
  persist->data = malloc(size);
  memcpy(persist->data, data, size);
  linked_list_append(persistence, persist);
  return size;
}

int persist_read_string(const uint32_t key, char *buffer, const size_t buffer_size) {
  Persist* persist = (Persist*) linked_list_get(persistence, linked_list_find_compare(persistence, fake_persist(key), persist_compare));
  if (! persist) {
    return -1;
  }
  if (STRING != persist->type) {
    return -1;
  }
  strncpy(buffer, persist->str, buffer_size);
  return buffer_size;
}

int persist_write_string(const uint32_t key, const char *cstring) {
  persist_delete(key);
  Persist* persist = malloc(sizeof(Persist));
  persist->key = key;
  persist->type = STRING;
  persist->str = malloc(strlen(cstring) + 1);
  strcpy(persist->str, cstring);
  linked_list_append(persistence, persist);
  return strlen(cstring);
}

status_t persist_delete(uint32_t key) {
  linked_list_remove(persistence, linked_list_find_compare(persistence, fake_persist(key), persist_compare));
  return S_SUCCESS;
}


static Persist* fake_persist(const uint32_t key) {
  Persist* p = malloc(sizeof(Persist));
  p->key = key;
  return p;
}

static bool persist_compare(void* persist1, void* persist2) {
  return ((Persist*)persist1)->key == ((Persist*)persist2)->key;
}
