#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1024

int SIZE = 10;
int heap[MAX_SIZE]={1, 3, 2, 1, 8, 5, 13, 21, 55, 34, 89};


void print_array()
{ 
	int i;
	for(i = 1; i<=SIZE; ++i)
		printf(" %d ,", heap[i]);
	printf("\n");
}

void heapify(int place)
{ 
	int tmp, max_index;
	if (2*place<=SIZE)
	{
		if (2*place==SIZE)
		{
			if(heap[2*place] > heap[place])
			{
				tmp = heap[place];
				heap[place] = heap[2*place];
				heap[2*place] = tmp;
			}
		}
		else
		{
			max_index=(heap[2*place+1] > heap[2*place])? 2*place+1: 2*place;
			if (heap[max_index] > heap[place])
			{
				tmp = heap[place];
				heap[place] = heap[max_index];
				heap[max_index] = tmp;
				heapify(max_index);
			}
		}
	}
}

void build_heap()
{ 
	int i;
	for (i=SIZE; i>=1; --i) 
		heapify(i);
}

int max_del()
{ 
	int max_value = heap[1];
	heap[1]=heap[SIZE--];
	heapify(1);
	return max_value;
}

void insert(int elem)
{
	int place = ++SIZE, tmp;
	heap[place] = elem;
	while ((place>1) && (heap[place/2] < heap[place]))
	{
		tmp = heap[place];
		heap[place] = heap[place/2];
		heap[place/2] = tmp;
		place = place/2;
	}
}

void print_rec(int place, int level)
{
	if (place >= SIZE)
		return;
		
	for (int i=0; i<level; ++i)
		printf("--");
	printf("->%d\n",heap[place]);
		
	print_rec(2*place, level+1);
	print_rec(2*place+1, level+1);	
}

int main(int argc, char ** argv)
{
	  int i;
	  print_array();
	  build_heap();
	  print_array();
	  insert(22);
	  print_array();
	  print_rec(1, 0);
	  for (i=1; i<=SIZE; ++i) 
		printf(" %d , ", max_del());
	  printf("\n");
	  return 0;
}
