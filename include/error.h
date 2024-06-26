#ifndef __ERROR_H
#define __ERROR_H

const char* ERR_INVALID_USAGE = "Usage: cgrep term -f file_path";
const int CODE_INVALID_USAGE = 1;

void error(const char* message, int exit_code);

#endif