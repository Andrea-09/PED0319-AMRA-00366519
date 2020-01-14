#include <iostream> //Entrada y salida de valores
#include <cctype> //Permite usar las funciones isalnum, isalpha, isdigit
#include <stdio.h> //Permite usar las funciones
using namespace std;

//No vimos banderas durante Fundamentos

//Prototipo de la funcion
int isAlpha(string word);
//Variable Global
string word;

//Inicio
int main(){
    
    isAlpha(word);
  
    return 0;
}

//Definicion de la funcion
int isAlpha(string word){
    cout << "Ingrese una palabra: ";
    cin >> word;
    
    for(int i = 0; i < word.length(); i++){
    if(isalpha(word[i])){
        cout << "-1";
        break;
    }
    else if(isdigit(word[i])){
            cout << "0";
            break;
            }
        else(isalnum(word[i]));{
            cout << "1";
            break;
        }
    }
}
