#include<stdio.h>
#include<stdlib.h>

#define TRUE	1
#define FALSE	0

#define HEAP_LEN	200010

typedef struct _pos
{
    int x;
    int y;
}pos;


typedef pos HData;

int DataPriorityComp(pos ch1, pos ch2)
{

	if(ch1.y > ch2.y)
	    return -1;
	else
	{
	    return 1;
	}

}

int compare1(const void *a , const void *b) 
{
    pos pos1 = *(pos*)a;
    pos pos2 = *(pos*)b;
    
    if(pos1.x > pos2.x)
        return 1;
    else if(pos1.x < pos2.x)
        return -1;
    else
    {
        if(pos1.y > pos2.y)
            return 1;
        else
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
    Heap heap;
    HeapInit(&heap,DataPriorityComp);
    HData data;
    int xpos,ypos;
    
    int N;	
    scanf("%d",&N);
    pos* posarr = (pos*)malloc(sizeof(pos) * N);
    
    for(int i = 0 ;i<N ;i++)
    {
        scanf("%d %d",&xpos,&ypos);
        posarr[i].x = xpos;
        posarr[i].y = ypos;
    }
    
    qsort(posarr,N,sizeof(pos),compare1);
    
    for(int i = 0 ; i < N ; i++)
    {
        if(heap.numOfData == 0)
            HInsert(&heap,posarr[i]);
        
        else
        {
            if(HPeek(&heap).y <= posarr[i].x)
            {
                HDelete(&heap);
                HInsert(&heap,posarr[i]);
            }
            else
            {
                HInsert(&heap,posarr[i]);    
            }
        }
    }
        
    printf("%d",heap.numOfData);
    
    
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