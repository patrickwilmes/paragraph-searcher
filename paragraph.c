#include "paragraph.h"
#include <stdio.h>

void print_paragraph(char *text, int paragraph_number) {
    int paragraph_counter = 0;
    int i = 0;
    while (paragraph_counter < paragraph_number) {
        if (text[i] == '\n' || text[i] == '\r') {
            paragraph_counter++;
        }
        i++;
    }
    i++;
    for (int j = i; text[j] != '\n' && text[j] != '\r'; j++) {
        printf("%c", text[j]);
    }
    printf("\n");
}
