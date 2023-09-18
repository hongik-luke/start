/*
백준 문제 풀이 1541
1931 풀다가 GG ... 다음에 꼭 풀어보자
2217
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
#include <string.h>


int main(void)
{
	char first[51];
	char second[51][51];
	char* ptr;
	char* ptr2;
	int count = 0;
	int temp;
	int result = 0;
	scanf("%s", &first);

	ptr = strtok(first, "-");

	while (ptr != NULL) 
	{
		
		strcpy(second[count], ptr);
		
		ptr = strtok(NULL, "-");
		count++;
	}
	
	ptr2 = strtok(second[0], "+");

	while (ptr2 != NULL)
	{

		result += atoi(ptr2);
		ptr2 = strtok(NULL, "+");

	}

	
	for (int i = 1 ; i<count ; i++)
	{
		temp = 0;
		ptr2 = strtok(second[i], "+");

		while (ptr2 != NULL)
		{

			temp += atoi(ptr2);
			ptr2 = strtok(NULL, "+");

		}

		result -= temp;
	}

	printf("%d", result);

	int N;
	int weight = 0;
	int row[100000];
	int temp, i;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &row[i]);
	}

	qsort(row, N, sizeof(int), compare);

	i = 0;

	while (N)
	{
		temp = N * row[i];

		if (weight < temp)
			weight = temp;

		i++, N--;
	}

	printf("%d", weight);

}

