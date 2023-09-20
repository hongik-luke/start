/*
1715 - 힙 배우면 꼭해보기!
백준 16953 1946 1449
*/

int static compare(const void* first, const void* second)
{
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}

#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>  
#include <string.h>\

int main(void)
{
	int A, B;
	int count = 0;
	int temp1;

	scanf("%d %d", &A, &B);

	temp1 = B;
	while (A <= temp1)
	{
		if (temp1 == A)
		{
			printf("%d", count+1);
			return 0;
		}

		if (temp1 % 10 == 1)
		{
			temp1 = temp1 / 10;
			count++;
		}

		else if (temp1 % 2 == 1)
		{
			printf("%d", -1);
			return 0;
		}

		else
		{
			temp1 = temp1 / 2;
			count++;
		}



	}

	printf("%d", -1);

	return 0;


	int M;
	int score[100000][2];
	int K;
	int min_score;
	int result_count1 = 1;

	scanf("%d", &M);

	for (int p = 0; p < M; p++)
	{
		scanf("%d", &K);
		for (int i = 0; i < K; i++)
		{
			scanf("%d %d", &score[i][0], &score[i][1]);
		}

		qsort(score, K, sizeof(score[0]), compare);


		min_score = score[0][1];

		for (int i = 1; i < K; i++)
		{
			if (min_score > score[i][1])
			{
				result_count1++;
				min_score = score[i][1];
			}

		}

		printf("%d\n", result_count1);

		result_count1 = 1;
	}

	int N, L;
	int water_location[1000];
	int distance;
	int fir_index,sec_index;
	int count = 1;
	scanf("%d %d", &N, &L);

	distance = L - 1;

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &water_location[i]);
	}

	qsort(water_location, N, sizeof(int), compare);

	fir_index = 0;
	sec_index = 0;

	while (sec_index <= N - 1)
	{
		if (water_location[sec_index] - water_location[fir_index] <= distance)
			sec_index++;
		else
		{
			fir_index = sec_index;
			count++;
		}
	
	} 

	printf("%d", count);

}
