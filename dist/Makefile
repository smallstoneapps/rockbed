#
# RockBed v1.1.0
# A suite and methdology for creating Pebble app unit tests.
# http://smallstoneapps.github.io/rockbed/
#
# ----------------------
#
# The MIT License (MIT)
#
# Copyright © 2014 - 2015 Matthew Tole
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#
# --------------------
#
# dist/Makefile
#
# This is a template for the Makefile you willneed to use RockBed.
# See the comments below for the variables you should set.
#

CC=gcc
ifeq ($(TRAVIS), true)
CFLAGS=-std=c99
else
CFLAGS=-std=c11
endif

# Set the name of your app for nicer test output
APP_NAME=

# Paths to the files from your code that are needed for the tests
SRC_FILES=
# Paths to the files from any libraries used your code that are needed for the tests
LIB_FILES=
# Include flags for the above libraries
LIB_INCLUDES=

CINCLUDES=-I tests/ -I src/ $(LIB_INCLUDES)
CINCLUDES_APLITE=-I tests/include/aplite $(CINCLUDES)
CINCLUDES_BASALT=-I tests/include/basalt $(CINCLUDES)

TEST_FILES=tests/tests.c

all: test

test_aplite:
	@printf "\n"
	@$(CC) $(CFLAGS) $(CINCLUDES_APLITE) $(TEST_FILES) $(SRC_FILES) $(LIB_FILES) $(TEST_EXTRAS) -o tests/run 
	@tests/run Aplite || (echo '$(APP_NAME) test suite failed.' | terminal-notifier; exit 1)
	@rm tests/run
	
test_basalt:
	@printf "\n"
	@$(CC) $(CFLAGS) $(CINCLUDES_BASALT) $(TEST_FILES) $(SRC_FILES) $(LIB_FILES) $(TEST_EXTRAS) -o tests/run
	@tests/run Basalt || (echo '$(APP_NAME) test suite failed.' | terminal-notifier; exit 1)
	@rm tests/run

test: test_aplite test_basalt
	@printf "\x1B[0m"
	@printf "\n"
