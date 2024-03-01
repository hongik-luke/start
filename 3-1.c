//정렬에 관한 백준 문제 풀이
//compare 함수 생각해보기 malloc , colloc 등 공부 시급!!!!
#include<stdio.h>
#include<stdlib.h>

int compare1(const void *a , const void *b);
int compare2(const void *a , const void *b);

typedef struct _xpos
{
    int value;
    int idx;
    int result;
}xpos;

int main3453(void)
{
    
    int num;
    int len;
    int result = 0;
    scanf("%d",&len);
    xpos* posarr = (xpos*)malloc(sizeof(xpos) * len);
    
    for(int i = 0 ; i< len ; i++)
    {
        scanf("%d",&num);
        
        posarr[i].value = num;
        posarr[i].idx = i;
    }
    
    qsort(posarr,len,sizeof(xpos),compare1);
    
    posarr[0].result = result;
    for(int i = 1 ; i< len ; i++)
    {
        if(posarr[i-1].value != posarr[i].value)
            result++;
            
        posarr[i].result = result;
    }
    
    qsort(posarr,len,sizeof(xpos),compare2);
    
    for(int i = 0 ; i< len ; i++)
    {
        printf("%d ",posarr[i].result);
    }
    
    
}





int compare1(const void *a , const void *b) 
{
    xpos pos1 = *(xpos*)a;
    xpos pos2 = *(xpos*)b;
    
     if(pos1.value > pos2.value)

        return 1;

    else if(pos1.value < pos2.value)

        return -1;

    else

        return 0;
} 

int compare2(const void *a , const void *b) 
{
    xpos pos1 = *(xpos*)a;
    xpos pos2 = *(xpos*)b;
    
     if(pos1.idx > pos2.idx)

        return 1;

    else if(pos1.idx < pos2.idx)

        return -1;

    else

        return 0;
}


