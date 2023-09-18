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

}
