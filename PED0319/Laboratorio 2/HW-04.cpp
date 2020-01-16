#include <iostream> //Entrada y salida en consola
#include <cmath> //Permite usar operaciones matematicas
using namespace std;

//Variables globales
float a, b, c, x1, x2, discriminant, realPart, imaginaryPart;
//Prototipo de la funcion
void showResults(float discriminant);

//Inicio
int main() {
    
    cout << "Ingrese los coeficientes a, b and c: ";
    cin >> a >> b >> c;
    //Como la formula es muy grande, se trabaja por separado
    //El numero descriminante es lo que se encuntra dentro de la raíz
    discriminant = b*b - 4*a*c;
    
    //Llama la funcion
    showResults(discriminant);
    
    return 0;
}

//Definicion de la funcion que muestra los resultados
void showResults(float discriminant){   
    //Si el descriminante es mayor que 0 entonces mostrara si las raices son reales y diferentes
if (discriminant > 0) {  
        x1 = (-b + sqrt(discriminant)) / (2*a);
        x2 = (-b - sqrt(discriminant)) / (2*a);
        cout << "Las raices son reales y diferentes." << endl;
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }
    //Si el descriminante es igual a 0 entonces mostrara si las raices son reales e iguales
    else if (discriminant == 0) {
        cout << "Las raices son iguales y reales." << endl;
        x1 = (-b + sqrt(discriminant)) / (2*a);
        cout << "x1 = x2 =" << x1 << endl;
    }
    //Si no son reales, ni iguales, entonces mostrará si son de numeros complejos
    else {
        realPart = -b/(2*a);
        imaginaryPart =sqrt(-discriminant)/(2*a);
        cout << "Las raices son complejas y diferentes"  << endl;
        cout << "x1 = " << realPart << "+" << imaginaryPart << "i" << endl;
        cout << "x2 = " << realPart << "-" << imaginaryPart << "i" << endl;
        }
    }