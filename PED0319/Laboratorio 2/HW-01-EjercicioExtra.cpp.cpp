#include <iostream> //Entrada y salida en consola
#include <string> //Permite el uso de los strings
using namespace std;

//Se declara el registro
struct Clients{
    string FullName;
};

//Inicio
int main(void){
cout << "Cocoa's Factory" <<endl;
    
    Clients* array;
    int size;

    cout << "Digite la cantidad de clientes: ";
    cin >> size;
    //Espacio de memoria
    array = new Clients[size];

    //Almacena los nombres en la cantidad que el usuario digite
    for (int i = 0; i < size; i++)
    {
        cout << "Nombre del cliente:\t";
        cin >> (array + i)->FullName;
        cin.ignore();
    }

    return 0;
}

