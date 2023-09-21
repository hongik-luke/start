/*
10610
1744 - 첫 골드문제!!
1931 - 진짜 힘들었다 구조체 정렬...
*/

#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>  
#include <string.h>

int static char_compare(const void* first, const void* second)
{
	if (*(char*)first > *(char*)second)
		return 1;
	else if (*(char*)first < *(char*)second)
		return -1;
	else
		return 0;
}

int static compare(const void* first, const void* second)
{
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}

int static reverse_compare(const void* first, const void* second)
{
	if (*(int*)first < *(int*)second)
		return 1;
	else if (*(int*)first > *(int*)second)
		return -1;
	else
		return 0;
}

typedef struct
{
	int x;
	int y;
} Time;

int static compare(const void* first, const void* second)
{
	Time A = *(Time*)first;
	Time B = *(Time*)second;

	if (A.y > B.y)
		return 1;
	else if (A.y == B.y)
	{
		if (A.x > B.x)
			return 1;
		else
			return -1;
	}
	else
		return -1;
}

Time time_array[100000];
int M;


int main(void)
{
	char number[100000];
	int len;
	int hap = 0;
	scanf("%s", &number);

	len = strlen(number);

	qsort(number, len, sizeof(number[0]), char_compare);


	if (number[0] != '0')
	{
		printf("%d", -1);
		return 0;
	}

	for (int i = 0; i < len; i++)
	{
		hap += (int)number[i] - 48;
	}

	if (hap % 3 != 0)
	{
		printf("%d", -1);
		return 0;
	}

	for (int i = 0; i < len; i++)
	{
		printf("%c", number[len - i - 1]);
	}
	int one_count = 0, minus_zero_count = 0, plus_count = 0;
	int minus_zero_array[50];
	int plus_array[50];
	int result = 0;
	int cnt;

	int N;
	int array[50];

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &array[i]);
	}

	qsort(array, N, sizeof(int), compare);

	for (int i = 0; i < N; i++)
	{
		if (array[i] <= 0)
		{
			minus_zero_array[minus_zero_count] = array[i];
			minus_zero_count++;
		}
		else if (array[i] == 1)
		{
			one_count++;
		}
		else
		{
			plus_array[plus_count] = array[i];
			plus_count++;
		}
	}

	cnt = 0;

	while (cnt <= minus_zero_count - 2)
	{
		result += (minus_zero_array[cnt] * minus_zero_array[cnt + 1]);
		cnt += 2;
	}

	if (cnt < minus_zero_count)
	{
		result += minus_zero_array[cnt];
	}

	result += one_count;


	qsort(plus_array, plus_count, sizeof(int), reverse_compare);

	cnt = 0;

	while (cnt <= plus_count - 2)
	{
		result += (plus_array[cnt] * plus_array[cnt + 1]);
		cnt += 2;
	}

	if (cnt < plus_count)
	{
		result += plus_array[cnt];
	}

	printf("%d", result);


	int now_time = 0;
	int last_time = 0;
	int temp;
	int result_cnt = 0;
	
	scanf("%d", &M);

	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &time_array[i].x, &time_array[i].y);
	}

	qsort(time_array, M, sizeof(Time), compare);


	
	for (int i = 0; i < M; i++)
	{
		printf("%d %d\n", time_array[i].x, time_array[i].y);
	}

	

	for (int i = 0; i < M; i++)
	{
		if (now_time <= time_array[i].x)
		{
			now_time = time_array[i].y;


			result_cnt++;
		}

	}

	printf("%d", result_cnt);
}
