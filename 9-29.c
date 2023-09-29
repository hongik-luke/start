  /*
2의 100승이 넘는 큰 수를 구현해야해서 실패함;;;;
1914
*/
#include <stdio.h>
#include <stdlib.h>

long long hanoi_num(long long num);
void hanoi(int num, int f,int b,int t);

int main(void)
{
    long long N;
    
    scanf("%lld",&N);
    
    printf("%lld\n",hanoi_num(N));
    
    if(N <= 20)
    {
       hanoi(N,1,2,3);
    }
}

long long hanoi_num(long long num)
{
    if(num == 1)
        return 1;
        
    else
    {
        return hanoi_num(num -1)*2 +1;
    }    
    
}

void hanoi(int num, int f,int b,int t)
{
    if(num == 1)
    {
        printf("%d %d\n",f,t);
    }
    
    else
    {
        
    hanoi(num-1,f,t,b);
    
    printf("%d %d\n",f,t);
    
    hanoi(num-1,b,f,t);

    }
}




















