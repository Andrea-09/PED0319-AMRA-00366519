#include <iostream>
#include <string>
using namespace std;

enum tipo{fuego, agua, veneno, na};

struct pokemon{
    string nombre;
    int indice;
    tipo pTipo1, pTipo2;
};

struct nodo{
    pokemon info;
    nodo *left, *right;
};

void inOrder(nodo* tree);
string enumToString(tipo aux);
nodo* createLeaf(pokemon pk);
void insertTree(nodo** tree, pokemon pk);

int main(void){
    nodo* pInicio = NULL;
    pokemon insertar;

    char t1, t2, opcion;
    int opcion2 = 0;

    do{
    cout << "Nombre: "; cin >>  insertar.nombre;
    cout << "Indice: "; cin >> insertar.indice;

    cout << "Tipo: "; cin >> t1;
        switch(t1){
            case 'f':
            case 'F':
                insertar.pTipo1 = fuego;
            break;
            case 'a':
            case 'A':
                insertar.pTipo1 = agua;
            break;
            case 'v':
            case 'V':
                insertar.pTipo1 = veneno;
            break;

        }

    cout << "Tiene otro tipo? S/N\t"; cin >> opcion;

        if(opcion == 's' || opcion == 'S'){
            cout << "Tipo: "; cin >> t2;
            switch(t2){
                case 'f':
                case 'F':
                    insertar.pTipo2 = fuego;
                break;
                case 'a':
                case 'A':
                    insertar.pTipo2 = agua;
                break;
                case 'v':
                case 'V':
                    insertar.pTipo2 = veneno;
                break;
            }
        }
        else{
            insertar.pTipo2 = na;
        }
        cout << "Desea agregar otro? \n1. Si\n0. No\t"; cin >> opcion2;
        cin.ignore();

    insertTree(&pInicio, insertar);
    }while(opcion2 != 0);

    inOrder(pInicio);

    return 0;
}

nodo* createLeaf(pokemon pk){
    nodo* leaf = new nodo;

    leaf->info = pk;
    leaf->left = NULL;
    leaf->right = NULL;

    return leaf;
}

void insertTree(nodo** tree, pokemon pk){
    if(!(*tree))
        *tree = createLeaf(pk);
    else{
        if((*(*tree)).info.indice <= pk.indice)
            insertTree(&(*(*tree)).left, pk);
        else
            insertTree(&(*(*tree)).right, pk);
    }
}

void inOrder(nodo* tree){
    if(!tree)
        return;
    else{
        inOrder(tree->left);
        cout << "Nombre: " << tree->info.nombre << "\t";
        cout << "Indice: " << tree->info.indice << "\t";
        cout << "Tipo: " << enumToString(tree->info.pTipo1) << "\n";
        cout << "Tipo: " << enumToString(tree->info.pTipo2) << "\n";
        inOrder(tree->right);
    }
}

string enumToString(tipo aux){
    switch(aux){
        case veneno:
            return "Veneno";
        case fuego:
            return "Fuego";
        case agua:
            return "Agua";
        case na:
            return "Sin tipo";
    }
}

void preOrder(nodo* tree){
    if(!tree)
        return;
    else{
        if(tree->info.pTipo1 == veneno || tree->info.pTipo2 == veneno){
            cout << "Nombre: " << tree->info.nombre << "\t";
            cout << "Indice: " << tree->info.indice << "\t";
            cout << "Tipo: " << enumToString(tree->info.pTipo1) << "\n";
            cout << "Tipo: " << enumToString(tree->info.pTipo2) << "\n";
        }
        preOrder(tree->left);
        preOrder(tree->right);
    }
}