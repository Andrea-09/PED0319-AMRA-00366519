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
    int option = 0;
    
    cout << "Bienvenido a su Pokedex, maestro Pokemon!" << endl;
    do{
        int option = 0;
        int auxEnum = 0;
        cout << "1. Agregar\n";
        cout << "2. Recorrer en In-Order\n";
        cout << "3. Recorrer en Post-Order\n";
        cout << "4. Salir\n";
        cout << "Ingrese su opcion: ";
        cin >> option;
        cin.ignore();
        
        switch(option){
            case 1:
            cout << "Ingrese el nombre de su Pokemon: \n";
            getline(cin, name);
            cout << "Ingrese el tipo (1. fuego, 2.agua, 3. volador, 4. psitico, 5. fantasma: .\n";
            cin >> auxEnum; cin.ignore(); auxEnum--;
            
            insertInTree(&Tree, surname, name, DUI);
            break;
            
            
        }while(option != 4)
    }
    

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
    
    else{
        
    }
