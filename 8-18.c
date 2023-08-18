/*
책 - "이것이 코딩 테스트다" 속 그리디 알고리즘 손코딩 옮김

6문제 풀이 + qsort 써보기 !!
*/
#include <stdio.h>
#include <stdlib.h>


int compare(const void *a , const void *b); 



int main(void)
{
    // 87p 동전갯수문제
    
    int money;
    int count = 0;
    int total_count = 0;
    
    
    printf("동전 갯수문제 \n");
    
    scanf("%d",&money);
    
    int coin_type[4] = {500,100,50,10}; 
    
    for(int i = 0 ; i < 4 ; i++)
    {
        count = money / coin_type[i];
        money = money % coin_type[i];
        total_count += count;
        
    }
    
    printf("동전갯수 : %d\n\n",total_count);
  
    // 311p 모험가 길드
    
    int people_num;
    int array[100000];

    count = 0 , total_count = 0;
    
    printf("모험가길드 문제 \n");
    
    printf("사람 수 입력 \n");
    scanf("%d",&people_num);
    
    for(int i = 0 ; i < people_num ; i++)
        scanf("%d" , &array[i]);
        
    qsort(array , people_num , sizeof(array[0]) , compare); 
 
    for(int i = 0 ; i < people_num ; i++)
    {
        count++;
        if(count >= array[i])
        {
            total_count++;
            count = 0;
        }
    }
    
    printf("출전 길드 : %d \n\n",total_count);
    
    
    
    // 312p 곱하기 혹은 더하기
    
    printf("곱하기 혹은 더하기 문제 \n");
    
    printf("문자열입력 \n");
    
    char string[20];
    int result = 0;
    int i = 0;
    int num;
    
    scanf("%s",string);

    while(string[i] != NULL)
    {   
        num = (int)string[i] - 48;
        
        if(num >= 2)
        {
            if(result == 0)
                result = num;    

            else
                result *= num;    
        }
        
        else
            result += num;    
        i++;
    }
    
    printf("답 = %d\n\n",result);
    
    // 313p 문자열 뒤집기
    
    printf("문자열 뒤집기 문제 \n");
    
    printf("문자열입력 \n");
    
    char string1[1000000];
    int count1 = 0;
    int result1 = 0;
    int len = 0;
    scanf("%s",string1);
    
    while(string1[len] != NULL)
    {
        len++;
    }
    
    
    for(int i = 1; i < len ; i++)
    {
        if(string1[i] != string1[i - 1])
            count1++;
    }
    
    result1 = (count1+1) / 2 ;
    
    printf("%d\n\n",result1);
    
     // 92p 큰 수의 법칙
    
    printf("큰 수의 법칙 문제 \n");
    
    printf("N M K 와 N개의 숫자 입력 \n");
    
    int N,M,K;
    int count2 = 0;
    int result2 = 0;
    int array1[1000];
    
    scanf("%d %d %d",&N,&M,&K);
    
    for(int i = 0 ; i < N ; i++)
    {
        scanf("%d",&array1[i]);
    }
    
     qsort(array1 , N , sizeof(array1[0]) , compare); 
    
    while(M)
    {
        if(count == K)
        {
            result2 += array1[N-2];
            count = 0 ; 
        }
        else
        {
            result2 += array1[N-1];
            count++ ; 
        }
        
        M--;
    }
    
    printf("정답 = %d\n\n",result2);
    
    
     // 96p 숫자 카드 게임
    
    printf("숫자 카드 게임 문제 \n");
    
    printf("N M 과 N*M행렬 입력 \n");
    
    int N1,M1;
    int min = 0 ;
    int result3 = 0;
    int array3[100][100];
    
    scanf("%d %d",&N1,&M1);
    
    
    for(int i = 0 ; i < N1 ; i++)
    {
        for(int j = 0 ; j < M1 ; j++)
        {
            scanf("%d", &array3[i][j]);
      
        }
    }
    
    for(int i = 0 ; i < N1 ; i++)
    {
        min = array3[i][0];
        
        for(int j = 0 ; j < M1 ; j++)
        {
            if(min > array3[i][j])
                min = array3[i][j];
        }
        
        if(result3 < min)
            result3 = min;
    }
    
    printf("답 = %d\n\n", result3);
    
    
    return 0;
}



int compare(const void *a , const void *b) 
{ 
     if( *(int*)a > *(int*)b )

        return 1;

    else if( *(int*)a < *(int*)b )

        return -1;

    else

        return 0;
} 


