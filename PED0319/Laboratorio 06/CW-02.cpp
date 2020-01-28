#include <iostream>
#include <string>
#include <cctype>
using namespace std;

struct node
{
    string product;
    float price;
    node *next;
};

string convertString(string product);
void printMenu(void);
node *addElement(node *list, string product, float price);
int searchStock(node *list, string product);

int main(void)
{
    int option = 0;
    string product = "";
    int auxStock = 0;
    float price = 0;
    node *list;

    do
    {
        printMenu();
        cin >> option;
        cin.ignore();
        switch (option)
        {
        case 1:
            cout << "Ingrese los datos del producto" << endl;
            cout << "Nombre:";
            cin >> product;
            cout << "Precio:";
            cin >> price;
            product = convertString(product);
            list = addElement(list, product, price);

            break;
        case 2:
            cout << "Ingrese el producto a buscar: " << endl;
            cout << "Producto: ";
            cin >> product;
            product = convertString(product);

            auxStock = searchStock(list, product);

            (auxStock == 0) ? cout << "Sin stock" : cout << "Cantidad en stock:\t" << auxStock;

            break;
        case 3:
            cout << "Saliendo..." << endl;
            break;
        }
        while (option != 3);
        return 0;
    }
}

//ESTO ES POR SI TOUPPER NO SIRVE
string convertString(string product)
{
    string aux = "";
    for (int i = 0; i < product.length; i++)
    {
        aux += toupper(product[i]);
        return aux;
    }
}

void printMenu(void)
{
    int option;
    cout << "***MENU PRINCIPAL***" << endl;
    cout << "1. Ingresar datos\t" << endl;
    cout << "2. BUscar en stock\t" << endl;
    cout << "3. Salir\t" << endl;
    cin >> option;
}

node *addELement(node *list, string product, float price)
{
    node *newNode = new node;
    newNode->price = price;
    newNode->product = product;
    newNode->next = NULL;

    if (!list)
        list = newNode;
    else
    {
        node *aux = list;

        while (aux->next != NULL)
            aux = aux->next;
    }

    return list;
}

int searchStock(node *list, string product)
{
    if (!list)
        return 0;
    else
    {
        if (product.compare(list->product) == 0)
            return 1 + searchStock(list->next, product);

        else
        {
            return 0 + searchStock(list->next, product);
        }
    }