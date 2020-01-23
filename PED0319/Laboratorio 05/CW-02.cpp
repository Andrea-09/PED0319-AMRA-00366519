#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct boxes
{
    float weight;
    string content, address;
};

int main()
{
    int option = 0;
    stack<boxes> st;
    boxes aux;

    do
    {
        cout << "Peso: ";
        cin >> aux.weight;
        cin.ignore();
        cout << "Contenido: ";
        getline(cin, aux.content);
        cout << "Direccion: ";
        getline(cin, aux.address);

        st.push(aux);

        cout << "Desea agregar mas datos? (1 = si, 0 = no)";
        cin >> option;
        cin.ignore();

    } while (option != 0);

    aux = st.top();
    cout << "Peso: " << aux.weight;
    cout << "Contenido: " << aux.content;
    cout << "Direccion: " << aux.address;

    return 0;
}