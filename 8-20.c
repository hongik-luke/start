/*
백준 속 그리디 알고르즘 문제 풂

3문제 약 30~40분
*/


#include <stdio.h>
#include <stdlib.h>


int compare(const void *a , const void *b); 

int main(void)
{
      // 11399 ATM
    printf("11399문제\n");
    int N ;
    int array[1000];
    int result = 0;
    int count = 0;
    
    scanf("%d",&N);
    
    for(int i = 0 ; i < N ; i ++)
        scanf("%d",&array[i]);
    
    qsort(array , N , sizeof(array[0]) , compare); 
    
    for(int i = 0 ; i < N ; i ++)
    {
        count += array[i];
        
        result += count;
    }
    
    printf("%d \n\n",result);
    
    
      // 11047문제 동전 0
    printf("11047문제\n");
    int K;
    int coin_value[10];
    int coin_count = 0;
    
    scanf("%d %d",&N,&K);
    
     for(int i = 0 ; i < N ; i ++)
        scanf("%d",&coin_value[i]);
    
    while(K)
    {
        N--;
        
        if(K < coin_value[N])
            continue;
            
        coin_count += K / coin_value[N];
        K = K % coin_value[N];
    }
    
    printf("%d \n\n",coin_count);
      // 1026문제 보물
    printf("1026문제\n");
    int a_array[50];
    int b_array[50];
    int s;
    int solve_result = 0;
    
    scanf("%d",&s);
    
    for(int i = 0 ; i < s ; i ++)
        scanf("%d",&a_array[i]);
        
    for(int i = 0 ; i < s ; i ++)
        scanf("%d",&b_array[i]);
    
    qsort(a_array , s , sizeof(a_array[0]) , compare);
    qsort(b_array , s , sizeof(b_array[0]) , compare);
    
    for(int i = 0 ; i < s ; i ++)
    {
        solve_result += a_array[i] * b_array[s - 1 - i] ;
    }
    
    printf("%d\n\n",solve_result);
    
}







