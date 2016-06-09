#include <iostream>
#include <cstdlib>
#include "linked_list.cpp"
#include "binary_search_tree.cpp"
using namespace std;

int main(int argc, char ** argv)
{
	if (argc < 3)
	{
		cerr<<"Usage: "<<argv[0]<<" <data_size> <search_size>"<<endl;
		return -1;
	}
	
	const int LIMIT = atoi(argv[1]);
	const int COUNT = atoi(argv[2]);
	
	LinkedList * list = new LinkedList();
	BinTree * tree = new BinTree();
	
	srand(0);
	for (int i=0; i<LIMIT; ++i)
	{
		int rn = rand();
		tree->insert(rn);
		list->insert(rn);
	}
	cout<<"Tree insertion complete"<<endl;
//	list->print();
//	tree->printLikeList();
	
//	srand(0);
//	for (int i=0; i<LIMIT; ++i)
//	{
//		list->insert(rand());
//	}
	cout<<"List insertion complete"<<endl;
	
	cout<<"\nFind "<<COUNT<<" random items in linked list"<<endl;
	clock_t start = clock();
	srand(42);
	int rand_num = 0, result = -1, found_count = 0;
	for (int i=0; i<COUNT; ++i)
	{
		rand_num = rand();
	    result = list->search(rand_num);
	    if (result!=-1)
			++found_count;
		result = -1;
	}
	cout<<"Completed! Found: "<<found_count<<"/"<<COUNT<<endl;
	double elapsed = (double)(clock()-start)/CLOCKS_PER_SEC;
	cout<<"List search complete ("<<elapsed<<" sec.)"<<endl;
			
	cout<<"\nFind (the same) "<<COUNT<<" random items in binary search tree"<<endl;
	start = clock();
	srand(42);
	rand_num = 0, result = -1, found_count = 0;
	for (int i=0; i<COUNT; ++i)
	{
		rand_num = rand();
		result = tree->search(rand_num);
		if (result!=-1)
			++found_count;
		result = -1;
	}
	cout<<"Completed! Found: "<<found_count<<"/"<<COUNT<<endl;
	elapsed = (double)(clock()-start)/CLOCKS_PER_SEC;
	cout<<"Tree search complete ("<<elapsed<<" sec.)"<<endl;

	return 0;
}
