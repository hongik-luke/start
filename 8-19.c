/*
책 - "이것이 코딩 테스트다" 속 그리디 알고리즘

총 4문제 풂 1시간 40분쯤 소요
*/
#include <stdio.h>
#include <stdlib.h>


int compare(const void *a , const void *b); 

int main(void)
{
      // 99p 1이 될 때까지
    
    printf("1이 될 때까지 문제 \n");
    
    int N;
    int K;
    int count = 0;
    
    printf("N K 입력\n");
    
    scanf("%d %d",&N,&K);
    
    while(N != 1)
    {
        if(N % K == 0)
            N = N / K;
        
        else
            N--;
            
        count++;
    }
    
    printf("%d\n\n" , count);


     // 314p 만들 수 없는 금액
    
    printf("만들 수 없는 금액 문제\n");
    
    printf("N값과 N개의 숫자 \n");
    
    int num = 1;
    int result;
    int array[1000];
    
    scanf("%d",&N);
    
    for(int i = 0 ; i < N ; i++)
        scanf("%d",&array[i]);
    
    qsort(array , N , sizeof(array[0]) , compare); 

    
    for(int i = 0 ; i < N ; i++)
    {
        if(num < array[i])
            break;
        
        
        num +=array[i];
        
    }


    printf("만들 수 없는 수 = %d\n\n",num);




     // 314p 만들 수 없는 금액
    
    printf("볼링공 고르기 \n");
    
    printf("N M값과 N개의 M이하의 수 입력 \n");
    
    int M;
    int ball_weight[1000];
    int player1, player2;
    
    count = 0;
    
    scanf("%d %d",&N,&M);
    
    for(int i = 0 ; i < N ; i++)
        scanf("%d",&ball_weight[i]);
        
    for(int i = 0 ; i < N - 1 ; i++)
    {
        player1 = ball_weight[i];
        
        for(int j = 1 ; i + j < N ; j++)
        {
            player2 = ball_weight[i + j];
            
            if(player1 != player2)
                count++;
        }
        
    }
    
    
    printf("%d \n\n",count);
    
     // 316p 무지의 먹방
    
    printf("무지의 먹방 문제  \n");
    
    printf("배열의 길이, 200000이하 배열, 10(13승)이하 자연수 입력  \n");
    
    int time_array[200000];
    long long nums;
    int food_result;
    int zero_count = 0;
    int min_time;
    
    scanf("%d",&N);
    
    for(int i = 0 ; i < N ; i++)
        scanf("%d",&time_array[i]);
        
    scanf("%lld",&nums);
        
    
    
    min_time = 100000001;
    
    for(int i = 0 ; i < N ; i++)
    {
        if(time_array[i] == 0)
            zero_count++;
        else if (time_array[i] < min_time)
            min_time = time_array[i];
    }
    
    while(nums > min_time * (N - zero_count))
    {
        for(int i = 0 ; i < N ; i++)
        {
            if(time_array[i] != 0)
                time_array[i] -= min_time;
        }
        
        nums -= min_time * (N - zero_count);
        
        zero_count = 0;
        
        min_time = 100000001;
    
        for(int i = 0 ; i < N ; i++)
        {
            if(time_array[i] == 0)
                zero_count++;
            else if (time_array[i] < min_time)
                min_time = time_array[i];
        }
    }    
    

    int i = 0;
    
    while(nums)
    {
        if(time_array[i] != 0)
            nums--;
        
        i++;
        if(i > N - 1)
            i = 0;
    }
    
    while(time_array[i] == 0)
    {
        i++;
        if(i > N - 1)
            i = 0;
    }
    
    printf("%d번째 음식을 먹어야함 \n\n",i+1);
   
    return 0;

}















