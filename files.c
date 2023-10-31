#include "files.h"
#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#elif defined(__linux__) || defined(__unix__)
#include <sys/stat.h>
#endif
#include <stdlib.h>
#include <stdio.h>

int file_exists(char *filename) {
#if defined(__linux__) || defined(__unix__)
    struct stat buffer;
    return (stat(filename, &buffer) == 0);
#elif defined(_WIN32) || defined(_WIN64)
    DWORD  dw_attrib = GetFileAttributes(filename);
    return (dw_attrib != INVALID_FILE_ATTRIBUTES && !(dw_attrib & FILE_ATTRIBUTE_DIRECTORY));
#endif
}

char* read_file(char *filename) {
    FILE *fp;
    if (fopen_s(&fp, filename, "r") != 0) {
        printf("Could not open file %s.\n", filename);
        return NULL;
    }
    fseek(fp, 0, SEEK_END);
    long fsize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char *text = malloc(fsize + 1);
    fread(text, fsize, 1, fp);
    if (fclose(fp) != 0) {
        printf("Could not close file %s.\n", filename);
        return NULL;
    }
//    printf("%s\n", text);
    return text;
}
