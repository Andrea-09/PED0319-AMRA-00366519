#include <iostream>
#include <string>
using namespace std;

void palabraInvertida(string word, int pos);

int main(void){

 string word;
 
cout << "Ingrese una palabra: "; cin >> word;
cout << "Palabra invertida: ";
palabraInvertida(word, 0);
cout << endl;

    return 0;
}

void palabraInvertida(string word, int pos){
    if(pos == word.length()){
        return;
    }
    else{
        palabraInvertida(word, pos + 1);
        cout << word[pos];
    }
}