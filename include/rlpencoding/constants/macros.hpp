#ifndef CONSTANTS_MACROS_H
#define CONSTANTS_MACROS_H

#include <string>

const int EMPTY_STRING = 0x00;
const int NON_VALUE_STRING = 0x80;

const int SINGLE_BYTE_STRING = 0x37;
const int SHORT_STRING = 0x7f;
const int LONG_STRING = 0xb7;
const int LAST_STRING = 0xff;

const int SHORT_LIST = 0xbf;
const int LONG_LIST = 0xf6;

const std::string DEFAULT_DB_FILE = "/tmp/pmt.db";

#endif