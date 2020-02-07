#include <iostream>
#include <string>
using namespace std;

struct node
{
    string word;
    node *left;
    node *right;
};

node *createLeaf(string word);
void insertInTree(node **pTree, string word);
void preOrder(node *pTree);
void inOrder(node *pTree);
void postOrder(node *pTree);

int main()
{
    node *pTree = NULL;

    insertInTree(&pTree, "Hi");
    insertInTree(&pTree, "Pupas");
    insertInTree(&pTree, "Nel");
    insertInTree(&pTree, "Facil");
    insertInTree(&pTree, "Honey");

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

node *createLeaf(string word)
{
    node *leaf = new node;
    leaf->word = word; //asigna el valor
    leaf->left = NULL;
    leaf->right = NULL;

    return leaf; //retorna el valore de la hoja que acaba de crear
}

void insertInTree(node **pTree, string word)
{
    if (!*pTree)
        *pTree = createLeaf(word);

    else
    {
        if (word.compare((*(*pTree)).word) <= 0)
            insertInTree(&(*(*pTree)).left, word);

        else
            insertInTree(&(*(*pTree)).right, word);
    }
}

void preOrder(node *pTree)
{
    if (!pTree)
        return;
    else
    {
        cout << pTree->word << endl
             << endl;
        preOrder(pTree->left);
        preOrder(pTree->right);
    }
}

void inOrder(node *pTree)
{
    if (!pTree)
        return;
    else
    {
        inOrder(pTree->left);
        cout << pTree->word << endl
             << endl;
        inOrder(pTree->right);
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
        cout << pTree->word << endl
             << endl;
    }
}
