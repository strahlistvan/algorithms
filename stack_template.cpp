#include <iostream>
#include <cstdlib>
using namespace std;

template <class T>
class Stack 
{
	T * stack;
	const int maxSize;
	int size, top;
	
	public: 
	
	/** Default constructor */
	Stack() : maxSize(1000000)
	{
		size = 5000, top = -1;
		stack = new T[size];
	}
	
	
	/** Push an element to the Stack. Increasing Stack size.
       * @param T  elem - element to push	
	  *  @return void
	*/
	void push(T elem)
	{
		int n = 5000;
		if (size > maxSize+n)
		{
			cerr<<"Stack is full"<<endl;
			return;
		}
		
		if (top == size-1)
		{
			cout<<"Increasing buffer"<<size+n<<endl;
			T * tmp = new T[size+n];
			for (int i=0; i<size; ++i)
				tmp[i] = stack[i];
			stack = tmp;
			delete[] tmp;
			size+=n;
		}
		++top;
		stack[top] = elem;
	}
	

	 /** Prints the stack elements 
	  *   Warning: it works properly only if you can use the << operator for the elements.
	  */
	void print()
	{
		for (int i=0; i<=top; ++i)
			cout<<stack[i]<<", ";
		cout<<endl;
	}
	
	
	/** Pops the first element of the Stack object. Decrease Stack size.
	  * @return T - the popped (removed) element.
	*/
	T pop()
	{
		if (top==-1)
		{
			cout<<"Stack is empty."<<endl;
			return T();
		}
		return stack[top--];
	}
	
	/** is the Stack empty? */
	bool isEmpty()
	{
		return (top==-1);
	}
	
	/** Default destructor */
	~Stack()
	{
		delete[] stack;
	}
};

int main()
{	
	Stack<string> * s1 = new Stack<string>();
	
	s1->push("melone");
	s1->push("apple");
	s1->push("pear");
	s1->push("strawberry");
		
	s1->print();
	string elem = s1->pop();
	elem = s1->pop();
	elem = s1->pop();
	cout<<"The element: "<<elem<<endl;
	s1->print();
	
	for (int i=0; i<20; ++i)
		s1->pop();
}
