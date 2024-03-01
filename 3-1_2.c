#include<stdio.h>
#include<stdlib.h>

#define TRUE	1
#define FALSE	0

typedef struct _pos
{
    int x;
    int y;
}pos;

// 연결 리스트 관련
typedef pos LData;

typedef struct _node
{
	LData data;
	struct _node * next;
} Node;

typedef struct _linkedList
{
	Node * head;
	Node * cur;
	Node * before;
	int numOfData;
	int (*comp)(LData d1, LData d2);
} LinkedList;


typedef LinkedList List;

void ListInit(List * plist);
void LInsert(List * plist, LData data);

int LFirst(List * plist, LData * pdata);
int LNext(List * plist, LData * pdata);

LData LRemove(List * plist);
int LCount(List * plist);

void SetSortRule(List * plist, int (*comp)(LData d1, LData d2));



int WhoIsPrecede(pos d1, pos d2)
{
	if(d1.y > d2.y)
	    return 1;
	else
	{
	    if(d1.x > d2.x)
	        return 1;	    
	    else
	        return 0;
	}

}

int main(void)
{
    List list;
	ListInit(&list);
	SetSortRule(&list, WhoIsPrecede);
    int timer = 0;
    
    int N;	
    scanf("%d",&N);
    
    LData data;
    int xpos,ypos;
    
    for(int i = 0 ; i< N ; i++)
    {
        scanf("%d %d",&xpos,&ypos);
        data.x = xpos;
        data.y = ypos;
        LInsert(&list,data);
    }    
    
    
    for(int i = 0 ; i< N ; i++)
    {
        if(timer == 0)
            LFirst(&list,&data);
        else
            LNext(&list,&data);
        
        if(data.x < timer)
        {
            LRemove(&list);
        }
        else
        {
            timer = data.y;    
        }
    }
    
    printf("%d",LCount(&list));
    
    
    
    
    
    
    

}

void ListInit(List * plist)
{
	plist->head = (Node*)malloc(sizeof(Node));
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->numOfData = 0;
}

void FInsert(List * plist, LData data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = plist->head->next;
	plist->head->next = newNode;

	(plist->numOfData)++;
}

void SInsert(List * plist, LData data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	Node * pred = plist->head;
	newNode->data = data;

	while(pred->next != NULL &&
		plist->comp(data, pred->next->data) != 0)
	{
		pred = pred->next;
	}

	newNode->next = pred->next;
	pred->next = newNode;

	(plist->numOfData)++;
}


void LInsert(List * plist, LData data)
{
	if(plist->comp == NULL)
		FInsert(plist, data);
	else
		SInsert(plist, data);
}

int LFirst(List * plist, LData * pdata)
{
	if(plist->head->next == NULL)
		return FALSE;

	plist->before = plist->head;
	plist->cur = plist->head->next;

	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List * plist, LData * pdata)
{
	if(plist->cur->next == NULL)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

LData LRemove(List * plist)
{
	Node * rpos = plist->cur;
	LData rdata = rpos->data;

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rpos);
	(plist->numOfData)--;
	return rdata;
}

int LCount(List * plist)
{
	return plist->numOfData;
}

void SetSortRule(List * plist, int (*comp)(LData d1, LData d2))
{
	plist->comp = comp;
}

/* 
int N,M;
	int data;
    
	int second = 0;
    
	int ship,box;
	int boxcount, shipcount;
	
	List shiplist;
	ListInit(&shiplist);
	SetSortRule(&shiplist, WhoIsPrecede);
	List boxlist;
	ListInit(&boxlist);
	SetSortRule(&boxlist, WhoIsPrecede);
	
    scanf("%d",&N);
    
    for(int i = 0 ; i < N; i++)
    {
        scanf("%d",&data);
        LInsert(&shiplist,data);
    }
    
    scanf("%d",&M);
    
    for(int i = 0 ; i < M; i++)
    {
        scanf("%d",&data);
        LInsert(&boxlist,data);
    }
    
    
	
	while(LCount(&shiplist) != 0 && LCount(&boxlist) != 0)
	{
        shipcount = 0;
        
        
        for(int i = 0 ; i < LCount(&shiplist); i++)
        {
            if(shipcount == 0)
            {
                LFirst(&shiplist,&ship);
                shipcount = 1;
            }
            else
            {
                LNext(&shiplist,&ship);
            }
            
            
            boxcount = 0;
            for(int j = 0 ; j < LCount(&boxlist); j++)
            {
                if(boxcount == 0)
                {
                    LFirst(&boxlist,&box);
                    boxcount = 1;
                }
                else
                {
                    LNext(&boxlist,&box);
                }
            
            
                if(ship >= box)
                {
                    LRemove(&boxlist);
                    break;
                }
            
                if(j == LCount(&boxlist)-1)
                {
                    LRemove(&shiplist);    
                }
            }
        }
        
        second++;
        

	}
	
	if(LCount(&shiplist) == 0)
	{
	    printf("-1");
	    return 0;
	}
	
	if(LCount(&boxlist) == 0)
	{
	    printf("%d",second);
	    return 0;
	}
	
	*/