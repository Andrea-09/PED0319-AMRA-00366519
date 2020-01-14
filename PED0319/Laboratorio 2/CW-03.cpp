#include <iostream>
using namespace std;

//prototipo
void showLetters(char *showArray, int size);

int main(void)
{
    int size = 0;

    cout << "Digite la cantidad de letras: ";
    cin >> size;

    char *array;
    array = new char[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Digite letra: ";
        cin >> array[i];
        //*(array + i) = array[i]
    }

    showLetters(array, size);

    return 0;
}

//definicion
void showLetters(char *showArray, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Letra: " << showArray[i] << endl;
    }
}