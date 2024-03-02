#include <stdio.h>
#include <stdlib.h>

int compare(const void *a , const void *b);
int search(int arr[],int i,int N)
{
    int* temparr = (int*)malloc(sizeof(int) * (N-1));
    int idx1,idx2;
    int check = 0;
    
    for(int j = 0 ; j < i ; j++)
        temparr[j] = arr[j];
    for(int j = i+1 ; j < N ; j++)
        temparr[j-1] = arr[j];
    
    idx1 = 0;
    idx2 = N-2;
    while(idx1 != idx2)
    {
        if(arr[i] == temparr[idx1] + temparr[idx2])
        {
            check = 1;
            break;
        }
        else if(arr[i] > temparr[idx1]+ temparr[idx2])
            idx1++;    
        else
            idx2--;
    }
    
    free(temparr);
    
    if(check != 0)
        return 1;
    else
        return 0;
        
    
    
    
}
int main(void)
{
 
	int num;
	int N;
	int result = 0;

	scanf("%d",&N);
	int* arr = (int*)malloc(sizeof(int) * N);
	
	for(int i = 0; i < N ; i++)
	{
	    scanf("%d",&num);
	    arr[i] = num;
	}
    
    qsort(arr,N,sizeof(int),compare);
    
    for(int i = 0 ; i < N ;i++)
    {
        result += search(arr,i,N);
    }
    
    free(arr);
    
    printf("%d",result);
}

int compare(const void *a , const void *b) 
{
    int num1 = *(int*)a;
    int num2 = *(int*)b;
    
    if(num1 > num2)
        return 1;
    else
        return -1;
} 