#include <stdio.h>
#include <stdlib.h>

#define TRUE	1
#define FALSE	0

#define HEAP_LEN	200010

typedef struct _pos
{
    int pay;
    int day;
}pos;

typedef pos HData;

int DataPriorityComp1(pos ch1, pos ch2)
{
    
	pos pos1 = ch1;
    pos pos2 = ch2;
    
    if(pos1.day > pos2.day)
        return 1;
    else 
        return -1;
}
int DataPriorityComp2(pos ch1, pos ch2)
{
    
	pos pos1 = ch1;
    pos pos2 = ch2;
    
    if(pos1.pay > pos2.pay)
        return 1;
    else 
        return -1;
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
    Heap heap,result_heap;
    HeapInit(&heap,DataPriorityComp1);
    HeapInit(&result_heap,DataPriorityComp2);
    pos sample;
    int N;
    int result = 0;
    int max_day = 0;
 
    scanf("%d",&N);


    for(int i = 0 ; i < N ; i++)
    {
        scanf("%d %d",&sample.pay, &sample.day);
        HInsert(&heap,sample);
        if(max_day < sample.day)
            max_day = sample.day;
    }
    
    
    for(int i = max_day ; i > 0 ; i--)
    {
        while(HPeek(&heap).day == i)
        {
            HInsert(&result_heap,HDelete(&heap));    
        }

        if(!HIsEmpty(&result_heap))
            result += HDelete(&result_heap).pay;
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















