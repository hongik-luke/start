#include <stdio.h>
#include <stdlib.h>

#define TRUE	1
#define FALSE	0

#define QUE_LEN	200001

typedef struct _pos
{
    int x;
    int y;
}Pos;

typedef struct tomato
{
    int ripe;
    int whenripe;
}Tomato;

typedef Pos Data;

typedef struct _cQueue
{
	int front;
	int rear;
	Data queArr[QUE_LEN];
}Queue;

void QueueInit(Queue * pq);
int QIsEmpty(Queue * pq);
void Enqueue(Queue * pq, Data data);
Data Dequeue(Queue * pq);
Data QPeek(Queue * pq);



int main(void)
{
    Pos a;
    Pos pos;
    int max = 0;
    scanf("%d %d",&a.x,&a.y);
    Tomato * arr =(Tomato*) malloc(sizeof(Tomato)*a.y *a.x);
    
    for(int i = 0 ; i < a.y*a.x; i++)
    {
        scanf("%d",&arr[i].ripe);
        arr[i].whenripe = 0;
    }
    
    
    Pos idx;
    Queue q;
    QueueInit(&q);
    for(int i = 0 ; i < a.y*a.x ; i++)
    {
        if(arr[i].ripe == 1)
        {
            pos.x = i/a.x;
            pos.y = i%a.x;
            Enqueue(&q,pos);
        }
    }
    
    while(!QIsEmpty(&q))
    {
        idx = Dequeue(&q);

        Pos upidx = idx;
        upidx.x -= 1;
        if(idx.x != 0 && arr[upidx.x*a.x + upidx.y].ripe == 0)
        {
            
            Enqueue(&q, upidx);
            arr[upidx.x*a.x + upidx.y].ripe = 1;
            arr[upidx.x*a.x + upidx.y].whenripe = arr[idx.x*a.x + idx.y].whenripe + 1;
        }
    
        Pos downidx = idx;
        downidx.x += 1;
        if(idx.x + 1 != a.y && arr[downidx.x*a.x + downidx.y].ripe == 0)
        {
            
            Enqueue(&q, downidx);
            arr[downidx.x*a.x + downidx.y].ripe = 1;
            arr[downidx.x*a.x + downidx.y].whenripe = arr[idx.x*a.x + idx.y].whenripe + 1;
        }
    
        Pos leftidx = idx;
        leftidx.y -= 1;
        if(idx.y != 0 && arr[leftidx.x*a.x + leftidx.y].ripe == 0)
        {
            Enqueue(&q, leftidx);
            arr[leftidx.x*a.x + leftidx.y].ripe = 1;
            arr[leftidx.x*a.x + leftidx.y].whenripe = arr[idx.x*a.x+ idx.y].whenripe + 1;
        }
    
        Pos rightidx = idx;
        rightidx.y += 1;
        if(idx.y + 1 != a.x && arr[rightidx.x*a.x + rightidx.y].ripe == 0)
        {
            
            Enqueue(&q, rightidx);

            arr[rightidx.x*a.x + rightidx.y].ripe = 1;
            arr[rightidx.x*a.x + rightidx.y].whenripe = arr[idx.x*a.x + idx.y].whenripe + 1;
        }

    }    
    
    for(int i = 0 ; i < a.y*a.x ; i++)
    {
        if(arr[i].ripe == 1)
        {
            if(arr[i].whenripe > max)
                max = arr[i].whenripe;
            
        }
        else if(arr[i].ripe == 0)
        {
            printf("-1");
            return 1;
        }
    }
    
    printf("%d",max);
    
    return 1;
    
    
    
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
