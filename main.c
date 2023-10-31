#include <stdio.h>
#include <stdlib.h>
#include "files.h"
#include "paragraph.h"

/*
 * This tool is used to print out a paragraph from a longer text file.
 * Therefor, one needs to handover two arguments: the text file to use,
 * and the number of the paragraph to print out.
 *
 * ./pargraph_searcher <textfile> <number>
 */

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: ./paragraph_searcher <textfile> <number>\n");
        return 1;
    }
    if (!file_exists(argv[1])) {
        printf("File %s does not exist.\n", argv[1]);
        return 1;
    }
    char *text = read_file(argv[1]);
    print_paragraph(text, atoi(argv[2]));
    free(text);
    return 0;
}
