#include <iostream> //Entrada y salida de datos
#include <cstdlib> //Se necesita para usar la funcion rand
#include <time.h> //Se necesita para usar la funcion rand
using namespace std;


//Prototipo de la funcion de arreglo de numeros aleatorios
int showRandArray(int arr[15], int size);
//Prototipo de la funcion para mostrar los multiplos de 7
void showMultiples(int arr[15]);
//Prototipo de la funcion de suma de los multiplos de 7
void showSum(int arr[15]);

// Declara variables globales
int size = 15;
int arr[15];

//Inicio del programa
int main(){
    showRandArray(arr, size);
    cout<<endl;

    showMultiples(arr);
    cout<<endl;

    showSum(arr);
    cout<<endl;

    return 0;
}

//Definicion de la funcion de arreglo
int showRandArray(int arr[15], int size){
    cout << "Los elementos del arreglo son: "<<endl;
    for(int i = 0; i < size; i++){
        arr[i] = 1 + rand() % 75;
        cout << arr[i] <<endl;
    }

}

//Definicion de la funcion de multiplos
void showMultiples(int arr[15]){
    cout << "Los multiplos de 7 del arreglo son: " <<endl;
    for(int i = 0; i < 15; i++){
        if( arr[i] % 7 == 0 ){
            cout << arr[i] << " ";
            }
        }
    }

//Definicion de la funcion de suma
void showSum(int arr[15]){
    int suma = 0;
    for(int i = 0; i < 15; i++){
        if(arr[i] % 7 == 0){
            suma += arr[i];
        }
         }
    cout<<"La suma de los multiplos de 7 del arreglo es: " << suma <<endl;
}
