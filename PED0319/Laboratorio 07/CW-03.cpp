//EJercicio 2 desde cerp

#include <iostream>
#include <string>
using namespace std;

struct pedido
{
    string remitente, destinatario;
    char tipo, modalidad;
    int peso;
};

struct cola
{
    pedido elemento;
    cola *sig;
};

pedido *queue(cola *c, pedido elemento);

int main()
{
    cola* pInicio = NULL;
    pedido aux;
    int opcion = 0;

    do
    {
        cout << "Remitente: ";
        getline(cin, aux.remitente);
        cout << "Destinatario: ";
        getline(cin, aux.destinatario);
        cout << "Tipo: ";
        cin >> aux.tipo;
        cin.ignore();
        cout << "Modalidad: ";
        cin >> aux.modalidad;
        cin.ignore();
        cout << "Peso: ";
        cin >> aux.peso;
        cin.ignore();

        pInicio = queue(pInicio, aux);

        cout << "Desea ingrear mas pedidos? (1 = si, 2 = no)";
        cin >> opcion;
        cin.ignore();

    } while (opcion != 0);

    cout << "Total por sus pedidos:\t" << calcularTotal(pInicio) << endl;
    cout << "Gracias por usar Correos El Salvador!" << endl;

    return 0;
}

pedido* queue(cola* c, pedido elemento)
{
    cola* nuevo = new cola;
    nuevo->elemento = elemento; ///gurada su info
    nuevo->sig = NULL;          //la cola a punta  a NULL

    if (!c) //Si la cola esta vacia
        c = nuevo;
    else
    {
        cola* aux = c;
        while (aux->sig)
            aux = aux->sig;
        aux->sig = nuevo;
    }
    return c;
}

float calcularTotal(cola *lista)
{
    if (!lista)
        return 0;
    else
    {
        float sub = 0;
        switch (lista->elemento.tipo)
        {
        case 'c':
        case 'C':
            switch (lista->elemento.modalidad)
            {
            case 'u':
            case 'U':
                sub = 3;
                break;

            case 'n':
            case 'N':
                sub = 1;
                break;

            case 'i':
            case 'I':
                sub = 2;
                break;
            }
            break;

        case 'p':
        case 'P':
            switch (lista->elemento.modalidad)
            {
            case 'u':
            case 'U':
                if (lista->elemento.peso <= 500)
                    sub = 10;
                else
                    sub = 15;
                break;

            case 'n':
            case 'N':
                sub = 5;
                break;

            case 'i':
            case 'I':
                if (lista->elemento.peso < 100)
                    sub = 5;
                else
                    sub = 10;
                break;
            }
            break;
        }
        return sub + calcularTotal(lista->sig);
    }
}