/*

RockBed v1.1.0
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

tests/tests.c

*/

#include <pebble.h>
#include <pebble_extra.h>
#include <defines.h>

#include "unit.h"

#define VERSION_LABEL "1.1.0"

// Keep track of how many tests have run, and how many have passed.
int tests_run = 0;
int tests_passed = 0;

typedef struct TestObject {
  char str[24];
  int number1;
  uint8_t number2;
  bool boolean;
} TestObject;

static void before_each(void) {
  persist_init();
}

static void after_each(void) {
  persist_clear();
}

static char* test_exists_fail(void) {
  bool pass = (false == persist_exists(0));
  mu_assert(pass, "Something exists when it shouldn't.");
  return 0;
}

static char* test_exists_success(void) {
  persist_write_int(0, 5);
  bool pass = (true == persist_exists(0));
  mu_assert(pass, "Something doesn't exist when it should.");
  return 0;
}

static char* test_int_single(void) {
  persist_write_int(1, 7484);
  bool pass = (7484 == persist_read_int(1));
  mu_assert(pass, "Reading int returned different value");
  return 0;
}

static char* test_int_multiple(void) {
  persist_write_int(1, 7484);
  persist_write_int(2, 500);
  persist_write_int(3, 400);
  persist_write_int(1, -5);
  bool pass = (-5 == persist_read_int(1));
  pass = pass && (500 == persist_read_int(2));
  pass = pass && (400 == persist_read_int(3));
  mu_assert(pass, "Reading ints returned different values");
  return 0;
}

static char* test_string_single(void) {
  const char* test_str = "Hello, World!";
  persist_write_string(0, test_str);
  char tmp[32];
  persist_read_string(0, tmp, 32);
  bool pass = (0 == strcmp(tmp, test_str));
  mu_assert(pass, "Reading string returned different value");
  return 0;
}

static char* test_string_multiple(void) {
  const char* test_str1 = "Hello, World!";
  const char* test_str2 = "Goodbye, Earth?";
  persist_write_string(1, test_str2);
  persist_write_string(2, test_str1);
  char tmp1[32];
  char tmp2[32];
  persist_read_string(1, tmp1, 32);
  persist_read_string(2, tmp2, 32);
  bool pass = (0 == strcmp(tmp1, test_str2));
  pass = pass && (0 == strcmp(tmp1, test_str2));
  mu_assert(pass, "Reading strings returned different values");
  return 0;
}

static char* test_data_single(void) {
  TestObject* test = malloc(sizeof(TestObject));
  strcpy(test->str, "fnjlenilvnlineibfieinif");
  test->number1 = 51;
  test->number2 = 9;
  test->boolean = true;
  persist_write_data(1, test, sizeof(TestObject));
  TestObject test_output;
  persist_read_data(1, &test_output, sizeof(TestObject));
  bool pass = (0 == strcmp(test->str, test_output.str));
  pass = pass && (test->number1 == test_output.number1);
  pass = pass && (test->number2 == test_output.number2);
  pass = pass && (test->boolean == test_output.boolean);
  mu_assert(pass, "Reading data returned different value");
  return 0;
}

#ifdef PBL_PLATFORM_BASALT
static char* test_delete(void) {
  persist_write_int(1, 7484);
  bool pass = (true == persist_exists(1));
  persist_delete(1);
  pass = pass && (false == persist_exists(1));
  mu_assert(pass, "Deleted key still exists.");
  return 0;
}
#endif

static char* all_tests() {
  mu_run_test(test_exists_fail);
  mu_run_test(test_exists_success);
  mu_run_test(test_int_single);
  mu_run_test(test_int_multiple);
  mu_run_test(test_string_single);
  mu_run_test(test_string_multiple);
  mu_run_test(test_data_single);
  #ifdef PBL_PLATFORM_BASALT
  mu_run_test(test_delete);
  #endif
  return 0;
}

int main(int argc, char **argv) {
  printf("%s--------------------------------------------\n", KCYN);
  printf(" Running RockBed %s Test Suite for %s \n", VERSION_LABEL, argv[1]);
  printf("--------------------------------------------\n%s", KNRM);
  char* result = all_tests();
  if (0 != result) {
    printf("%s - Failed Test:%s %s\n", KRED, KNRM, result);
  }
  printf(" - Tests Run: %s%d%s\n", (tests_run == tests_passed) ? KGRN : KRED, tests_run, KNRM);
  printf(" - Tests Passed: %s%d%s\n", (tests_run == tests_passed) ? KGRN : KRED, tests_passed, KNRM);

  printf("%s--------------------------------------------%s\n", KCYN, KNRM);
  return result != 0;
}
