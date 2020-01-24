#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct Products{
    string name;
    float price;
    int stock;
};

int option = 0;

int main()
{
    stack <Products> merchandise;
    Products aux;
    
    do

    {
        cout << "Nombre del producto: "; getline(cin, aux.name);
        cout << endl;
        cout << "Precio: $"; cin >> aux.price;
        cin.ignore();
        cout << "Cantidad en bodega: "; cin >> aux.stock;
        cin.ignore();
        
        merchandise.push(aux);
        
        cout << "Desea agregar mas datos? (1 = si, 0 = no)" << endl;
        cin >> option;
        cin.ignore();
    } while (option != 0);

    aux = merchandise.top();

    cout << "Nombre del producto: " << aux.name << endl;
    cout << "Precio: $" << aux.price << endl;
    cout << "Cantidad en bodega: " << aux.stock << endl;


    return 0;
}
