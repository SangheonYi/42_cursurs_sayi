
#include "solution.h"

int arrlen(void *arr, size_t size) {
	if (size)
		return sizeof(arr) / size;
	return -1;
}

int main() {
	int lottos[] = {44, 1, 0, 0, 31, 25};
	int lottos_len = arrlen(lottos, sizeof(*lottos));
	int win_nums[] = {31, 10, 45, 1, 6, 19};
	int win_nums_len = arrlen(win_nums, sizeof(*win_nums));
	int result[] = {3, 5};
	int *answer = solution(lottos, lottos_len, win_nums, win_nums_len);
	int i = 0;

	while (arrlen(result, sizeof(*result)) > i++)
		printf("answer: %d\n", *(answer + i++));
}
