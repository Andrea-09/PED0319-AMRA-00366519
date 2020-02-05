#include <iostream>
using namespace std;

struct node
{
    int info;
    node *left;
    node *right;
};

void preOrder(node *pTree);
void postOrder(node *pTree);
void inOrder(node *pTree);
node *createLeaf(int info);
void insertInTree(node **tree, int info);

int main()
{
    node *pTree = NULL;
    insertInTree(&pTree, 12);
    insertInTree(&pTree, 22);
    insertInTree(&pTree, 8);
    insertInTree(&pTree, 15);
    insertInTree(&pTree, 1);
    insertInTree(&pTree, 1);
    insertInTree(&pTree, 0);
    insertInTree(&pTree, 27);

    cout << "Imprimiendo en preOrden: " << endl;
    preOrder(pTree);
    cout << endl
         << endl;

    cout << "Imprimiendo en inOrden: " << endl;
    inOrder(pTree);
    cout << endl
         << endl;

    cout << "Imprimiendo en postOrden: " << endl;
    postOrder(pTree);
    cout << endl
         << endl;

    return 0;
}

node *createLeaf(int info)
{
    node *leaf = new node;
    leaf->info = info; //asigna ek valor
    leaf->left = NULL;
    leaf->right = NULL;

    return leaf; //retorna el valore de la hoja que acaba de crear
}

void insertInTree(node **tree, int info)
{ ///doblre puntero lo envia por referencia para modificar el valor
    if (!(*tree))
    {
        *tree = createLeaf(info); //iguala lo que tiene el arbol a la creacion de una hoja
    }
    else
    {
        if (info <= (*(*tree)).info)
        {
            insertInTree(&(*(*tree)).left, info);
        }
        else
        {
            insertInTree(&(*(*tree)).right, info);
        }
    }
}

void preOrder(node *pTree)
{
    if (!pTree)
        return;
    else
    {
        cout << pTree->info << "\t";
        preOrder(pTree->left);
        preOrder(pTree->right);
    }
}

void postOrder(node *pTree)
{
    if (!pTree)
        return;
    else
    {

        postOrder(pTree->left);
        postOrder(pTree->right);
        cout << pTree->info << "\t";
    }
}

void inOrder(node *pTree)
{
    if (!pTree)
        return;
    else
    {

        inOrder(pTree->left);
        cout << pTree->info << "\t";
        inOrder(pTree->right);
    }
}