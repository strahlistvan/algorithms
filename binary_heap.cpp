#include <iostream>
#include <cstdio>
using namespace std;

class BinHeap
{
	const int MAX_SIZE;
	int SIZE;
	int * heapArray;
	
	
	/** Private function for recursive calling */
	void printRec(int place, int level)
	{
		if (place >= SIZE)
			return;
		
		for (int i=0; i<level; ++i)
			cout<<"--";
		cout<<"->"<<heapArray[place]<<endl;
		
		printRec(2*place, level+1);
		printRec(2*place+1, level+1);
		
	}
	
	public:
	
	/** Default constructor */
	BinHeap() : MAX_SIZE(1024)
	{
		heapArray = new int [MAX_SIZE];
		int SIZE = 0;
	}
	
	/** Consturctor: build heap from the given numbers */
	BinHeap(int * array, int size) : MAX_SIZE(1024)
	{
		heapArray = new int[MAX_SIZE];
		heapArray[0] = 0;
		for (int i=0; i<size && i<MAX_SIZE; ++i)
		{
			heapArray[i+1] = array[i];
		}
		
		this->SIZE = size;
		this->buildHeap();
	}

	 /** Insert a new element in the heap */
	void insert(int elem)
	{
		int place = ++SIZE; //inserting the end of the array
		heapArray[place] = elem; //insert
		
		//while the element less then the parent, swap them
		while ((place>1) && (heapArray[place/2] < heapArray[place]))
		{
			swap(heapArray[place], heapArray[place/2]);		
			place = place/2;
		}
	}
	
	/** Build heap to the element in the given place */
	void heapify(int place)
	{ 
		if (2*place<=SIZE) //if leaf node
		{
			if (2*place==SIZE)
			{
				if(heapArray[2*place] > heapArray[place])
				{
					swap(heapArray[place], heapArray[2*place]);
				}
			}
			else
			{
				//get the biggest index: parent node/left/right child
				int maxIndex=(heapArray[2*place+1] > heapArray[2*place])? 2*place+1: 2*place;
				
				//if not the parent is the biggest: swap+recursive call
				if (heapArray[maxIndex] > heapArray[place])
				{
					swap(heapArray[maxIndex], heapArray[place]);
					heapify(maxIndex);
				}
			}
		}
	}
	
	/** Build a heap from the unordered (private) array */
	void buildHeap()
	{
		//heapify for all  node
		for (int i=SIZE; i>=1; --i)
		{
			heapify(i);
		}
	}
	
	/** Delete the maximum element (root), and return with it
	 *  It also restores the heap property after deletion
	 * */
	int maxDel()
	{
		int max = heapArray[1];
		heapArray[1]=heapArray[SIZE--];
		heapify(1); //heap
		return max;
	}
	
	/** Print the heap's array (for debugging for example) */
	void printArray()
	{ 
		for(int i = 1; i<=SIZE; ++i)
			cout<<heapArray[i]<<", ";
		cout<<endl;
	}
	
	
	void printHeap()
	{
		printRec(1, 0);
	}
	
	int getSize()
	{
		return SIZE;
	}
	
	int getRoot()
	{
		return heapArray[1];
	}
	
	/** Sort elements decreasing order with heap sort O(n*log n) */
	static void decSort(int * array, int * end)
	{
		int N = (end-array);
		BinHeap * heap = new BinHeap(array, N);
		
		for (int i=1; i<=N; ++i)
		{
			array[i-1] = heap->maxDel();
		}
	}
	
	/** Sort elements increasing order with heap sort O(n*log n) */
	static void incSort(int * array, int * end)
	{
		int N = (end-array);
		BinHeap::decSort(array, end);
		for (int i=0; i<=N/2; ++i)
		{
			swap(array[i], array[N-1-i]);
		}
	}
};

int main(int argc, char ** argv)
{
	BinHeap * h1 = new BinHeap();
	h1->insert(12);
	h1->insert(20);
	h1->insert(4);
	h1->insert(42);
	h1->printArray();
	
	int arr[10] = {1, 3, 2, 1, 8, 5, 13, 21, 55, 34}; 
	BinHeap * h2 = new BinHeap(arr, 10);
	h2->insert(111);
	h2->printArray();
	h2->printHeap();
	BinHeap::decSort(arr, arr+9);
	for (int i=0; i<9; ++i) 
		cout<<arr[i]<<", ";
	cout<<endl;
	BinHeap::incSort(arr, arr+9);
	for (int i=0; i<9; ++i) 
		cout<<arr[i]<<", ";
	cout<<endl;
	return 0;
}
