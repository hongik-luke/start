#include <stdio.h>
#include <stdlib.h>

typedef struct _pos
{
    int min;
    int max;
}pos;

int compare(const void *a , const void *b);

int main(void)
{
 
	int min,max;
	int N;
	int result = 0;


	scanf("%d",&N);

    pos* arr = (pos*)malloc(sizeof(pos) * N);

	
	for(int i = 0; i < N ; i++)
	{
	    scanf("%d %d",&min,&max);
	    arr[i].min = min;
	    arr[i].max = max;
	    
	}
    
    qsort(arr,N,sizeof(pos),compare);
    
    min = arr[0].min;
    max = arr[0].max;
    for(int i = 1; i < N ; i++)
    {
        if(max >= arr[i].min)
        {
            if(max <arr[i].max)
                max = arr[i].max;
        }
        else
        {
            result += max - min;
            min = arr[i].min;
            max = arr[i].max;
        }
    }
    result += max - min;
    
    printf("%d",result);
    
}

int compare(const void *a , const void *b) 
{
    pos num1 = *(pos*)a;
    pos num2 = *(pos*)b;
    
    
    if(num1.min > num2.min)
        return 1;
    else if(num1.min < num2.min)
        return -1;
    else
    {
        if(num1.max > num2.max)
            return 1;
        else
            return -1;
    }

    
} 