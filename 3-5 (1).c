#include <stdio.h>
#include <stdlib.h>
#define TRUE	1
#define FALSE	0

typedef struct _pos
{
    int start;
    int finish;
}pos;

#define HEAP_LEN	500

int compare(const void *a , const void *b);

int DataPriorityComp(int ch1, int ch2)
{
    
	int num1 = ch1;
    int num2 = ch2;
    
    if(num1 < num2)
        return 1;
    else 
        return -1;
}

typedef int HData;
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
    int N,M;
    int min,max;
    Heap heap;
    HeapInit(&heap,DataPriorityComp);
    int result = 0;
    
    scanf("%d",&N);
    pos* arr = (pos*)malloc(sizeof(pos) * N);
    
    for(int i = 0 ; i < N ; i++)
        scanf("%d %d",&arr[i].start,&arr[i].finish);
     
    qsort(arr,N,sizeof(pos),compare);   
    max = 0;
    min = 0;
    for(int i = 0 ; i < N ; i++)
    {
        if(max + 1 < arr[i].start)
        {
            result += heap.numOfData * (max - min + 1);
            while(!HIsEmpty(&heap))
                HDelete(&heap);
        }
        
        if(HIsEmpty(&heap))
        {
            HInsert(&heap,arr[i].finish);
            min = arr[i].start;
        }
        else
        {
            if(arr[i].start > HPeek(&heap))
            {
                HDelete(&heap);
                HInsert(&heap,arr[i].finish);
            }
            else
                HInsert(&heap,arr[i].finish);
        }
        
        if(max < arr[i].finish)
            max = arr[i].finish;
    }
    
    result += heap.numOfData * (max - min + 1);
    while(!HIsEmpty(&heap))
        HDelete(&heap);
    
    printf("%d",result);
    

}

int compare(const void *a , const void *b) 
{
    pos num1 = *(pos*)a;
    pos num2 = *(pos*)b;
    
    
    if(num1.start > num2.start)
        return 1;
    else if(num1.start < num2.start)
        return -1;
    else
    {
        if(num1.finish < num2.finish)
            return 1;
        else
            return -1;
    }
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

