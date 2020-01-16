#include <iostream> //Entrada y salida en consola
#include <cmath> //Permite usar operaciones matematicas
#include <string> //Permite el uso de strings
using namespace std;

//Declaracion del registro
struct Salesman
{
    int DUI;
    string Name;
    int YearHired;
    float MensualSalary;
};

//Prototipo de funcion de conversion
float YeartoMonths(array[i].YearHired);
//Prototipo de funcion de salario devengado
float accruedIncome(array[i].MensualSalary, int months);

//Inicio
int main(void)
{
    Salesman *array;
    int size;

    cout << "Digite la cantidad de empleados: ";
    cin >> size;
    //Espacio de memoria
    array = new Salesman[size];

    //Recorre el tamaño que el usuario haya digitado como cantidad de empleados
    for (int i = 0; i < size; i++)
    {
        
        cout << "Numero de DUI: ";
        cin >> array[i].DUI;
        cout << "Nombre completo: ";
        cin >> array[i].Name;
        getline(cin, array[i].Name);
        cout << "Año en el que fue contratado: ";
        cin >> array[i].YearHired;
        cout << "Salario mensual: $";
        cin >> array[i].MensualSalary;

cout << endl;
    }
    
    //Llama a la funcion 
    YeartoMonths(YearHired);
    accruedIncome(MensualSalary, months);
    

    return 0;
}

//Funcion de conversion
float YeartoMonths(array[i].YearHired){
	for(int i = 0; i < array[i].YearHired; i++){
  int months = array[i].YearHired * 12;             //Recorre los años del arreglo y los multiplica por 12 para obtener los meses de trabajo
  }
}

//Funcion de salario devengado   
float accruedIncome(array[i].MensualSalary, int months){
	for(int i = 0; i < array[i].MensualSalary; i++){
  	float Income = array[i].MensualSalary * YeartoMonths;            //Calcula el salario devengado
    cout << "El salario devengado es: ";
    cin >> Income;
  }
}