
#include "solution.h"

int main() {
	// int lottos[] = {44, 1, 0, 0, 31, 25};
	const char * s = "one4seveneight";
	int answer = solution(s);
	int result[] = {1478};
	int result_len = 1;
	int i = 0;

	while (result_len > i)
	{
		printf("%d th: ", i);
		if (result[i] != answer)
			printf("🤩 result: %d, my answer: %d\n", result[i],  answer);
		else
			printf("✅\n");
		i++;
	}
}
