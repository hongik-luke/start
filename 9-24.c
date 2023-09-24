/*
1783
1339
2812 - 스택을 사용해야만 풀 수 있는 것 같다..
*/

#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>  
#include <string.h>

int static compare(const void* first, const void* second)
{
	if (*(int*)first > *(int*)second)
		return -1;
	else if (*(int*)first < *(int*)second)
		return 1;
	else
		return 0;
}
int main(void)
{
	int N, M;


	scanf("%d %d", &N, &M);

	if (N == 1)
		printf("%d", 1);

	else if (N == 2)

		if (M <= 6)
			printf("%d", (M + 1) / 2);
		else
			printf("%d", 4);
	else
		if (M <= 4)
			printf("%d", M);
		else if (M == 5)
			printf("%d", 4);
		else
			printf("%d", M - 2);
	int N;
	int alpabet[26] = { 0, };
	char word[9];
	int word_len;
	int count = 0;

	int ten_square[8] = { 1,10,100,1000,10000,100000,1000000,10000000 };

	int result = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{

		scanf("%s", &word);
		word_len = strlen(word);

		count = 0;

		while (word_len != 0)
		{
			word_len--;
			alpabet[(int)word[count] - 65] += ten_square[word_len];
			count++;
		}
	}

	qsort(alpabet, 26, sizeof(int), compare);

	for (int i = 0; i < 9; i++)
	{
		result += alpabet[i] * (9 - i);
	}

	printf("%d", result);

	int N, K;
	int count = 0;
	int count_K;
	int index = 0;
	int max_num;
	int cnt = 0;
	char num[500000];
	
	scanf("%d %d", &N, &K);
	
	count_K = K;

	scanf("%s", &num);

	while (count != N - K)
	{
		max_num = num[index];
		for (int i = 1; i < count_K+1; i++)
		{
			
			if (num[index + i] > max_num)
			{
				cnt = i;
				max_num = num[index + i];
			}
		}

		if (num[index] == max_num)
		{
			printf("%c", num[index]);
			count++;
			index++;
		}

		else
		{
			count_K -= cnt;
			index += cnt;
			cnt = 0;
		}
	}

	return 0;
}



