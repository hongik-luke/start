#include <stdio.h>
#include <stdlib.h>

int compare(const void *a , const void *b);

int main(void)
{
 
	int num;
	int N, K;
	int result = 0;
	int idx = 0;
	int hap = 0;

	scanf("%d",&N);
	scanf("%d",&K);
	int* arr = (int*)malloc(sizeof(int) * N);
	int* lenarr = (int*)malloc(sizeof(int) * N-1);
	
	for(int i = 0; i < N ; i++)
	{
	    scanf("%d",&num);
	    arr[i] = num;
	}
    
    qsort(arr,N,sizeof(int),compare);
    
    for(int i = 0; i < N - 1 ; i++)
    {
        if(arr[i] - arr[i+1] > 0)
        {
            lenarr[idx++] = arr[i] - arr[i+1];
        }
    }
    
    qsort(lenarr,idx,sizeof(int),compare);
    
    for(int i = K-1 ; i < idx ; i++)
    {
        hap += lenarr[i];
    }
    
    printf("%d",hap);
    free(arr);
    free(lenarr);
    
}

int compare(const void *a , const void *b) 
{
    int num1 = *(int*)a;
    int num2 = *(int*)b;
    
    
    if(num1 < num2)
        return 1;
    else
        return -1;
} 