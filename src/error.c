#include <stdio.h>
#include <stdlib.h>

void error(char* message, int error_code) {
    printf("%s\n", message);
    exit(error_code);
}