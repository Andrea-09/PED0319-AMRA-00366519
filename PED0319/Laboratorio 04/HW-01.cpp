#include <iostream> //Entrada y salida en consola
using namespace std;

//Prototipo de funcion de invertir
int reverseNumber(int num, int aux);
int num = 0;

//Inicio
int main(void){

cout << "Ingrese el numero: "; cin >> num;
cout << "El numero invertido es: " << reverseNumber(num, 0) << endl;


    return 0;
}

//Funcion de invertir
int reverseNumber(int num, int aux){
    if(num == 0){
       return aux;
    }
    else{
        return reverseNumber(num / 10, aux * 10 + num % 10);
    }
}
