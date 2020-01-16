#include <iostream>
using namespace std;

int main(void)
{
    float array[20];

    for (int i = 0; i < 20; i++)
    {
        cout << "Digite la nota: ";
        cin >> array[i];
    }
    for (int i = 0; i < 20; i++)
    {
        cout << "Nota: " << (i + 1) << "\t";
    }
    return 0;
}