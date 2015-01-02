/*

RockBed v1.0.0
A Pebble library for doing unit tests.
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

dist/tests/tests.c

*/

#include <pebble.h>
#include <pebble_extra.h>

#include "unit.h"

#define VERSION_LABEL "1.0.0"

// Keep track of how many tests have run, and how many have passed.
int tests_run = 0;
int tests_passed = 0;

static void before_each(void) {
  persist_init();
}

static void after_each(void) {
  persist_clear();
}

static char* all_tests() {
  return 0;
}

int main(int argc, char **argv) {
  printf("%s----------------------------------\n", KCYN);
  printf(" Running YourApp %s Test Suite \n", VERSION_LABEL);
  printf("----------------------------------\n%s", KNRM);
  char* result = all_tests();
  if (0 != result) {
    printf("%s - Failed Test:%s %s\n", KRED, KNRM, result);
  }
  printf(" - Tests Run: %s%d%s\n", (tests_run == tests_passed) ? KGRN : KRED, tests_run, KNRM);
  printf(" - Tests Passed: %s%d%s\n", (tests_run == tests_passed) ? KGRN : KRED, tests_passed, KNRM);

  printf("%s----------------------------------%s\n", KCYN, KNRM);
  return result != 0;
}
