#include <stdio.h>
#include <stdlib.h>

#define TRUE	1
#define FALSE	0

#define HEAP_LEN	200010

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



typedef Pos LData;

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
}List;

void ListInit(List * plist);
void LInsert(List * plist, LData data);
int LFirst(List * plist, LData * pdata);
int LNext(List * plist, LData * pdata);
LData LRemove(List * plist);
int LCount(List * plist);


Pos  upidx(Pos idx, Pos a)
{
    Pos nidx = idx;
    nidx.x = nidx.x - 1;
    if(nidx.x == -1)
        return idx;
        
    return nidx;
}

Pos downidx(Pos idx, Pos a)
{
    Pos nidx = idx;
    nidx.x = nidx.x + 1;
    if(nidx.x == a.y)
        return idx;
        
    return nidx;
}

Pos leftidx(Pos idx, Pos a)
{
    Pos nidx = idx;
    nidx.y = nidx.y - 1;
    if(nidx.y == -1)
        return idx;
        
    return nidx;
}

Pos rightidx(Pos idx, Pos a)
{
    Pos nidx = idx;
    nidx.y = nidx.y + 1;
    if(nidx.y == a.x)
        return idx;
        
    return nidx;
}


int main(void)
{
    Pos a;

    scanf("%d %d",&a.x,&a.y);
    
    Tomato ** arr =(Tomato*) malloc(sizeof(Tomato)*a.y);
    
    for(int i = 0; i<a.x; i++)
    {
        arr[i] = (Tomato*) malloc ( sizeof(Tomato) * a.x );
    }
    
    for(int i = 0 ; i < a.y ; i++)
    {
        for(int j = 0 ; j < a.x; j++)
        {
            scanf("%d",&arr[i][j].ripe);
            arr[i][j].whenripe = 0;
        }
    }
    
    
    int num = 0;
    Pos pos;
    List list;
    ListInit(&list);
    Pos anotherpos ;
    
    for(int i = 0 ; i < a.y ; i++)
    {
        for(int j = 0 ; j < a.x; j++)
        {
            if(arr[i][j].ripe == 1)
            {
                pos.x = i;
                pos.y = j;
                LInsert(&list,pos);
            }
        }
    }
    
    printf("check - %d \n",LCount(&list));
    

    
    while(LCount(&list)!= 0)
    {
        if(LFirst(&list,&pos))
        {
            printf("!!!!%d %d\n",pos.x ,pos.y);
        
            anotherpos = upidx(pos, a);
            printf("!!!!%d %d\n",anotherpos.x ,anotherpos.y);
            if(arr[anotherpos.x][anotherpos.y].ripe == 0)
            {
            LInsert(&list,anotherpos);
            arr[anotherpos.x][anotherpos.y].ripe = 1;
            arr[anotherpos.x][anotherpos.y].whenripe = arr[pos.x][pos.y].whenripe + 1;
            }
    
    

            anotherpos = downidx(pos, a);
            if(arr[anotherpos.x][anotherpos.y].ripe == 0)
            {
                LInsert(&list,anotherpos);
                arr[anotherpos.x][anotherpos.y].ripe = 1;
                arr[anotherpos.x][anotherpos.y].whenripe = arr[pos.x][pos.y].whenripe + 1;
            }

            anotherpos = leftidx(pos, a);
            if(arr[anotherpos.x][anotherpos.y].ripe == 0)
            {
                LInsert(&list,anotherpos);
                arr[anotherpos.x][anotherpos.y].ripe = 1;
                arr[anotherpos.x][anotherpos.y].whenripe = arr[pos.x][pos.y].whenripe + 1;
            }
        

            anotherpos = rightidx(pos, a);
            if(arr[anotherpos.x][anotherpos.y].ripe == 0)
            {
                LInsert(&list,anotherpos);
                arr[anotherpos.x][anotherpos.y].ripe = 1;
                arr[anotherpos.x][anotherpos.y].whenripe = arr[pos.x][pos.y].whenripe + 1;
            }
            LRemove(&list);
        }
       
    } 
       
     printf("check - %d \n",LCount(&list));
        
        
        printf("%d\n",LNext(&list,&pos));
        while(LNext(&list,&pos))
        {


            anotherpos = upidx(pos, a);
            if(arr[anotherpos.x][anotherpos.y].ripe == 0)
            {
                LInsert(&list,anotherpos);
                arr[anotherpos.x][anotherpos.y].ripe = 1;
                arr[anotherpos.x][anotherpos.y].whenripe = arr[pos.x][pos.y].whenripe + 1;
            }
    
            anotherpos = downidx(pos, a);
            if(arr[anotherpos.x][anotherpos.y].ripe == 0)
            {
                LInsert(&list,anotherpos);
                arr[anotherpos.x][anotherpos.y].ripe = 1;
                arr[anotherpos.x][anotherpos.y].whenripe = arr[pos.x][pos.y].whenripe + 1;
            }
        

            anotherpos = leftidx(pos, a);
            if(arr[anotherpos.x][anotherpos.y].ripe == 0)
            {
                LInsert(&list,anotherpos);
                arr[anotherpos.x][anotherpos.y].ripe = 1;
                arr[anotherpos.x][anotherpos.y].whenripe = arr[pos.x][pos.y].whenripe + 1;
            }
        

            anotherpos = rightidx(pos, a);
            if(arr[anotherpos.x][anotherpos.y].ripe == 0)
            {
                LInsert(&list,anotherpos);
                arr[anotherpos.x][anotherpos.y].ripe = 1;
                arr[anotherpos.x][anotherpos.y].whenripe = arr[pos.x][pos.y].whenripe + 1;
            }
            LRemove(&list);
            
            printf("check - %d \n",LCount(&list));
        }
        
    }
    


    

    
    
    
    
    for(int i = 0 ; i < a.y ; i++)
    {
        for(int j = 0 ; j < a.x ; j++)
        {
            printf("%d %d   ",arr[i][j].ripe,arr[i][j].whenripe);
        }
        printf("\n");
    }
    
    
    
    
    
    
    
    
    
    
    
}


void ListInit(List * plist)
{
	plist->head = (Node*)malloc(sizeof(Node));
	plist->head->next = NULL;
	plist->numOfData = 0;
}

void LInsert(List * plist, LData data)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = plist->head->next;
	plist->head->next = newNode;

	(plist->numOfData)++;

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
		return 0;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return 1;
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






