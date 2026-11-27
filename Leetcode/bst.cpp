#include <iostream>
using namespace std;

class Treenode{
    public:
    int root;
    Treenode* left;
    Treenode* right;
    
    public:
    Treenode(){
        root= NULL; Treenode* left =nullptr; Treenode* right= nullptr;
    }
    Treenode(int val){
        root= val; Treenode* left =nullptr; Treenode* right= nullptr;
    }


}

// BINARY SEARCH TREE 
/*
 left<node<right
 rule not only apply for root node but also for subtrees 
 some writers allows duplicates while others not
 generally height of bst is log2N

 */

 // Searching in BST
 Treenode* 