//Pre parcial 1 ejercicio con libreria

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

enum genre
{
    pop,
    rock,
    clasical,
    ballad
};
enum playlist
{
    triste,
    feliz,
    dormir
};
struct songs
{
    string tittle, artists;
    genre gen;
    int time;
};
typedef songs T;

//Prototipo
void printMenu(void);

int main(void)
{

    vector<T> lista;
    queue<T> triste, feliz, dormir;
    T aux;
    int option, auxENum = 0;

    do
    {
        printMenu();
        cin >> option;
        cin.ignore();
        switch (option)
        {
        case 1:
            cout << "Titulo de la cancion";
            getline(cin, aux.tittle);
            cout << "Artista";
            getline(cin, aux.artists);
            cout << "Genero (1 - pop, 2 - rock, 3 - clasical, 4 - ballad)";
            cin >> auxENum;
            cin.ignore();
            auxENum--;
            aux.gen = genre(auxENum);
            aux.time = 0;

            do
            {
                cout << "Duracion";
                cin >> aux.time;
                cin.ignore();
            } while (aux.time <= 0);
            lista.push_back(aux);
            break;

        case 2:
            cout << "CAncion a eliminar. \t";
            getline(cin, tit);
            for (auto iter = lista.begin(); iter != lista.end(); ++iter)
            {
                if (iter->tittle.compare(tit))
                    iter = lista.erase(iter);
                else
                    iter++;
            }

            break;

        case 3:
            for (T element : lista)
            {
                cout << element.artists << endl;
                cout << element.tittle << endl;
                cout << element.time << endl;

                switch (element.gen)
                {
                case pop:
                    cout << "Pop" << endl;
                    break;

                case rock:
                    cout << "Rock" << endl;
                    break;

                case clasical:
                    cout << "Clasical" << endl;
                    break;

                case ballad:
                    cout << "Ballad" << endl;
                    break;
                }
            }
            break;

        case 4:
            cout << "Cancion a buscar. \t";
            getline(cin, tit);
            cout << "Agregar en (1- triste, 2 - feliz, 3 - dormir)";
            cin >> auxENum;
            cin.ignore();
            switch (auxENum)
            {
            case 1:
                searchElement(lista, &triste, tit);
            }

            break;
        }
        while (option != 5)
            ;
    }

    void printMenu(void)
    {
        cout << "1.t\Agregar cancion" << endl;
        cout << "2.t\Eliminar cancion" << endl;
        cout << "3.t\Mostrar cancion" << endl;
        cout << "4.t\Buscar cancion" << endl;
        cout << "5.t\Salir" << endl;
    }

    void searchElement(vector<T> songs, queue<T> * cola, string tit)
    {
        for (T element : songs)
        {
            if (element.tittle.compare(tit) == 0)
            {
                cout << "Cancion encontrada" << endl;
                (*cola).push(element);
                return;
            }
        }
    }