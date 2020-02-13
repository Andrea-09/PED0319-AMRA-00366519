#include <iostream>
#include <string>
using namespace std;

enum type{fire, water, flying, physic, phantom};

struct node{
    string name;
    int KantoPokedex;
    type Types;
    node* left;
    node* right;
};

int main()
{
    node* Tree = NULL;
    
    

    return 0;
}

node* createLeaf (string name, int KantoPokedex, type Types){
    node* leaf = new node;
    leaf->name = name;
    leaf->Types = Types;
    leaf->KantoPokedex = KantoPokedex;
    leaf->left = NULL;
    leaf->right = NULL;

    return leaf;
    
}

void insertInTree(node** Tree, string name int KantoPokedex, type Types){
    
    if(!(*Tree))
        *Tree = createLeaf(name, KantoPokedex, Types);
    
    
    
}
