#include "solution.h"

typedef struct  s_numbers
{
    int     digit;
    int     word_len;
    char    *word;
}               t_numbers;

const t_numbers digits[11] = {
    {0, 4, "ze"},
    {1, 3, "on"},
    {2, 3, "tw"},
    {3, 5, "th"},
    {4, 4, "fo"},
    {5, 4, "fi"},
    {6, 3, "si"},
    {7, 5, "se"},
    {8, 5, "ei"},
    {9, 4, "ni"},
    {-1, 1, "not word"},
    };

t_numbers find_word(const char *s) {
    int i = 0;
    while (i < 10)
    {
        if (*s == digits[i].word[0] && *(s + 1) == digits[i].word[1])
            break;
        i++;
    }
    return digits[i];
}

int solution(const char* s) {
    int         answer = 0;
    t_numbers   hit = digits[10];

    while (*s)
    {
        hit = find_word(s);
        if (hit.digit > -1)
            answer = answer * 10 + hit.digit;
        else
            answer = answer * 10 + *s -'0';
        s += hit.word_len;
    }
    return answer;
}

