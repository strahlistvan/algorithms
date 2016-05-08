#include <iostream>
using namespace std;

/** Node of a binary tree
 *  properties: 1. value of the node
 *              2. pointer to the node's left child
 *              3. pointer to the node's right child
 **/
struct Node
{
	int value;
	Node * leftChild;
	Node * rightChild;
	
	Node()
	{
		this->value = 0;
		this->leftChild = this->rightChild = NULL;
	}
	
	Node(int value)
	{
		this->value = value;
		this->leftChild = this->rightChild = NULL;
	}
	
	/** Insert value to the Node element */
	void addChild(int value)
	{
		if (this->leftChild == NULL)
			this->leftChild = new Node(value);
		else if (this->rightChild == NULL)
			this->rightChild = new Node(value);
		else 
			cerr<<"Can not add more child to ("<<this->value<<") node"<<endl;
	}
};

/** Binary tree class 
 *  Propery: root = pointer to the tree root
 *  You can search in the tree, and print the tree (recursive methods) 
 *  Insert method not implemented yet, you need to build the tree "manually" 
 **/
class BinTree 
{
	Node * root;
	
	void printRec(Node * node, int level)
	{
		if (node==NULL)
		    return;
		
		for (int i=0; i<level; ++i)
			cout<<"--";
		cout<<"-> ("<<node->value<<")"<<endl;
		
		
		printRec(node->leftChild, level+1);
		printRec(node->rightChild, level+1);
		
	}
	
	int searchRec(int key, Node * node)
	{
		static int pos = -1, foundPos = -1;
		if (node==NULL)
		    return foundPos;
	
	  ++pos;
	   if (node->value == key)
	   {
		   cout<<key<<" is in the tree "<<pos<<endl;
		   foundPos = pos;
		   return foundPos;
	   }
	   
	   searchRec(key, node->leftChild);
	   searchRec(key, node->rightChild);
	}

   Node * getNodeInPosRec(int pos_par, Node * node)
   {
	   static int pos = 0;
	   static Node * foundNode = NULL;
	   
	   if (node==NULL)
	       return foundNode;
	   
	   	if(pos == pos_par)
	   	{
			cout<<"Node value in position "<<pos<<" = "<<node->value<<endl;
			foundNode = node;
		}
	   ++pos; 
	   
	   getNodeInPosRec(pos_par, node->leftChild);
	   getNodeInPosRec(pos_par, node->rightChild);
   }
	
	public: 
	
	BinTree() 
	{
		root = new Node();
	}
	
	Node * getRoot()
	{
		return this->root;
	}
   
   Node * getNodeInPos(int pos_par)
   {
	   return getNodeInPosRec(pos_par, this->root);
   }
   
	void print()
	{
		printRec(this->root, 0);
	}
	
	int search(int key)
	{
		return searchRec(key, this->root);
	}
		
};

int main (int argc, char ** argv)
{
	BinTree * bt = new BinTree();
	Node * node =  bt->getRoot();
	node->value = 543;
	node->addChild(20);
	node->addChild(100);
	node->addChild(234);
	
	node = node->leftChild;
	node->addChild(121);
	node->addChild(1331);
	node = bt->getRoot()->rightChild;
	node->addChild(14641);
	node->addChild(43);
	
	bt->print();
	int pos = bt->search(1331);
	if (pos==-1)
		cout<<"Not in the tree"<<endl;
	else 
		cout<<"In the tree in position: "<<pos<<endl;
		
    node = bt->getNodeInPos(2);
    cout<<node->value<<endl;
	return 0;
}
