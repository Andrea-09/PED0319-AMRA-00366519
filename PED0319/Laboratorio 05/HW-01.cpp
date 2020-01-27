#include <iostream> //Muestra entrada y salida en consola
#include <string>  //Permite el uso de strings
#include <stack>   //Libreria para pilas
using namespace std;

//Registro
struct Products{
    string name;
    float price;
    int stock;
};

int option = 0;

//Inicio
int main()
{
    stack <Products> merchandise;  //se declara una variable llamada merchandise de tipo products en la pila
    Products aux;
    
    do

    {
        cout << "Nombre del producto: "; getline(cin, aux.name);
        cout << endl;
        cout << "Precio: $"; cin >> aux.price;
        cin.ignore();
        cout << "Cantidad en bodega: "; cin >> aux.stock;
        cin.ignore();
        
        merchandise.push(aux);   //Ingresa los datos en la pila
        
        cout << "Desea agregar mas datos? (1 = si, 0 = no)" << endl;
        cin >> option;
        cin.ignore();
    } while (option != 0);

    aux = merchandise.top();  //Muestra los datos de la pila pero no los destruye

    cout << "Nombre del producto: " << aux.name << endl;
    cout << "Precio: $" << aux.price << endl;
    cout << "Cantidad en bodega: " << aux.stock << endl;


    return 0;
}
