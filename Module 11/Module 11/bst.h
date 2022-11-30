#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class treenode {//node in a BST
public:
	string county_name;
	double population_size;
	treenode* lchild, * rchild; //left and right children pointers
};
class bst {
public:
	bst(); // store the data file(“county_data.txt”) into initial bst
	~bst(); //de-allocates dynamic memory allocate for tree
	bool empty(); // checks to see if the tree is empty
	void insert(const string& item, const double& population); //inserts a county record into bst based on county_name.
	void insert(treenode*&, const string& item, const double& population); //see insert description above
	void del_name(string item); //deletes a county record based on county name.
	void del_name(treenode*& loc_ptr, string item); //see del description above
	treenode* search_tree(treenode*, string item); //returns pointer to node with county name
	treenode* search_tree(string item); //see search_tree description above
	treenode* inorder_succ(treenode*); //return pointer to inorder successor (based on county name).
	void county_ranges(const string& min_name, const string& max_name); //prints all county names
	//to the screen between min_name and max_name, inclusive.
	void print_tree(); //prints each county record to the screen sorted by county name.
	void print_tree(treenode*);
	void sorted_info();//prints each county record to a file called “county_info.txt” sorted by county_name.
	void createSort(treenode* node, vector<string>& v);
	void print_range(treenode* root, const string& min, const string& max);
private:
	treenode* root;
};
