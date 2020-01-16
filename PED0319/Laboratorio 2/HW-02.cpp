#include <iostream> //Entrada y salida en consola
#include <string> //permite el uso de strings
using namespace std;

//Se declara un registro
struct Person{
    string name;
    int income;
    int age;
    int WorkYears;
};

//Prototipo de la funcion para mostrar la informacion
void printInfo(Person print);
//Prototipo de la funcion que verifica la jubilacion
bool retirement(int age, int work);

//Inicio
int main(void){

//Declara la variable de tipo Person (del registro)
Person ad1;

    cout << "Nombre de la persona: ";
    cin >> ad1.name;
    cout << "Salario: $";
    cin >> ad1.income;
    cout << "Edad: ";
    cin >> ad1.age;
    cout << "Anios Laborales: ";
    cin >> ad1.WorkYears;
    cout << endl;

//Llama la función para mostrar la informacion
    printInfo(ad1);
    
 //Dentro del if se utiliza como condición la funcion que verifica la jubilacion   
    if(retirement(ad1.age, ad1.WorkYears) == true){
        cout << "Esta persona puede jubilarse" << endl;
    }
    else{
        cout << "Esta persona aun no puede jubilarse" << endl;
    }
//Fin del programa
return 0;
}

//Definicion de la funcion que muestra la informacion
void printInfo(Person print){
    cout << "Nombre de la persona:\t" << print.name << endl;
    cout << "Salario: $\t" << print.income << endl;
    cout << "Edad:\t" << print.age << endl;
    cout << "Anios laborales:\t" << print.WorkYears << endl;
}
//Definicion de la funcion que verifica la jubilacion
bool retirement(int age, int work){
    bool flag = false;
        if(age >= 60 && work >= 25){
            return true; //Si la persona tiene 60 años o más y 25 años laborales entonces podrá jubilarse
            }
}   
   



//Edad de jubilacion es de 60 años con 25 años laborales, 