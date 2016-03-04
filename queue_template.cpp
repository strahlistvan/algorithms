#include <iostream>
using namespace std;

/**  Queue template class
  *   Used array implementation, with simple modular arithmetics.
*/
template <class T>
class Queue
{
	const int SIZE;
	int front, rear;
	T * queue;
	
	public: 
	
	/** Default constructor */
	Queue() : SIZE(5)
	{
		front = 0;
		rear = SIZE-1;
		queue = new T [SIZE];
	}
	
	/** Parameterized constructor 
	  * @param int custum_size - initial size of the Queue (can not modify later)
	*/
	Queue(int custum_size):  SIZE(custum_size)
	{
		front = 0;
		rear = SIZE-1;
		queue = new T [SIZE];
	}
	
	/** @return the current size of the Queue */
	int size()
	{
			return (rear-front+1 +SIZE) % SIZE;
	}
	
	/** @return the maximal size of the Queue  (constant) */
	int max_size()
	{
		return SIZE-1;
	}
	
	/**  Put an element to the end of the Queue. Increasing Queue size.
      *   @param T elem - the element to put to the end
	  *   @return void
	 */
	void put(T elem)
	{
		if (this->size() == this->max_size()) 
		{
			cout<<"Queue is full"<<endl;
			return;
		}
		rear=(rear+1)%SIZE;
		queue[rear] = elem;
	}
	
	/** Get and erase the first element of the Queue. Decreasing Queue size.
     *   @return  the first element of the Queue
	*/
	T get()
	{
		T back_value;
		if (this->size()==0)
		{
			cout<<"Queue is empty"<<endl;
			return T();
		}
		back_value = queue[front];
		queue[front] = T();
		front=(front+1)%SIZE;
		return back_value;
	}
	
	/** Prints the elements of the Queue
	  *  Warning: it works properly only if you can use the << operator for the elements.
	*/
	void print()
	{
		if (this->size()==0)
		{
			cout<<"Queue is empty"<<endl;
			return;
		}
		
		int i;
		for(i=front; i!=rear; i=(i+1)%SIZE)
		{
			cout<<queue[i]<<" ";
		}
		cout<<queue[i]<<endl;
	}
		
	/** Prints the whole array of the queue implementation, from the beginning to the end.
	  *  It can be useful for debugging.
	  *  Warning: it works properly only if you can use the << operator for the elements.
	*/	
	void test_print()
	{
		for (int i=0; i<SIZE; ++i)
			cout<<queue[i]<<" ";
		cout<<endl;
	}
	
	/** Desctructor */
	~Queue()
	{
		delete[] queue;
	}
};

int main(int argc, char **argv)
{
	Queue<double> q(7);
	for (int i=1; i<10; ++i)
	{
		q.put(3.14*i);
		q.print();
		cout<<"Size: "<<q.size()<<endl;
	
	}
	
	while (q.size() > 2)
	{
		q.get();
		q.print();
	}
	
	q.put(121.121);
	q.print();
	q.test_print();
	q.put(1331.1331);
	q.print();
	q.test_print();
	
}