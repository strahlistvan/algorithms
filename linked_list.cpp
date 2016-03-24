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
			return;
		}
		
		Node * node = head;
		//Amig van rakovetkezo, es kisebb mint az elem (beszurasi hely megkeresese)
		while (node->next && node->next->value < elem)
		{
			//cout<<node->value<<"<"<<elem<<endl;
			node = node->next;
		}
		
		Node * next = node->next;	//rakovetkezo elmentese
		node->next = new Node(elem, next);	//beszuras az uj helyre
		++size;	//meret noveles -> "extra" funkcio
	}
	
	void delNode(int index)
	{
		//Index ellenorzese
		if (index > size || index < 0)
		{
			cerr<<"Invalid index: "<<index<<". Must be between 0 and "<<size<<endl;
			return;
		}
		
		Node * prevNode = head;
		//Torlendo csucs elodjenek megkeresese
		for (int k=0; prevNode->next && k<index-1; ++k)
		{
			prevNode = prevNode->next;
		}
		Node * nextNode = prevNode->next->next;
		Node * delNode = prevNode->next;
		cout<<"Node to delete: "<<delNode->value<<endl;
		delete delNode;
		prevNode->next = nextNode;
	
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
	list->insert(40);
	list->insert(35);
	list->print();
	list->delNode(4);
	list->delNode(2);
	list->print();
}
