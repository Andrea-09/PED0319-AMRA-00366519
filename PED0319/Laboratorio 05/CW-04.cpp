#include <iostream>
using namespace std;

struct node
{
    int n;
    node *next;
};

int main(void)
{

    node *pStart = NULL;
    pStart = push(pStart, 5);
    pStart = push(pStart, 9);
    pStart = push(pStart, 0);
    pStart = push(pStart, 6);

    return 0;
}

node *push(node *pStart, int n)
{
    node *newNode = new node;
    newNode->n = n;

    newNode->next = pStart;
    pStart = newNode;

    return pStart;
}

node *top(node *pStart)
{
    if (!pStart)
    {
        return NULL;
    }
    else
    {
        pStart->next = NULL;
        return pStart;
    }
}

//