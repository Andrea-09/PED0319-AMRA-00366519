#include <iostream> //Entrada y salida de datos
using namespace std;

//Prototipo de la funcion que verifica si es primo y luego suma las cantidades
int prime(int n);

//Inicio
 int main(void)
{
	int n;
	cout << "Ingrese el valor maximo: "; //El usuario puede ingrese el valor maximo de los numeros
	//En el caso del ejercicio, el usuario debera ingresar un cien
	cin >> n;
	cout << "La suma es: " << prime(n);

	return 0;
}
//Definicion de la funcion
int prime(int n)
{
	int num = 0;
	bool prime; //Verifica si el numero es primo o no
	for(int i = 2; i <= n; i++)
	{
		prime = true;
		for(int j = 2; j < i; j++)
		{
			if(i % j == 0)
			{
				prime = false;
				break;
			}
		}
		if(prime)
		{
			num += i; //Si el numero es primo entonces suma las cantidades
		}
	}
	return num; //Retorna la suma
}