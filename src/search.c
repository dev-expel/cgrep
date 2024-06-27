#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../include/cgrep.h"

const int M_LINE_SIZE = 1000;
const int M_WORD_SIZE = 20;

int is_char_search_term(int index, char current_char, char* search_term);

char* get_valid_text(char* file_text, char* search_term, const int MAX_FILE_SIZE) {
    char* valid_text = (char*) malloc(100000 * sizeof(char));
    strcpy(valid_text, "");

    int is_current_line_valid = 0;
    char* current_line = (char*) malloc(M_LINE_SIZE * sizeof(char));
    char* possible_search_term = (char*) malloc(M_WORD_SIZE * sizeof(char));
    for (int i = 0, length = strlen(file_text); i < length; i++) {
        char current_char = file_text[i];

        if (current_char == '\n' || current_char == -1) {
            if (is_current_line_valid) 
                strncat(valid_text, current_line, strlen(current_line));

            strcpy(current_line, "");
            is_current_line_valid = 0;
        }
        strncat(current_line, &current_char, 1);

        if (isspace(current_char)) strcpy(possible_search_term, "");

        if ((is_char_search_term(strlen(possible_search_term), current_char, search_term)
             || strcmp(possible_search_term, "") != 0)
            && !is_current_line_valid) {
            strncat(possible_search_term, &current_char, 1);
            if (strcmp(possible_search_term, search_term) == 0) {
                is_current_line_valid = 1;
                strcpy(possible_search_term, "\0");
            }
        }
        

    }

    return valid_text;
}

int is_char_search_term(int index, char current_char, char* search_term) {
    return search_term[index] == current_char;
}