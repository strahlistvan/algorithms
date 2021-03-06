#include <iostream>
using namespace std;

struct Node 
{
	int value;
	Node * next;
	
	Node()
	{
		this->value = 0;
	}
	
	Node(int value)
	{
		this->value = value;
	}
	
	Node(int value, Node * next)
	{
		this->value = value;
		this->next = next;
	}
	
};

class LinkedList
{
	Node * head;
	int size;
	
	public: 
	
	LinkedList()
	{
		head = NULL;
		size = 0;
	}
	
	void insert(int elem)
	{
		//Ha ures a lista
		if (head==NULL)
		{
			head = new Node(elem);
			++size;
			return;
		}
		
		//Ha az elem a beszrando legkisebb
		if ( elem < head->value)
		{
			Node * nextNode = head;
			head = new Node(elem, nextNode);
			++size;
			return;
		}

		Node * node = head;
		//Amig van rakovetkezo, es kisebb mint az elem (beszurasi hely megkeresese)
		while (node->next && node->next->value < elem)
		{
			node = node->next;
		}
		
		Node * nextNode = node->next;	//rakovetkezo elmentese
		node->next = new Node(elem, nextNode);	//beszuras az uj helyre
		++size;	//meret noveles -> "extra" funkcio
	}
	
	void delNode(int index)
	{
		if (head == NULL)	//ures-e a lista?
		{
			cout<<"Empty list. Nothing to delete"<<endl;
			return;
		}
		
		if (head->next == NULL)	//utolso elem torlese
		{
			head = NULL;
			size = 0;
			return;
		}
			
		//Index ellenorzese
		if (index >= size || index < 0)
		{
			cerr<<"Invalid index: "<<index<<". Must be between 0 and "<<(size-1)<<endl;
			return;
		}
				
		//Torlendo csucs elodjenek megkeresese
		Node * prevNode = head;
		for (int k=0; prevNode->next && k<index-1; ++k)
		{
			prevNode = prevNode->next;
		}
		Node * nextNode = prevNode->next->next;
		Node * delNode = prevNode->next;
		cout<<"Node to delete: "<<delNode->value<<endl;
		delete delNode;
		prevNode->next = nextNode;
		--size;
	}
	
	int get_size()
	{
		return this->size;
	}
	
	void print()
	{
		if (head==NULL)
		{
			cout<<"Empty list"<<endl;
			return;
		}
		
		Node * node = head;
		do
		{
			cout<<node->value<<", ";
			node = node->next;
		}
		while (node!=NULL);
		cout<<endl;
	}
	
	int search (int elem)
	{
		Node * node = head;
		int index = 0;
		//Amig van rakovetkezo, es a jelenlegi kisebb mint az elem 
		while (node->next && node->value < elem)
		{
			++index;
			node = node->next;
		}
		if (node->value == elem)	//ha van talalat
		{
			cout<<node->value<<" is in "<<index<<" index"<<endl;
			return index;
		}
		cout<<index<<" element not found in list"<<endl;
		return -1;
	}
	
	int & operator[] (int index)
	{
		//Index ellenorzese
		if (index >= size || index < 0)
		{
			cerr<<"Invalid index: "<<index<<". Must be between 0 and "<<(size-1)<<endl;
			return head->value;
		}
		
		Node * node = head;
		for (int k=0; head->next && k<index; ++k)
		{
			node = node->next;
		}
		return node->value;
	}
	
};

int main(int argc, char ** argv)
{
	LinkedList * list = new LinkedList();
	list->insert(10);
	list->insert(30);
	list->insert(20);
	//list->print();
	//list->delNode(1);
	//list->print();
	list->insert(40);
	list->insert(35);
	list->print();
	cout<<"Size: "<<list->get_size()<<endl;
	list->delNode(0);
	cout<<"Size: "<<list->get_size()<<endl;
	list->delNode(4);
	cout<<"Size: "<<list->get_size()<<endl;
	list->delNode(2);
	cout<<"Size: "<<list->get_size()<<endl;
	list->delNode(0);
	list->delNode(0);
	list->delNode(0);
	list->delNode(0);
	list->delNode(0);
	
	cout<<"size: "<<list->get_size()<<endl;
	
	
	list->insert(111);
	list->insert(2);
	list->insert(1);
	list->insert(42);
	list->print();	
	list->search(111);
	list->search(112);
	list->search(1);
	list->search(43);
	list->search(-2);
	
	cout<<list->get_size()<<endl;
	int elem = (*list)[4];
	cout<<elem<<endl;
	return 0;
}
