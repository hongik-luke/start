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
int arr[101][101][2] = {0,};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};



int bfs(int Max_x, int Max_y)
{
    Queue q;
    QueueInit(&q);
    Pos first = {0,0};
    Enqueue(&q,first);
    int returnnum;
    Pos nowidx;
    Pos searchidx;
    arr[0][0][0] = 0;
    while(!QIsEmpty(&q))
    {
        nowidx = Dequeue(&q);
        for(int i = 0 ; i < 4 ; i++)
        {
            searchidx.x = nowidx.x + dx[i];
            searchidx.y = nowidx.y + dy[i];
            
            if(searchidx.x >= 0 && searchidx.x < Max_x && searchidx.y >= 0 && searchidx.y < Max_y)
            {
                if(arr[searchidx.x][searchidx.y][0] == 1)
                {
                    arr[searchidx.x][searchidx.y][0] = 0;
                    Enqueue(&q,searchidx);
                    arr[searchidx.x][searchidx.y][1] = arr[nowidx.x][nowidx.y][1] +1;
                }
            }
        }
    }
    
    returnnum = arr[Max_x - 1][Max_y - 1][1];
    return returnnum;
}

int main(void)
{
    
    Pos a;
    int result;
    scanf("%d %d",&a.x,&a.y);
    for(int i = 0 ; i < a.x ; i++)
    {
        for(int j = 0 ; j < a.y ; j++)
        {
            scanf("%1d",&arr[i][j][0]);
        }
        
    }

    result = bfs(a.x,a.y);
    
    for(int i = 0 ; i < a.x ; i++)
    {
        for(int j = 0 ; j < a.y ; j++)
        {
            printf("%d ",arr[i][j][0]);

        }
        printf("\n");
    }
    printf("%d",result+1);
    
    return 0;
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
