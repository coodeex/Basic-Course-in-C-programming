#ifndef AALTO_STRINGSPLIT_H
#define AALTO_STRINGSPLIT_H

char** split_string(const char *str, const char* split);
void print_split_string(char **split_string);
void free_split_string(char **split_string);

#endif
