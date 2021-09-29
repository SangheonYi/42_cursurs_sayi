#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define C_NRML "\033[0m"
#define C_BLCK "\033[30m"
#define C_RED  "\033[31m"
#define C_GREN "\033[32m"
#define C_YLLW "\033[33m"
#define C_BLUE "\033[34m"
#define C_PRPL "\033[35m"
#define C_AQUA "\033[36m"

int* solution(int lottos[], size_t lottos_len, int win_nums[], size_t win_nums_len);
