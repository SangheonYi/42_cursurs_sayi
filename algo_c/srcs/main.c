
#include "solution.h"

int main() {
	int lottos[] = {44, 1, 0, 0, 31, 25};
	int win_nums[] = {31, 10, 45, 1, 6, 19};
	int result[] = {3, 5};
	int *answer = *solution(lottos, strlen(lottos), win_nums, strlen(win_nums));
	int i = 0;

	while (strlen(result) > i++)
		printf("answer: %d\n", *(answer + i++));
}
