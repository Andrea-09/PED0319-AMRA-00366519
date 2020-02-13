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
    
}
