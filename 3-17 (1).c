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




int arr[51][51] = {0,};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};



void bfs(int mexx, int mexy, int x, int y)
{

    Queue q;
    QueueInit(&q);
    Pos first = {x,y};
    Enqueue(&q,first);

    arr[x][y] = 0;
    
    Pos nowidx;
    Pos searchidx;
    while(!QIsEmpty(&q))
    {
        nowidx = Dequeue(&q);
        for(int i = 0 ; i < 4 ; i++)
        {
            searchidx.x = nowidx.x + dx[i];
            searchidx.y = nowidx.y + dy[i];
            
            if(searchidx.x >= 0 && searchidx.x <= mexx && searchidx.y >= 0 && searchidx.y <= mexy)
            {
                if(arr[searchidx.x][searchidx.y] == 1)
                {
                    arr[searchidx.x][searchidx.y] = 0;
                    Enqueue(&q,searchidx);
                }       
            }
        }
    }

}

int main(void)
{
    
    Pos Mex;
    Pos a;
    int N,M;
    int result = 0;
    scanf("%d",&N);
    for(int k = 0 ; k < N ; k++)
    {
        scanf("%d %d %d",&Mex.x,&Mex.y,&M);
        
        for(int i = 0 ; i < M ; i++){
            scanf("%d %d",&a.x,&a.y);
            arr[a.x][a.y] = 1;
        }
        
        for(int i = 0 ; i < Mex.x ; i++){
            for(int j = 0 ; j < Mex.y ; j++){
                if(arr[i][j] == 1)
                {
                    printf("%d %d   ",i,j);
                    bfs(Mex.x,Mex.y,i,j);
                    result++;
                }
            }
        }
    
        printf("%d\n",result);
        result = 0;
    }
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
