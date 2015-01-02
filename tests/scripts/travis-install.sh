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
# tests/scripts/travis-install.sh
#

SDK_VERSION=2.8.1
PACKAGE_NAME=PebbleSDK-$SDK_VERSION
SDK_INCLUDE_FOLDER=$PACKAGE_NAME/Pebble/include
INCLUDE_FOLDER=tests/include
SDK_ZIP_NAME=$PACKAGE_NAME.tar.gz

wget http://assets.getpebble.com.s3-website-us-east-1.amazonaws.com/sdk2/$SDK_ZIP_NAME
tar -zxf $SDK_ZIP_NAME
mkdir -p $INCLUDE_FOLDER
mv $SDK_INCLUDE_FOLDER/pebble.h $INCLUDE_FOLDER
mv $SDK_INCLUDE_FOLDER/pebble_fonts.h $INCLUDE_FOLDER
mv $SDK_INCLUDE_FOLDER/pebble_app_info.h $INCLUDE_FOLDER
touch $INCLUDE_FOLDER/pebble_warn_unsupported_functions.h