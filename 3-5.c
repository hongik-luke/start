#include <stdio.h>
#include <stdlib.h>

int compare(const void *a , const void *b);

int main(void)
{
    int N,M,num;
    int max;
    scanf("%d",&M);
    
    for(int i = 0 ; i < M ; i++)
    {
        scanf("%d",&N);
        int* arr = (int*)malloc(sizeof(int) * N);
        
        for(int j = 0 ; j < N ; j++)
        {
            scanf("%d",&arr[j]);    
        }
        
        qsort(arr,N,sizeof(int),compare);
        
        max = 0;
        
        for(int j = 0 ; j < N - 2 ; j++)
        {
            if(max < arr[j] - arr[j+1])
            {
                max = arr[j] - arr[j+1];
            } 
            if(max < arr[j] - arr[j+2])
            {
                max = arr[j] - arr[j+2];
            }
        }
        printf("%d\n",max);
    }
    

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
