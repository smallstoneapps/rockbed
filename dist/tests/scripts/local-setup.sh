#
# RockBed v1.0.0
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
# tests/scripts/local-setup.sh
#

SDK_INCLUDE_FOLDER=$1/Pebble/include
INCLUDE_FOLDER=tests/include
SRC_FOLDER=tests/src

mkdir -p $INCLUDE_FOLDER
mkdir -p $SRC_FOLDER
cp $SDK_INCLUDE_FOLDER/*.h $INCLUDE_FOLDER
echo '' > $INCLUDE_FOLDER/pebble_warn_unsupported_functions.h
touch $SRC_FOLDER/resource_ids.auto.h
