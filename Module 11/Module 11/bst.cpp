/*
This is a simple program to give the student experience writing code
for binary trees.  This is a CLASS implementation of the BST ADT.
The student should study, comment, correct errors, compile,
implement/un-implemented/undeveloped functions, and modify code to make
it more efficient when ever necessary. The student should be able to
discuss the advantages and disadvantages of using such an
implementation.
*/


#include "bst.h"
#include <sstream>
#include <fstream>
bst::bst() {
    //create input file stream object
    ifstream in("county_data.txt");
    string line;
    while (getline(in, line)) {//get data line by line
        vector<string> v; //crate vecctor object to hold seprate values from string
        size_t pos = 0;
        string delimeter = " ";
        string token;
        while ((pos = line.find(delimeter)) != string::npos) {
            token = line.substr(0, pos);
            v.push_back(token);
            line.erase(0, pos + delimeter.length());
        }
        //last element in vector is pupulation of contry
        double popul = stod(line);//convert string to double
        //get name of county from vector
        string name = v.at(0);
        if (v.size() > 1) {
            name.append(" ");
            name.append(v.at(1));
        }
        //clear vector
        v.clear();
        // create node in tree
        insert(name, popul);
    }
    // close file object when done reading
    in.close();
}
bst::~bst() {
    while (root != 0) {
        del_name(root->county_name);
    }
}
bool bst::empty() {
    return (root == 0);
}
void bst::insert(const string& item, const double& population) {
    // call overloaded function to insert item
    insert(root, item, population);
}
void bst::insert(treenode*& loc_ptr, const string& item, const double& population) {
    // if root node is 0 then insert in root node
    if (loc_ptr == 0) {
        loc_ptr = new treenode;
        loc_ptr->lchild = loc_ptr->rchild = 0;
        loc_ptr->county_name = item;
        loc_ptr->population_size = population;
    }
    // add node acording to county name in binary tree
    else if (loc_ptr->county_name.compare(item) > 0) {
        insert(loc_ptr->lchild, item, population);
    }
    else if (loc_ptr->county_name.compare(item) < 0) {
        insert(loc_ptr->rchild, item, population);
    }
    // print message when county is already in list
    else {
        cout << "the county is already in the tree\n";
    }
}
treenode* bst::search_tree(string item) {
    // search tree from root node
    return search_tree(root, item);
}
treenode* bst::search_tree(treenode* loc_ptr, string item) {
    //check if current node is not empty
    if (loc_ptr != 0) {
        //if current node contians county name return pointer to current node
        if (loc_ptr->county_name.compare(item) == 0) {
            return loc_ptr;
        }
        // else if corrent node's county name is greater then given contry name move to left side
        else if (loc_ptr->county_name.compare(item) > 0) {
            return search_tree(loc_ptr->lchild, item);
        }
        // else move to right side
        else {
            return search_tree(loc_ptr->rchild, item);
        }
    }
    // if current node is NULL then return current node
    else {
        return loc_ptr;
    }
}
void bst::del_name(string item) {
    //search from root to delete item
    del_name(root, item);
}
void bst::del_name(treenode*& loc_ptr, string item) {
    // delete a node based on given county name
    // check if current node is NULL
    if (loc_ptr == 0) {
        cout << "item not in tree\n";
    }
    // if current node's county name is greater then given county name move to left in search space
    else if (loc_ptr->county_name.compare(item) > 0) {
        del_name(loc_ptr->lchild, item);
    }
    // if current node's county name is less then given county name move to right in search space
    else if (loc_ptr->county_name.compare(item) < 0) {
        del_name(loc_ptr->rchild, item);
    }
    else {//delete current node
        treenode* ptr;
        //check if current node have only right child
        if (loc_ptr->lchild == 0) {
            //delete current node and assign right child to current node
            ptr = loc_ptr->rchild;
            delete loc_ptr;
            loc_ptr = ptr;
        }
        //check if current node have only left child
        else if (loc_ptr->rchild == 0) {
            //delete current node and assign left child to current node
            ptr = loc_ptr->lchild;
            delete loc_ptr;
            loc_ptr = ptr;
        }
        // current node have both left and right child
        else {
            // get inorder successor node
            ptr = inorder_succ(loc_ptr);
            //copy successor's data to current node
            loc_ptr->county_name = ptr->county_name;
            loc_ptr->population_size = ptr->population_size;
            //delete successor node
            del_name(loc_ptr->rchild, ptr->county_name);
        }
    }
}
treenode* bst::inorder_succ(treenode* loc_ptr) {
    // get the right node
    treenode* ptr = loc_ptr->rchild;
    // from right node get the left most node that is successor to the given node
    while (ptr->lchild != 0) {
        ptr = ptr->lchild;
    }
    //return the successor node
    return ptr;
}
void bst::print_tree() {
    // print entire tree by calling auxilary function
    print_tree(root);
}
void bst::print_tree(treenode* loc_ptr) {
    if (loc_ptr != 0) {// if current node is not NULL
        // move to left node
        print_tree(loc_ptr->lchild);
        // print current node's data
        cout << loc_ptr->county_name << ", " << loc_ptr->population_size << endl;
        // move to right node
        print_tree(loc_ptr->rchild);
    }
}
void bst::county_ranges(const string& min_name, const string& max_name) {
    // print all county between minimum value and maximum value, inclusive
    print_range(root, min_name, max_name);
}
void bst::print_range(treenode* node, const string& min, const string& max) {
    if (node != 0) {// if current node is not NULL
        // if min is less then current node's county name then move to left node
        if (node->county_name.compare(min) > 0) {
            print_range(node->lchild, min, max);
        }
        //if current node is between min and max value print current node's data
        if (node->county_name.compare(min) >= 0) {
            if (node->county_name.compare(max) <= 0) {
                cout << node->county_name << ", " << node->population_size << endl;
            }
        }
        // move to right node
        // if max is greater then current node's county name then move to right node
        if (node->county_name.compare(max) < 0) {
            print_range(node->rchild, min, max);
        }
    }
}
void bst::sorted_info() {
    // create output file object to write data to file
    ofstream f;
    f.open("county_info.txt");
    // set iterator to root
    treenode* i = root;
    //create a vector object to store sorted data
    vector<string> v;
    createSort(root, v);
    for (int i = 0; i < v.size(); i++) {
        string data = v.at(i);
        f << data << endl;
    }
    //close file object
    f.close();
}
void bst::createSort(treenode* node, vector<string>& v) {
    if (node != 0) {
        createSort(node->lchild, v);
        string str = node->county_name + " ";
        stringstream s;
        s << node->population_size;
        str = str + s.str();
        v.push_back(str);
        createSort(node->rchild, v);
    }
}

