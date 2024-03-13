#include <stdio.h>
#include <stdlib.h>

#define TRUE	1
#define FALSE	0

#define HEAP_LEN	200010

typedef struct _pos
{
    int start_num;
    int end_num;
    int com_num;
    int use_num;
}pos;

typedef pos HData;

int compare(const void *a , const void *b) 
{
    pos pos1 = *(pos*)a;
    pos pos2 = *(pos*)b;
    
    if(pos1.start_num > pos2.start_num)
        return 1;
    else
        return -1;
}

int DataPriorityComp1(pos ch1, pos ch2)
{
    
	pos pos1 = ch1;
    pos pos2 = ch2;
    
    if(pos1.end_num < pos2.end_num)
        return 1;
    else 
        return -1;
}
int DataPriorityComp2(pos ch1, pos ch2)
{
    
	pos pos1 = ch1;
    pos pos2 = ch2;
    
    if(pos1.com_num < pos2.com_num)
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
    int Nowtime;
    scanf("%d",&N);
    
    pos* posarr = (pos*)malloc(sizeof(pos) * N);
    

    for(int i = 0 ; i < N ; i++)
    {
        scanf("%d %d",&posarr[i].start_num, &posarr[i].end_num);
        posarr[i].com_num = 0;
        posarr[i].use_num = 0;
    }
    
    qsort(posarr,N,sizeof(pos),compare);
    
    for(int i = 0 ; i < N ; i++)
    {
        Nowtime = posarr[i].start_num;
        
        
        
        while(!HIsEmpty(&heap))
        {
            if(Nowtime >= HPeek(&heap).end_num)
            {
                HInsert(&result_heap,HDelete(&heap));
            }
            else
            {
                break;
            }
        }
        
        
        if(HIsEmpty(&result_heap))
        {
            sample = posarr[i];
            sample.com_num = heap.numOfData + 1;
            sample.use_num = 1;
            HInsert(&heap,sample);
        }
        
        else
        {
            sample = HDelete(&result_heap);
            sample.end_num = posarr[i].end_num;
            sample.use_num = sample.use_num + 1;
            HInsert(&heap,sample);
        }
        
    }
    
    while(!HIsEmpty(&heap))
    {
        HInsert(&result_heap,HDelete(&heap));
    }
    
    printf("%d\n",result_heap.numOfData);
    while(!HIsEmpty(&result_heap))
    {
        printf("%d ",HDelete(&result_heap).use_num);
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
