#include <iostream> //Entrada y salida en consola
using namespace std;

//Prototipo de funcion
int fib(int number);

//Inicio
int main() {
   int number , aux=0;
   cout << "Ingrese el numero de terminos de la : ";
   cin >> number;
   cout << "\nSerie Fibonacci : ";
   while(aux < number) {
      cout << " " << fib(aux);   //Mientras que el aux sea menor que el numero ingresado, se llama a la funcion recursiva
      aux++;                    //El aux aumenta segun el numero de terminos
   }
   return 0;
}

//Funcion recursiva fibonacci
int fib(int number) {
   if((number == 1)||(number == 0)) {   //Caso base, si el numero es 1 o 0 retorna el numero
      return(number);
   }else {
      return(fib(number - 1) + fib(number - 2));    //Caso recursivo
   }
}