//백준 1655
//다음문제 14235,15903,1715

#include<stdio.h>
#include<stdlib.h>

#define TRUE	1
#define FALSE	0


#define HEAP_LEN	100001
typedef int HData;

int DataPriorityComp1(int ch1, int ch2)
{
	return ch2-ch1;
}
int DataPriorityComp2(int ch1, int ch2)
{
	return ch1-ch2;
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
    int N;
    int num;
    
    Heap max_heap;
    HeapInit(&max_heap,DataPriorityComp2);
    Heap min_heap;
    HeapInit(&min_heap,DataPriorityComp1);
    
    scanf("%d",&N);
    
    // 처음을 위해서
    scanf("%d",&num);
    HInsert(&max_heap,num);
    printf("%d\n",HPeek(&max_heap));
    
    for(int i = 1 ; i < N ; i++)
    {
        scanf("%d",&num);
        
        if(max_heap.numOfData == min_heap.numOfData)
        {
            //max에 담기  
            if(num > HPeek(&min_heap))
            {
                HInsert(&max_heap,HDelete(&min_heap));
                HInsert(&min_heap,num);
            }
            else
            {
                HInsert(&max_heap,num);    
            }
        }
        else
        {
            if(num < HPeek(&max_heap))
            {
                HInsert(&min_heap,HDelete(&max_heap));
                HInsert(&max_heap,num);
            }
            else
            {
                HInsert(&min_heap,num);
            }
        }
        
        //답 말하기
        printf("%d\n",HPeek(&max_heap));
        
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
    if(ph->numOfData == 0)
    {
        return 0;
    }
    
    
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




