#include <iostream>
#include <cmath>
using namespace std;

struct monomio
{
    float coef, exp;
};

float fillArray(monomio *array, int size, int aux);

int main(void)
{

    int size = 0;
    monomio *array;
    cout << "Ingrese el tamano: ";
    cin >> size;

    array = new monomio[size];

    for (int i = 0; i < size; i++)
    {
        cin >> array[i].coef >> array[i].exp;
    }

    cout << fillArray(array, size, 0);

    return 0;
}

float fillArray(monomio *array, int size, int aux)
{
    if (aux == size)
    {
        return 0;
    }
    else
    {
        return pow(array[aux].coef, array[aux].exp) + fillArray(array, size, aux + 1);
    }
}