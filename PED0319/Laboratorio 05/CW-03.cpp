#include <iostream>
#include <string>
using namespace std;

struct node
{
    string content, address;
    float weight;
    node *next;
};
typedef node *st;

void push(st *pST, string content, string address, float weight);
node top(st *pST);
node pop(st *pST);
bool isEmpty(st *pST);

int main()
{
    st pST = NULL;

    int option = 0;
    string content, address;
    float weight;

    do
    {
        cout << "Peso: ";
        cin >> weight;
        cin.ignore();
        cin.ignore();
        cout << "Contenido: ";
        getline(cin, content);
        cout << "Direccion: ";
        getline(cin, address);

        push(&pST, content, address, weight);

        cout << "Desea agregar mas datos? (1 = si, 0 = no)";
        cin >> option;
        cin.ignore();

    } while (option != 0);
    node aux = top(&pST);

    cout << "Peso: ";
    cout << aux.weight << endl;
    cout << "Contenido: ";
    cout << aux.content << endl;
    cout << "Direccion: ";
    cout << aux.address << endl;

    return 0;
}

void push(st *pST, string content, string address, float weight)
{
    node *newNode = new node;
    newNode->address = address;
    newNode->content = content;
    newNode->weight = weight;

    newNode->next = *pST;
    *pST = newNode;
}

node top(st *pST)
{
    node aux;
    if (!(*pST))
    {

        aux.address = "";
        aux.content = "";
        aux.weight = 0;
        aux.next = NULL;
    }
    else
    {
        aux.address = (*pST)->address;
        aux.content = (*pST)->content;
        aux.weight = (*pST)->weight;
        aux.next = NULL;
    }
    return aux;
}

node pop(st *pST)
{
    node aux;
    if (!(*pST))
    {

        aux.address = "";
        aux.content = "";
        aux.weight = 0;
        aux.next = NULL;
    }
    else
    {
        aux.address = (*pST)->address;
        aux.content = (*pST)->content;
        aux.weight = (*pST)->weight;
        aux.next = NULL;

        (*pST) = (*pST)->next;
    }
    return aux;
}

bool isEmpty(st *pST)
{
    return (*pST) = NULL;
}