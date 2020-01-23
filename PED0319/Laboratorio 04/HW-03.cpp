#include <iostream> //Entrada y salida en consola
#include <string>  //Permite el uso de strings
using namespace std;

//Declaracion de estructuras
struct Electrodomestics{
    string type;
    float price, storePrice;
};

//Variables globales
int theSize = 0;
bool flag = false;
int op;

//Prototipo de funcion para ingresar los datos
void fillArray(Electrodomestics *array, int theSize, int aux);
//Prototipo de funcion para mostrar los datos
void printArray(Electrodomestics *array, int theSize, int aux);
//Prototipo de funcion para la suma de los precios
float addStorePrices(Electrodomestics *array, int theSize, int aux, bool flag);

//Inicio
int main(void){

    cout << "Ingrese la cantidad de productos a almacenar: "; cin >> theSize;
    cin.ignore();
    Electrodomestics *products;
    products = new Electrodomestics[theSize];

    fillArray(products, theSize, 0);
    printArray(products, theSize, 0);

    cout << "Digite 1 para sumar los costos o digite 2 para sumar el precio de ventas" << endl;
    cin >> op;

    if(op == 1){
        flag = true;
        cout << "La suma del costo es de: $" << addStorePrices(products, theSize, 0, flag) << endl;  //Llama a la funcion recursiva
    }
    else{
        flag = false;
        cout << "La suma del precio de venta es: $" << addStorePrices(products, theSize, 0, flag) << endl; //Lama a la funcion recursiva
    }

    return 0;

}

//Definicion de funcion para llenar el arreglo
void fillArray(Electrodomestics *array, int theSize, int aux){
    if(theSize == aux){
        return;
    }
    else{
        cout << "Nombre del electrodomestico: ";
        getline(cin, array[aux].type);
        cout << "Costo: $"; cin >> array[aux].price; 
        cin.ignore();
        cout << "Precio de venta: $"; cin >> array[aux].storePrice; 
        cin.ignore();

        fillArray(array, theSize, aux + 1); //El auxiliar aumenta en 1 hasta llenar el tamaño del arreglo
    }
}

//Funcion para mostrar el arreglo
void printArray(Electrodomestics *array, int theSize, int aux){
    if(theSize == aux){ 
        return;
    }
    else{
        cout << "Nombre del electrodomestico: " << array[aux].type;
        cin.ignore();
        cout << "Costo: $" << array[aux].price;
        cin.ignore();
        cout << "Precio de venta: $" << array[aux].storePrice;
        cin.ignore();

        printArray(array, theSize, aux + 1);    //El auxiliar aumenta en 1 hasta mostrar todo el tamaño del arreglo
        
    }
}

//Funcion para sumar los costos y el precio de venta
float addStorePrices(Electrodomestics *array, int theSize, int aux, bool flag){
    if(aux == theSize){   //El caso base es que el auxiliar sea igual que el tamaño
        return 0;
    }
    else{
        if(flag == true)                  //Si la bandera es true suma los costos
            return array[aux].price + addStorePrices(array, theSize, aux + 1, flag);
        else
              return array[aux].storePrice + addStorePrices(array, theSize, aux + 1, flag);   //Caso contrario suma los precios de venta
    }
}
