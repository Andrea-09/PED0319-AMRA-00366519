#include <iostream>
#include <string>
using namespace std;

#include <iostream>
using namespace std;

void argumentByReference(char *v, char c1, char c2){
    //Prototipo funcion de remplazo por referencia
    int tamano = 20;
    for (int i=0; v[i] < tamano; i++){
        if (*(v+i)==c1){
            *(v+i)=c2;
        }
    }

}

int main (){
    string word = "";
    char letterA, letterB;
   
    cout << "Ingrese palabra: " << word <<endl;
   
    cout << "Ingrese caracter a reemplazar: " << letterA <<endl;
    
    cout << "Ingrese nuevo caracter: "<< letterB << endl;
    argumentByReference(&word);
 
    cout << "Resultado: "<< &word <<endl;

    return 0;
}