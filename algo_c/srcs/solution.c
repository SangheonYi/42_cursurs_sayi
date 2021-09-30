#include "solution.h"

int compare(const void *a, const void *b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;
    if (num1 < num2)
        return -1;
    if (num1 > num2)
        return 1;
    return 0;
}

void set_answer(int *answer, int hitcnt) {
    if (hitcnt >= 6)
        *answer = 1;
    else if (1 < hitcnt && hitcnt < 6 )
        *answer = 7 - hitcnt;
    else
        *answer = 6;
}

int* solution(int lottos[], size_t lottos_len, int win_nums[], size_t win_nums_len) {
    int* answer = calloc(sizeof(int), 2);
    int i = 0;
    int wildcard = 0;
    int hitcnt = 0;

    if (!answer)
        return NULL;
    qsort(lottos, lottos_len, sizeof(int), compare);
    qsort(win_nums, win_nums_len, sizeof(int), compare);
    while (lottos[wildcard] == 0)
        wildcard++;
    while (i < win_nums_len)
    {
        if(bsearch(win_nums + i, lottos, lottos_len, sizeof(int), compare))
            hitcnt++;
        i++;
    }
    set_answer(answer, hitcnt + wildcard);
    set_answer(answer + 1, hitcnt);
    return answer;
}

/* // 범위가 작을 때는 좋아 보인다.
int arr1[46];
int arr2[7]={6,6,5,4,3,2,1};

 int* solution(int lottos[], size_t lottos_len, int win_nums[], size_t win_nums_len) {
    int* answer = (int*)malloc(1);
    int min=0,max=0;

    for(int i=0;i<lottos_len;i++){
        arr1[lottos[i]]++;
    }

    for(int i=0;i<win_nums_len;i++){
        if(arr1[win_nums[i]])
            min++;
    }

    max=min+arr1[0];

    answer[0]=arr2[max];
    answer[1]=arr2[min];

    return answer;
}
*/
