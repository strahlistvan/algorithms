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
		if (head==NULL)
		{
			head = new Node(elem);
			++size;
			return;
		}
			
		if (head->next == NULL)
		{
			if (elem < head->value)
			{
				swap(elem, head->value);
			}
			head->next = new Node(elem);
			++size;
			return;
		}
		
		Node * node = head;
		//Amig van rakovetkezo, es kisebb mint az elem (beszurasi hely megkeresese)
		while (node->next && node->next->value < elem)
		{
			node = node->next;
		}
		if (head->next->value < head->value)
			swap(head->next->value, head->value);
		
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
};

int main(int argc, char ** argv)
{
	LinkedList * list = new LinkedList();
	list->insert(10);
	list->insert(30);
	list->insert(20);
	list->print();
	list->delNode(1);
	list->print();
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
	
	list->insert(111);
	list->insert(2);
	list->insert(1);
	list->insert(42);
	cout<<endl;
	list->print();
	
	return 0;
}
