# RockBed

[![Tests Status](https://img.shields.io/travis/smallstoneapps/rockbed.svg?style=flat-square&label=tests)][travis] ![Version 1.1.0](https://img.shields.io/badge/version-1.1.0-blue.svg?style=flat-square) [![MIT License](https://img.shields.io/badge/license-MIT-red.svg?style=flat-square)](./LICENSE)

## Usage

To use RockBed to add unit tests to your Pebble app or watchface, you will need
to follow these steps:

1. Create a `tests` folder and copy the contents of `dist/tests/` into it.
2. Add Makefile to run tests. You can use `dist/Makefile` as a starting point.
3. Use the comments in your new Makefile to work out what you need to fill out.
4. Run `./tests/scripts/local-install.sh PEBBLE_DIR` where `PEBBLE_DIR` is the location of your Pebble SDK folder.
5. Check that everything is okay by running `make test`. If no errors appear, you can start writing your tests!

[travis]: https://travis-ci.org/smallstoneapps/rockbed/
