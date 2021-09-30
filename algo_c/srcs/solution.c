#include "solution.h"

int compare(const void *a, const void *b)    // 오름차순 비교 함수 구현
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if (num1 < num2)
        return -1;
    if (num1 > num2)
        return 1;
    return 0;
}

// lottos_len은 배열 lottos의 길이입니다.
// win_nums_len은 배열 win_nums의 길이입니다.
int* solution(int lottos[], size_t lottos_len, int win_nums[], size_t win_nums_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(3);
    int i = 0;

    // printf("💫 sort\n");
    // print_arr(lottos, lottos_len, "unsorted lottos");
    qsort(lottos, lottos_len, sizeof(int), compare);
    // print_arr(lottos, lottos_len, "sorted lottos");
    // print_arr(win_nums, win_nums_len, "unsorted win_nums");
    qsort(win_nums, win_nums_len, sizeof(int), compare);
    // print_arr(win_nums, win_nums_len, "sorted win_nums");


    answer[0] = 2;
    answer[1] = 3;
    answer[2] = 0;
    return answer;
}
