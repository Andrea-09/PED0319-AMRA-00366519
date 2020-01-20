#include <iostream>
#include <string>

using namespace std;

struct Datos{
    int placa[9];
    string color;
    string marca;
    string tipo;
    float precio;
};

int main(void){
Datos carro;

cout << "Placa: ";
for(int i = 0; i < 9; i++){
    cin >> carro.placa[i];
}
    cout << "Color: ";
    getline(cin, carro.color);
    cout << "Marca: ";
    getline(cin, carro.marca);
    cout << "Tipo: ";
    getline(cin, carro.tipo);
    cout << "Precio: "; cin >> carro.precio;

return 0;

}