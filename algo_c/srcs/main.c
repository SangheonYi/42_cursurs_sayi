
#include "solution.h"

int main() {
	// int lottos[] = {44, 1, 0, 0, 31, 25};
	int lottos[] = {0, 0, 0, 0, 0, 0};
	int lottos_len = 6;
	int win_nums[] = {31, 10, 45, 1, 6, 19};
	// int result[] = {3, 5};
	int result[] = {1, 6};
	int result_len = 2;
	int *answer = solution(lottos, lottos_len, win_nums, lottos_len);
	int i = 0;

	while (result_len > i)
	{
		printf("%d th: ", i);
		if (result[i] != answer[i])
			printf("🤩 result: %d, my answer: %d\n", result[i],  answer[i]);
		else
			printf("✅\n");
		i++;
	}
}
