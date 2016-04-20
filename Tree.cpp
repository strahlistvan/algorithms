#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

const int LIMIT = 1000; //max tree depth

/** Nodes of the tree */
struct Node
{
    int value;
    Node * parent;
    vector<Node *> children;

    void add_child(int child_value)
    {
        Node * child = new Node();
        child->parent = this;
        child->value = child_value;
        this->children.push_back(child);
    }
};

class Tree
{
    Node * root;

public:

    Tree() { root = new Node();}

    Node * getRoot() { return root; }

    /** Print recursively from the given node */
    void print_rec(Node * node, int level)
    {
        if (node->children.empty())
            return;

        for (int i=0; i<node->children.size(); ++i)
        {
            cout<<level<<". level: ";
            for (int k=1; k<=level; ++k)
                cout<<"   ";
            cout<<"-->("<<node->children[i]->value<<")"<<endl;
            print_rec(node->children[i], level+1);
        }
    }
	
    void print()
    {
       // cout<<"\n0. (root) level: ("<<root->value<<")"<<endl;
        print_rec(root, 1);
    }

    /** insert child to the given parent to with the given value */
    void add_child(Node * parent_node, int child_value)
    {
        Node * child = new Node();
        child->parent = parent_node;
        child->value = child_value;
        parent_node->children.push_back(child);
    }


    /** Make a random walk in the tree.
     *  @return product of the branching factors, in every level of the tree (integer array)
     */
    long long * random_walk()
    {
        static long long product[LIMIT] = {0};
        for (int i=0; i<LIMIT; ++i)
            product[i] = 0;
        Node * node = this->root;
        int level = 0;
        while (node!=NULL && node->children.size()!=0)
        {
            int branching_factor = node->children.size();
            if (level==0)
                product[level] = branching_factor;
            else
            {
                product[level] = product[level-1];
                product[level]*=branching_factor;
            }
            int random = rand()%branching_factor;
            node = node->children[random];
            ++level;
        }
        return product;
    }

    /** Estimate the tree size. Print the estimated tree size of every level ot the tree.
     *  @return the estimated size of the tree
     *  @param the number of random walks (default = 1000)
    */
    double estimated_size(int cycles = 1000, bool echo = true)
    {
        srand(time(0));
        double level[LIMIT] = {0};
        
        for (int k=0; k<cycles; ++k)
        {
            long long * result = this->random_walk();

            for (int i=0; result[i]; ++i)
            {
                level[i]+=(double)result[i]/cycles;
            }
        }
        double sum = 0.0;
        for (int i=0; level[i]; ++i)
        {
        		if (echo)
            	cout<<(i+1)<<". level: "<<fixed<<setprecision(2)<<level[i]<<endl;
            sum+= level[i];
        }
        return sum;
    }
	
	/** Get the tree size in every level, with depth-first search.
	 * @param node - current root node of the tree, level - current level
	 * @param levels_size - array of every levels size (output variable)
	*/
	void get_size_rec(Node * node, int level, int * levels_size)
	{
		if (node->children.empty())
            return;

        for (int i=0; i<node->children.size(); ++i)
        {
				++levels_size[level-1]; 
            get_size_rec(node->children[i], level+1, levels_size);
        }
		return;
	}
	
	/** Print and return the real size of the tree. */
	long long real_size(bool echo = true)
	{
		long long sum = 0;
		int levels_size[LIMIT] = {0}; 
		get_size_rec(root, 1, levels_size);
		for (int i=0; levels_size[i]; ++i)
		{
			if (echo)
				cout<<(i+1)<<". level: "<< levels_size[i] <<endl;
			sum+=(long long)levels_size[i];
		}
		return sum;
	}
};
