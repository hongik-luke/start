#include <stdio.h>
#include <stdlib.h>

int compare(const void *a , const void *b);

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

// 스택 명령어
void StackInit(Stack * pstack);
int SIsEmpty(Stack * pstack);
void SPush(Stack * pstack, Data data);
Data SPop(Stack * pstack);
Data SPeek(Stack * pstack);



int main(void)
{
    Stack plus_stack,minus_stack;
	StackInit(&plus_stack);
	StackInit(&minus_stack);
	
	int num;
	int N;
	int min,max,min_result;
	
	scanf("%d",&N);
	int* arr = (int*)malloc(sizeof(int) * N);
	
	for(int i = 0; i < N ; i++)
	{
	    scanf("%d",&num);
	    arr[i] = num;
	}
    
    qsort(arr,N,sizeof(int),compare);
    
    if(arr[0] > 0)
        SPush(&plus_stack,arr[0]);
    else if(arr[0] < 0)
        SPush(&minus_stack,arr[0]);    
    else
    {
        SPush(&plus_stack,arr[0]);  
        SPush(&minus_stack,arr[0]); 
    }
    
    if(arr[1] > 0)
        SPush(&plus_stack,arr[1]);
    else if(arr[1] < 0)
        SPush(&minus_stack,arr[1]);    
    else
    {
        SPush(&plus_stack,arr[1]);  
        SPush(&minus_stack,arr[1]); 
    }
    
    if(arr[0] < arr[1])
    {
        min = arr[0];
        max = arr[1];
    }
    else
    {
        min = arr[1];
        max = arr[0];
    }
    min_result = abs(arr[0]+arr[1]); 
      
    for(int i = 2; i < N ; i++)
    {
        if(arr[i] > 0)
            SPush(&plus_stack,arr[i]);    
        else
            SPush(&minus_stack,arr[i]);    
        
        if(SIsEmpty(&plus_stack) != 1 && SIsEmpty(&minus_stack) != 1)
        {
            if(min_result > abs(SPeek(&plus_stack) + SPeek(&minus_stack)))
            {
                min = SPeek(&minus_stack);
                max = SPeek(&plus_stack);
                min_result = abs(SPeek(&plus_stack) + SPeek(&minus_stack));
            }
        }
    }

    printf("%d %d",min, max);
    
}

int compare(const void *a , const void *b) 
{
    int num1 = abs(*(int*)a);
    int num2 = abs(*(int*)b);
    
    
    if(num1 > num2)
        return 1;
    else
        return -1;

    
} 

void StackInit(Stack * pstack)
{
	pstack->head = NULL;
}

int SIsEmpty(Stack * pstack)
{
	if(pstack->head == NULL)
		return 1;
	else
		return 0;
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