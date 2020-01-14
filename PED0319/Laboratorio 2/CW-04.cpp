#include <iostream>
#include <string>
using namespace std;

struct Adress
{
    int houseNumber;
    string city;
    string state;
};
void printInfo(Adress printAd);

int main(void)
{
    Adress ad1;

    cout << "Numero de casa: ";
    cin >> ad1.houseNumber;
    cout << "Ciudad: ";
    cin >> ad1.city;
    cout << "Departamento: ";
    cin >> ad1.state;
    cout << endl;

    printInfo(ad1);

    return 0;
}

void printInfo(Adress printAd)
{
    cout << "No. casa:\t" << printAd.houseNumber << endl;
    cout << "Ciudad:\t" << printAd.city << endl;
    cout << "Departamento:\t" << printAd.state << endl;
}