#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/error.h"
#include "../include/cgrep.h"
#include "../include/search.h"

const int MAX_FILE_SIZE = 100000;

void setup(int argc, char** argv, Data* data);

int main(int argc, char** argv) {
    // collect data from cmd args
    Data data = {"", ""};
    setup(argc, argv, &data);

    // read the text from the given file
    FILE* file_pointer = fopen(data.src_file_path, "r");
    char* file_text = (char*) malloc(MAX_FILE_SIZE * sizeof(char));
    do {
        char current_char = fgetc(file_pointer);
        strncat(file_text, &current_char, 1);
    } while (!feof(file_pointer));
    fclose(file_pointer);

    // generate the valid text
    char* valid_text = get_valid_text(file_text, data.search_term, MAX_FILE_SIZE);

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