#include <stdio.h>
#include <string.h>

#include "../include/error.h"

typedef struct Data {
    char* src_file_path;
    char* search_term;
} Data;

void setup(int argc, char** argv, Data* data);

int main(int argc, char** argv) {
    Data data = {"", ""};
    setup(argc, argv, &data);

    return 0;
}

void setup(int argc, char** argv, Data* data) {
    if (argc != 4) error(ERR_INVALID_USAGE, CODE_INVALID_USAGE);
    int found_search_term = 0;
    int skip_next_arg = 0;
    for (int i = 1; i < 4; i++) {
        if (skip_next_arg) {
            skip_next_arg = 0;
            continue;
        }
        char* current_arg = argv[i];
        if (strcmp(current_arg, "-f") == 0) {
            data->src_file_path = argv[i+1];
            skip_next_arg = 1;
        }
        else if (!found_search_term) {
            data->search_term = current_arg;
            found_search_term = 1;
        }
    }
}