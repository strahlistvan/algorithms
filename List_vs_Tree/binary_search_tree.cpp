#include <iostream>
using namespace std;

/** Node of a binary tree
 *  properties: 1. value of the node
 *              2. pointer to the node's left child
 *              3. pointer to the node's right child
 **/
struct TreeNode
{
	int value;
	TreeNode * parent;
	TreeNode * leftChild, * rightChild;
	
	TreeNode()
	{
		this->value = 0;
		this->parent = NULL;
		this->leftChild = this->rightChild = NULL;
	}
	
	TreeNode(int value)
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
			this->leftChild = new TreeNode(value);
			this->leftChild->parent = this;
		}
		else if (this->rightChild == NULL)
		{
			this->rightChild = new TreeNode(value);
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
	TreeNode * root;
	
	/** Print tree with recursive preorder traversal */
	void printRec(TreeNode * node, int level)
	{
		if (node==NULL)
		    return;
		
		for (int i=0; i<level; ++i)
			cout<<"--";
		cout<<"-> ("<<node->value<<")"<<endl;
		
		printRec(node->leftChild, level+1);
		printRec(node->rightChild, level+1);
	}
	
	int searchRec(int key, TreeNode * node)
	{
		static int pos = -1, foundPos = -1;
		if (node==NULL)
		    return foundPos;
	
	  ++pos;
	   if (node->value == key)
	   {
		//   cout<<key<<" is inside the tree. Position: "<<pos<<endl;
		   foundPos = pos;
		   return foundPos;
	   }
	   
	   searchRec(key, node->leftChild);
	   searchRec(key, node->rightChild);
	}
	
	void printLikeListRec(TreeNode * node)
	{
		if (node == NULL)
			return;
		
		printLikeListRec(node->leftChild);
		cout<<node->value<<", ";
		printLikeListRec(node->rightChild);
	}

   TreeNode * getNodeInPosRec(int pos_par, TreeNode * node)
   {
	   static int pos = 0;
	   static TreeNode * foundNode = NULL;
	   
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
		root = new TreeNode(value);
	}
	
	TreeNode * getRoot()
	{
		return this->root;
	}
   
   TreeNode * getNodeInPos(int pos_par)
   {
	   return getNodeInPosRec(pos_par, this->root);
   }
   
   int getValueInPos(int pos_par)
   {
	   TreeNode * node = getNodeInPosRec(pos_par, this->root);
	   return node->value;
   }
   
   int & operator [] (int pos_par)
   {
	   TreeNode * node = getNodeInPosRec(pos_par, this->root);
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
		TreeNode * node = this->root;
		TreeNode * parentNode = NULL;
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
		TreeNode * insertNode = new TreeNode(key);
		insertNode->parent = parentNode; 
		
		if (parentNode == NULL)
			this->root = insertNode;
		else if (key < parentNode->value)
			parentNode->leftChild = insertNode;
		else
			parentNode->rightChild = insertNode;
	}
};
