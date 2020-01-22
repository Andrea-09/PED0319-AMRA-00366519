#include <iostream>
#include <string>
using namespace std;

struct Electrodomestics{
    string type;
    float price, storePrice;
};
int theSize = 0;
void fillArray(Electrodomestics *array, int theSize, int aux);
void printArray(Electrodomestics *array, int theSize, int aux);
int addStorePrices(Electrodomestics *array, int theSize, int aux);

int main(void){

    cout << "Ingrese la cantidad de productos a almacenar: "; cin >> theSize;
    cin.ignore();
    Electrodomestics *products;
    products = new Electrodomestics[theSize];

    fillArray(products, theSize, 0);
    printArray(products, theSize, 0);

    return 0;

}

void fillArray(Electrodomestics *array, int theSize, int aux){
    if(theSize == aux){
        return;
    }
    else{
        cout << "Nombre del electrodomestico: ";
        getline(cin, array[aux].type);
        cout << "Costo: "; cin >> array[aux].price; 
        cin.ignore();
        cout << "Precio de venta: "; cin >> array[aux].storePrice; 
        cin.ignore();

        fillArray(array, theSize, aux + 1);
    }
}

void printArray(Electrodomestics *array, int theSize, int aux){
    if(theSize == aux){
        return;
    }
    else{
        cout << "Nombre del electrodomestico: " << array[aux].type;
        cin.ignore();
        cout << "Costo: " << array[aux].price;
        cin.ignore();
        cout << "Precio de venta: " << array[aux].storePrice;

        printArray(array, theSize, aux + 1);
        addStorePrices(array, theSize, aux +1);
    }
}

float addStorePrices(Electrodomestics *array, int theSize, int aux, bool flag){
   
    if(aux == theSize){
        return 0;
    }
    else{
        if(flag == true)
            return array[aux].price + addStorePrices(array, theSize, aux + 1, flag);
        else
              return array[aux].storePrice + addStorePrices(array, theSize, aux + 1, flag);
    }
}
