#include <stdio.h>
#include <stdlib.h>

#define TRUE	1
#define FALSE	0

#define HEAP_LEN	200010

typedef int HData;


int DataPriorityComp1(int ch1, int ch2)
{
    
	if(abs(ch1)>abs(ch2))
	    return 1;
	else
	{
	    return -1;
	}

}
typedef int PriorityComp(HData d1, HData d2);

typedef struct _heap
{
	PriorityComp * comp;
	int numOfData;
	HData heapArr[HEAP_LEN];
} Heap;

/*** Heap 관련 연산들 ****/
void HeapInit(Heap * ph, PriorityComp pc);
int HIsEmpty(Heap * ph);
HData HPeek(Heap * ph);
void HInsert(Heap * ph, HData data);
HData HDelete(Heap * ph);

int main(void)
{
    Heap minus_heap,plus_heap,result_heap;
    HeapInit(&plus_heap,DataPriorityComp1);
    HeapInit(&minus_heap,DataPriorityComp1);
    HeapInit(&result_heap,DataPriorityComp1);
    
    int data;
    int N,M,K;
    int result = 0;
    
    scanf("%d %d",&N ,&M);

    for(int i = 0 ; i < N ; i++)
    {
        scanf("%d",&data);
        if(data > 0)
            HInsert(&plus_heap,data);
        else
            HInsert(&minus_heap,abs(data));
    }
    
    K = 0;
    while(!HIsEmpty(&plus_heap))
    {
        data = HDelete(&plus_heap);
        if(K % M == 0)
            HInsert(&result_heap,data);
        K++;
    }
    
    K = 0;
    while(!HIsEmpty(&minus_heap))
    {
        data = HDelete(&minus_heap);
        if(K % M == 0)
            HInsert(&result_heap,data);
        K++;
    }
    
    result = HDelete(&result_heap);
    
    while(!HIsEmpty(&result_heap))
    {
        data = HDelete(&result_heap);
        result += data;
        result += data;
    }
    
    printf("%d",result);
    
}



void HeapInit(Heap * ph, PriorityComp pc)
{
	ph->numOfData = 0;
	ph->comp = pc;
}

int HIsEmpty(Heap * ph)
{
	if(ph->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

int GetParentIDX(int idx) 
{ 
	return idx/2; 
}

int GetLChildIDX(int idx) 
{ 
	return idx*2; 
}

int GetRChildIDX(int idx) 
{ 
	return GetLChildIDX(idx)+1; 
}

int GetHiPriChildIDX(Heap * ph, int idx)
{
	if(GetLChildIDX(idx) > ph->numOfData)
		return 0;

	else if(GetLChildIDX(idx) == ph->numOfData)
		return GetLChildIDX(idx);

	else
	{
	//	if(ph->heapArr[GetLChildIDX(idx)].pr 
	//				> ph->heapArr[GetRChildIDX(idx)].pr)
		if(ph->comp(ph->heapArr[GetLChildIDX(idx)], 
					ph->heapArr[GetRChildIDX(idx)]) < 0)
			return GetRChildIDX(idx);
		else
			return GetLChildIDX(idx);
	}
}

void HInsert(Heap * ph, HData data)
{
	int idx = ph->numOfData+1;

	while(idx != 1)
	{
	//	if(pr < (ph->heapArr[GetParentIDX(idx)].pr))
		if(ph->comp(data, ph->heapArr[GetParentIDX(idx)]) > 0)
		{
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		else
		{
			break;
		}
	}
	
	ph->heapArr[idx] = data;
	ph->numOfData += 1;
}

HData HDelete(Heap * ph)
{
    
    
	HData retData = ph->heapArr[1];
	HData lastElem = ph->heapArr[ph->numOfData];

	int parentIdx = 1;
	int childIdx;

	while(childIdx = GetHiPriChildIDX(ph, parentIdx))
	{
	//	if(lastElem.pr <= ph->heapArr[childIdx].pr)
		if(ph->comp(lastElem, ph->heapArr[childIdx]) >= 0)
			break;

		ph->heapArr[parentIdx] = ph->heapArr[childIdx];
		parentIdx = childIdx;
	}

	ph->heapArr[parentIdx] = lastElem;
	ph->numOfData -= 1;
	return retData;
}


HData HPeek(Heap * ph)
{
    return ph->heapArr[1];     
}















