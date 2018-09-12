#pragma once

#define CHUNK 64

char *read(char* path) {
    char *str;
    size_t fsize;
    FILE *f = fopen(path, "r");
    fseek(f, 0, SEEK_END);
    fsize = ftell(f);
    rewind(f);
    str = malloc(fsize * (sizeof(char)));
    fread(str, sizeof(char), fsize, f);
    str[fsize * (sizeof(char))] = '\0';
    fclose(f);
    return str;
}

void write(char* path, char* str) {
    FILE *f = fopen(path, "w");
    if (f != NULL) {
        fputs(str, f);
        fclose(f);
    }
}
