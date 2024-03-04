#include <stdio.h>
#include <stdlib.h>

#define TRUE	1
#define FALSE	0

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node * next;
} Node;

typedef struct _listStack
{
	Node * head;
} ListStack;


typedef ListStack Stack;

void StackInit(Stack * pstack);
int SIsEmpty(Stack * pstack);
void SPush(Stack * pstack, Data data);
Data SPop(Stack * pstack);
Data SPeek(Stack * pstack);

int main(void)
{
    int arr[1000001];
    int NGEarr[1000001];
    int N,num;
    Stack stack;
	StackInit(&stack);
	
	scanf("%d",&N);
	
	for(int i = 0; i<N ;i++)
	    scanf("%d",&arr[i]);
	
	num = arr[N-1];
	SPush(&stack,num);
	NGEarr[N-1] = -1;
	for(int i = N-2 ; i >= 0 ;i--)
	{
	    while(1)
	    {
	        if(SIsEmpty(&stack))
	        {
	            NGEarr[i] = -1;
	            SPush(&stack,arr[i]);
	            break;
	        }
	        else if(arr[i] < SPeek(&stack))
	        {
	            NGEarr[i] = SPeek(&stack);
	            SPush(&stack,arr[i]);
	            break;
	        }
	        SPop(&stack);
	    }
	}
	
	for(int i = 0; i<N ;i++)
	    printf("%d ",NGEarr[i]);

}


void StackInit(Stack * pstack)
{
	pstack->head = NULL;
}

int SIsEmpty(Stack * pstack)
{
	if(pstack->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack * pstack, Data data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;
	newNode->next = pstack->head;

	pstack->head = newNode;
}

Data SPop(Stack * pstack)
{
	Data rdata;
	Node * rnode;

	if(SIsEmpty(pstack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}

	rdata = pstack->head->data;
	rnode = pstack->head;

	pstack->head = pstack->head->next;
	free(rnode);

	return rdata;
}

Data SPeek(Stack * pstack)
{
	if(SIsEmpty(pstack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}

	return pstack->head->data;
}















