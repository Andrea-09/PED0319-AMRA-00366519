#include <iostream>
#include <string>

using namespace std;

struct Address
{
    int houseNumber;
    string city, state;
};

struct personalInfo
{
    string name;
    int age;
    Address pAddress;
};

void printInfo(personalInfo *pI, int size, int pos);

int main(void)
{
    personalInfo *pData;
    int size = 0;

    cout << "Cantidad de datos a ingresar: ";
    cin >> size;

    pData = new personalInfo[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Nombre: ";
        cin >> pData[i].name;
        cout << "Edad: ";
        cin >> (pData + i)->age;
        cout << "No. de casa: ";
        cin >> pData[i].pAddress.houseNumber;
        cout << "Ciudad: ";
        cin >> (pData + i)->pAddress.city;
        cout << "Estado: ";
        cin >> (pData + i)->pAddress.state;
    }

    printInfo(pData, size, 0);

    return 0;
}

void printInfo(personalInfo *pI, int size, int pos)
{

    if (pos == size)
    {
        return;
    }
    else
    {
        printInfo(pI, size, pos + 1);

        cout << "Nombre: ";
        cin >> pI[pos].name;
        cout << "Edad: ";
        cin >> pI[pos].age;
        cout << "No. de casa: ";
        cin >> pI[pos].pAddress.houseNumber;
        cout << "Ciudad: ";
        cin >> pI[pos].pAddress.city;
        cout << "Estado: ";
        cin >> pI[pos].pAddress.state;
    }
}
