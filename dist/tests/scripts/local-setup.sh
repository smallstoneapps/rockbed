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
# tests/scripts/local-setup.sh
#

SDK_INCLUDE_FOLDER_APLITE=$1/Pebble/aplite/include
SDK_INCLUDE_FOLDER_BASALT=$1/Pebble/basalt/include
INCLUDE_FOLDER=tests/include
SRC_FOLDER=tests/src

mkdir -p $INCLUDE_FOLDER/aplite
mkdir -p $INCLUDE_FOLDER/basalt
mkdir -p $SRC_FOLDER
cp $SDK_INCLUDE_FOLDER_APLITE/*.h $INCLUDE_FOLDER/aplite
cp $SDK_INCLUDE_FOLDER_BASALT/*.h $INCLUDE_FOLDER/basalt
echo '' > $INCLUDE_FOLDER/aplite/pebble_warn_unsupported_functions.h
echo '' > $INCLUDE_FOLDER/basalt/pebble_warn_unsupported_functions.h
echo 'typedef int time_t;' > $INCLUDE_FOLDER/basalt/time.h
echo '#define PBL_PLATFORM_BASALT\n#define PBL_COLOR' > $INCLUDE_FOLDER/basalt/defines.h
echo '#define PBL_PLATFORM_APLITE\n#define PBL_BW' > $INCLUDE_FOLDER/aplite/defines.h
touch $SRC_FOLDER/resource_ids.auto.h
