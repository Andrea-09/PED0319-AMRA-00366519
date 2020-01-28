#include <iostream>
using namespace std;

struct node
{
    int number;
    node *next;
};

int main(void)
{
    node *pStart = NULL; //apunta al inicio de la lista
    pStart = addStack(pStart, 8);
    pStart = addStack(pStart, 5);

    return 0;
}

//Como si fuera pila
node *addStack(node *list, int n)
{
    node *newNode = new node; //CRea un nuevo nodo aka reserva espacio de memoria
    newNode->number = n;      ///guarda la informacion

    newNode->next = list; //Agraga a la lista
    list = newNode;       //ES el primero que existe

    return list; //retorna la lista modficada
}

//Como si fuera cola
node *addQueue(node *list, int n)
{
    node *newNode = new node;
    newNode->number = n;

    if (!list)
    {
        list = newNode; //ES el primero que existe
    }
    else
    {
        node *aux = list;

        while (!aux->next)
            aux = aux->next;

        aux->next = newNode
    }
    return list;
}

//freaking recursion
void printElements(node *list)
{
    if (!list)
        return;
    else
    {
        cout << list->number << endl;
        printElements(list->next); //llamada recursiva y le manda lista siguiente
    }
}

//recursiom
int countNumbers(node *list, int n)
{
    if (!list)
        return 0;
    else
    {
        if (list->number == n)
        {
            return 1 + countNumbers(list->number, n);
        }
        else
            return 0 + countNumbers(list->number, n);
    }
}