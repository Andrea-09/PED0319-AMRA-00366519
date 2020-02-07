#include <iostream>
#include <string>
using namespace std;

struct node{
    string name;
    string surname;
    string DUI;
    node* leftNode;
    node* rightNode;
};

node* createLeaf(string surname, string name, string DUI);
void insertInTree(node** tree, string surname, string name, string DUI);
void preOrder(node* pTree);
void postOrder(node* pTree);
void inOrder(node* pTree);

int main(){
    node* Tree = NULL;
    bool proceed = true;
    string name, surname, DUI;

    do{
        int option = 0;
    
        cout << "\t1. Agregar\n";
        cout << "\t2. Recorrer\n";
        cout << "\t3. Salir\n";
        cout << "Su opcion: ";
        cin >> option;
        cin.ignore();
        switch (option)
        {
        case 1:
            cout << "Ingrese un nombre: \n";
            getline(cin, name);
            cout << "Ingrese el apellido: .\n";
            getline(cin, surname);
            cout << "Ingrese el DUI: \n";
            getline(cin, DUI);
            insertInTree(&Tree, surname, name, DUI);
            break;
        case 2:
            cout << "Recorrido Pre-Orden: \n";
            preOrder(Tree);
            cout << endl << endl;

            cout << "Recorrido In-Orden: \n";
            inOrder(Tree);
            cout << endl << endl;

            cout << "Recorrido Post-Order: \n";
            postOrder(Tree);
            cout << endl << endl;
            break;
        case 3:
            proceed = false;
            break;
        default:
        cout << "Opcion invalida" << endl;
            break;
        }
    }while(proceed);

    
    return 0;
}

node* createLeaf(string surname, string name, string DUI){
    node* leaf = new node;
    leaf->name = name;
    leaf->surname = surname;
    leaf->DUI = DUI;
    leaf->leftNode = NULL;
    leaf->rightNode = NULL;

    return leaf;
}

void insertInTree(node** tree, string surname, string name, string DUI){
    if(!(*tree)){
        *tree = createLeaf(surname, name, DUI);
    }
    else{
        if(name.compare((*tree)->name) <= 0){
            insertInTree(&((*tree)->leftNode), surname, name, DUI);
        }
        else if(surname.compare((*tree)->surname) == 0){
            if(name.compare((*tree)->name) <= 0){
                insertInTree(&((*tree)->leftNode), surname, name, DUI);
            }
            else{
                insertInTree(&((*tree)->rightNode), surname, name, DUI);
            }
        }
        else{
            insertInTree(&((*tree)->rightNode), surname, name, DUI);
        }
    }
}

void preOrder(node* pTree){
    if(!pTree){
        return;
    }
    else{
        cout << pTree->name << ", " << pTree->surname << ", " << pTree->DUI << "\n";
        preOrder(pTree->leftNode);
        preOrder(pTree->rightNode);
    }
}

void postOrder(node* pTree){
    if(!pTree){
        return;
    }
    else{
        postOrder(pTree->leftNode);
        postOrder(pTree->rightNode);
        cout << pTree->name << ", " << pTree->surname << ", " << pTree->DUI << "\n";
    }
}

void inOrder(node* pTree){
    if(!pTree){
        return;
    }
    else{
        inOrder(pTree->leftNode);
        cout << pTree->name << ", " << pTree->surname << ", " << pTree->DUI << "\n";
        inOrder(pTree->rightNode);
    }
}