#include <stdio.h>
#include <stdlib.h>

#define TRUE	1
#define FALSE	0

#define QUE_LEN	100001

typedef struct _pos
{
    int x;
    int y;
}Pos;

typedef Pos Data;
typedef struct _cQueue
{
	int front;
	int rear;
	Data queArr[QUE_LEN];
}Queue;

// 큐 관련 인자들
void QueueInit(Queue * pq);
int QIsEmpty(Queue * pq);
void Enqueue(Queue * pq, Data data);
Data Dequeue(Queue * pq);
Data QPeek(Queue * pq);




int arr[101][101] = {0,};
int check[101][101] = {0,};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};



void bfs(int mexx, int mexy)
{

    Queue q;
    QueueInit(&q);
    Pos first = {0,0};
    Enqueue(&q,first);
    check[0][0] = 1;
    
    
    Pos nowidx;
    Pos searchidx;
    while(!QIsEmpty(&q))
    {
        nowidx = Dequeue(&q);
        for(int i = 0 ; i < 4 ; i++)
        {
            searchidx.x = nowidx.x + dx[i];
            searchidx.y = nowidx.y + dy[i];
            
            if(searchidx.x >= 0 && searchidx.x < mexx && searchidx.y >= 0 && searchidx.y < mexy)
            {
                if(check[searchidx.x][searchidx.y] == 0)
                {
                    if(arr[searchidx.x][searchidx.y] == 0)
                    {
                        check[searchidx.x][searchidx.y] = 1;
                        Enqueue(&q,searchidx);
                    }
                    else
                        check[searchidx.x][searchidx.y] = 2;
                }    
            }
        }
    }

}

int main(void)
{
    
    Pos Mex;
    Pos a;

    int result = 0;
    
    scanf("%d %d",&Mex.y,&Mex.x);
    
    for(int i = 0 ; i < Mex.x ; i++)
    {
        for(int j = 0 ; j < Mex.y ; j++)
        {
            scanf("%1d",&arr[i][j]);
        }
    }
    
    while(1)
    {
        bfs(Mex.x,Mex.y);
        

        if(check[Mex.x -1][Mex.y -1] == 1)
            break;
        
        for(int i = 0 ; i < Mex.x ; i++)
        {
            for(int j = 0 ; j < Mex.y ; j++)
            {
                if(check[i][j] != 0)
                {
                    if(check[i][j] == 2)
                        arr[i][j] = 0;
                    check[i][j] = 0;
                }
                
            }
        }
        
        result++;
        
        
    }
    printf("%d",result);

    
}

void QueueInit(Queue * pq)
{
	pq->front = 0;
	pq->rear = 0;
}
int QIsEmpty(Queue * pq)
{
	if(pq->front == pq->rear)
		return TRUE;
	else
		return FALSE;
}
int NextPosIdx(int pos)
{
	if(pos == QUE_LEN-1)
		return 0;
	else
		return pos+1;
}
void Enqueue(Queue * pq, Data data)
{
	if(NextPosIdx(pq->rear) == pq->front)
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	pq->rear = NextPosIdx(pq->rear);
	pq->queArr[pq->rear] = data;
}
Data Dequeue(Queue * pq)
{
	if(QIsEmpty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	pq->front = NextPosIdx(pq->front);
	return pq->queArr[pq->front];
}
Data QPeek(Queue * pq)
{
	if(QIsEmpty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	return pq->queArr[NextPosIdx(pq->front)];
}
