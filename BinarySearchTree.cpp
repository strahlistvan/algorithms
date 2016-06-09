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
	Node * parent;
	Node * leftChild, * rightChild;
	
	Node()
	{
		this->value = 0;
		this->parent = NULL;
		this->leftChild = this->rightChild = NULL;
	}
	
	Node(int value)
	{
		this->value = value;
		this->parent = NULL;
		this->leftChild = this->rightChild = NULL;
	}
	
	/** Insert value to the Node element */
	void addChild(int value)
	{
		if (this->leftChild == NULL)
		{
			this->leftChild = new Node(value);
			this->leftChild->parent = this;
		}
		else if (this->rightChild == NULL)
		{
			this->rightChild = new Node(value);
			this->leftChild->parent = this;
		}
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
	
	/** Print tree with recursive preorder traversal */
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
		   cout<<key<<" is inside the tree. Position: "<<pos<<endl;
		   foundPos = pos;
		   return foundPos;
	   }
	   
	   searchRec(key, node->leftChild);
	   searchRec(key, node->rightChild);
	}
	
	void printLikeListRec(Node * node)
	{
		if (node == NULL)
			return;
		
		printLikeListRec(node->leftChild);
		cout<<node->value<<", ";
		printLikeListRec(node->rightChild);
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
		root = NULL;
	}
	
	BinTree(int value)
	{
		root = new Node(value);
	}
	
	Node * getRoot()
	{
		return this->root;
	}
   
   Node * getNodeInPos(int pos_par)
   {
	   return getNodeInPosRec(pos_par, this->root);
   }
   
   int getValueInPos(int pos_par)
   {
	   Node * node = getNodeInPosRec(pos_par, this->root);
	   return node->value;
   }
   
   int & operator [] (int pos_par)
   {
	   Node * node = getNodeInPosRec(pos_par, this->root);
	   return node->value;
   }
   
	void print()
	{
		if (this->root == NULL)
			cout<<"Binary search tree is empty"<<endl;
		else
			printRec(this->root, 0);
	}
	
	void printLikeList()
	{
		printLikeListRec(root);
		cout<<endl;
	}
	
	/** Iterative searching in the binary search tree */
	int search(int key)
	{
		TreeNode * node = root;
		int found = -1;
		while (node!=NULL && node->value!=key)
		{
			if (key < node->value)
				node = node->leftChild;
			else
				node = node->rightChild;
		}
		
		if (node==NULL)
			return -1;
		if (node->value == key)
			return node->value;
	}
	
	int insert(int key)
	{
		//Find the insert place
		Node * node = this->root;
		Node * parentNode = NULL;
		while (node!=NULL)
		{
		    parentNode = node;	
			if (key < node->value)
			{
				//cout<<key<<"<"<<node->value<<endl;
				node = node->leftChild;
			}
			else
			{
				//cout<<key<<">"<<node->value<<"("<<parentNode->value<<")\n";
				node = node->rightChild;
			}
		}
		
		//Insert to node to the good place
		Node * insertNode = new Node(key);
		insertNode->parent = parentNode; 
		
		if (parentNode == NULL)
			this->root = insertNode;
		else if (key < parentNode->value)
			parentNode->leftChild = insertNode;
		else
			parentNode->rightChild = insertNode;
	}

	Node * getNextNode(int key)
	{
		Node * node = getNodeWithValue(key);
		cout<<"ertek: "<<node->value<<endl;
		
		//if the given node right subtree is not empty
		if (node->rightChild != NULL)
		{
			//find the leftest (minimal) in the subtree
			while (node->rightChild != NULL)
			{
				node = node->leftChild;
			}
			return node;
		}
		
		Node * parentNode = node->parent;
		//go up in the tree, while the node is not the leftChild of his parent
		while (parentNode!=NULL && node == parentNode->leftChild)
		{ 
			node = parentNode;
			parentNode = parentNode->parent;
		}
		return parentNode;
	}
};

int main (int argc, char ** argv)
{
	BinTree * bt = new BinTree(2); 
    bt->insert(13);
    bt->insert(90);
    bt->insert(17);
    bt->insert(1);
    bt->insert(21);
    bt->insert(6);
    bt->print();
    
    bt->printLikeList();
    bt->search(6);
    cout<<bt->getValueInPos(3)<<"=="<<(*bt)[3]<<endl;
    
	return 0;
}
