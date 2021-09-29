#include "solution.h"

void print_arr(int arr[], size_t len, char *name) {
    size_t i = 0;

    while (len > i)
    {
        printf("%s[%ld]: %d\n", name, i, arr[i]);
        i++;
    }
}
void Swap(int arr[], int a, int b) // a,b 스왑 함수
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
int Partition(int arr[], int left, int right)
{
    int pivot = arr[left]; // 피벗의 위치는 가장 왼쪽에서 시작
    int low = left + 1;
    int high = right;

    while (low <= high) // 교차되기 전까지 반복한다
    {
        while (low <= right && pivot >= arr[low]) // 피벗보다 큰 값을 찾는 과정
        {
            low++; // low를 오른쪽으로 이동
        }
        while (high >= (left+1)  && pivot <= arr[high]) // 피벗보다 작은 값을 찾는 과정
        {
            high--; // high를 왼쪽으로 이동
        }
        if (low <= high)// 교차되지 않은 상태이면 스왑 과정 실행
        {
            Swap(arr, low, high); //low와 high를 스왑
        }
    }
    Swap(arr, left, high); // 피벗과 high가 가리키는 대상을 교환
    return high;  // 옮겨진 피벗의 위치정보를 반환

}


void QuickSort(int arr[], int left, int right)
{
    if (left <= right)
    {
        int pivot = Partition(arr, left, right); // 둘로 나누어서
        QuickSort(arr, left, pivot - 1); // 왼쪽 영역을 정렬한다.
        QuickSort(arr, pivot + 1, right); // 오른쪽 영역을 정렬한다.
    }
}
// lottos_len은 배열 lottos의 길이입니다.
// win_nums_len은 배열 win_nums의 길이입니다.
int* solution(int lottos[], size_t lottos_len, int win_nums[], size_t win_nums_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(3);
    int i = 0;

    printf("💫 sort\n");
    print_arr(lottos, lottos_len, "unsorted lottos");
    QuickSort(lottos, 0, lottos_len - 1);
    print_arr(lottos, lottos_len, "sorted lottos");
    print_arr(win_nums, win_nums_len, "unsorted win_nums");
    QuickSort(win_nums, 0, win_nums_len - 1);
    print_arr(win_nums, win_nums_len, "sorted win_nums");


    answer[0] = 2;
    answer[1] = 3;
    answer[2] = 0;
    return answer;
}
