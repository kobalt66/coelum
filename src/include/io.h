#ifndef IO_H
#define IO_H
#include <stdio.h>
#include <stdlib.h>


char* read_file(char* filename);

unsigned int file_exists(const char* filename);
#endif
