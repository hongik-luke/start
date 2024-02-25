#include<stdio.h>
#include<stdlib.h>

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node * next;
} Node;

typedef struct _listStack
{
	Node * head;
	int size;
} ListStack;

typedef ListStack Stack;

void StackInit(Stack * pstack)
{
	pstack->head = NULL;
	pstack->size = 0;
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
	
	pstack->size++;
}

Data SPop(Stack * pstack)
{
	Data rdata;
	Node * rnode;

	if(SIsEmpty(pstack)) {
		return -1;
	}

	rdata = pstack->head->data;
	rnode = pstack->head;

	pstack->head = pstack->head->next;
	free(rnode);
    pstack->size--;
    
	return rdata;
}

Data SPeek(Stack * pstack)
{
	if(SIsEmpty(pstack)) {
		return -1;
	}

	return pstack->head->data;
}

int sizeofstack(Stack * pstack)
{
    return pstack->size;
}












int main34634612(void)
{
    int N;
    
    char answer[500002];
    scanf("%d",&N);
    

    Stack stack;
    StackInit(&stack);
    
    
    int target;
    int k = 0;
    int j = 1;
    
    int check = 1;
    int yes_or_no_check = 1;
    
    
    SPush(&stack,j++);
    answer[k++] = '+';
    
    for(int i = 0 ; i < N ; i++)
    {
        scanf("%d",&target);
        
        while(1)
        {
            if(target > SPeek(&stack))
            {
                SPush(&stack,j);
                j++;
                answer[k++] = '+';
            }
            
            else
            {
                check =  SPop(&stack);
                answer[k++] = '-';
                if(check != target)
                {
                    yes_or_no_check = -1;
                }
                break;
            }
        }
        
        
    }
    
    
    if(yes_or_no_check == -1)
    {
        printf("NO");
    }
    else
    {
        for(int i = 0 ; answer[i] != NULL ; i++)
        {
            printf("%c\n",answer[i]);
        }
    }
    
    
    
}













