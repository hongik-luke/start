#include <stdio.h>
#include <stdlib.h>

typedef struct _pos
{
    int day;
    int num;
}pos;

#define TRUE	1
#define FALSE	0

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
	if(d1.day < d2.day)
		return 1;    // d1이 정렬 순서상 앞선다.
	else
		return 0;    // d2가 정렬 순서상 앞서거나 같다.
}




int main(void)
{
	int N,day,num;
	int result = 0;
    List list;
	pos data;
	int max,max_day;
	ListInit(&list);
	SetSortRule(&list, WhoIsPrecede);
    
	scanf("%d",&N);


	for(int i = 0; i < N ; i++)
	{
	    scanf("%d %d",&data.day, &data.num);
	    LInsert(&list, data);
	}
	
	for(int i = N; i > 0 ; i--)
	{
	    max = 0;
        if(LFirst(&list, &data))
	    {
	        if(i <= data.day && max < data.num)
	        {
	            max = data.num;
	            max_day = data.day;
	        }  
	    	while(LNext(&list, &data)) 
		    {
		        if(i <= data.day && max < data.num)
	            {
	                max = data.num;
	                max_day = data.day;
	            }
		    }
    	}
    	
    	if(max != 0)
    	{
    	    if(LFirst(&list, &data))
	        {
	            if(max_day == data.day && max == data.num)
	            {
	                data = LRemove(&list);
	                result +=data.num;
	            }  
	            else
	            {
	                while(LNext(&list, &data)) 
		            {
		                if(max_day == data.day && max == data.num)
	                    {
	                        data = LRemove(&list);
	                        result +=data.num;
	                        break;
	                    }
		                
		            }
	            }
	    	    
    	    }
    	    
    	}
    	
	}
	
	printf("%d",result);
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
    
