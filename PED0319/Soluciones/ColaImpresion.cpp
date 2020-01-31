#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct trabajo{
    string usuario;
    string documento;
    int paginas;
    int tiempo;
};
typedef struct trabajo Trabajo;

struct impresora{
    queue <Trabajo> colaImpresion;
    int trabajosRealizados;
    int paginasUtilizadas;
};
typedef struct impresora Impresora;

Impresora epson380;

void agregar();
void consultar();
void imprimir();

int main(){
    epson380.trabajosRealizados = 0;
    epson380.paginasUtilizadas = 0;
    
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\n1) Agregar un trabajo a la cola\n";
        cout << "2) Consultar el estado actual\n";
        cout << "3) Imprimir cola de trabajos\n";
        cout << "4) Salir\n";
        cout << "Opcion elegida: ";
        cin >> opcion; cin.ignore();
        
        switch(opcion){
            case 1: agregar(); break;
            case 2: consultar(); break;
            case 3: imprimir(); break;
            case 4: continuar = false; break;
            default: cout << "Opcion invalida!\n"; break;
        }
    }while(continuar);

    return 0;
}

void agregar(){
    // Solicitar datos del trabajo
    Trabajo unTrabajo;
    cout << "Digite su usuario: "; getline(cin, unTrabajo.usuario);
    cout << "Digite documento: "; getline(cin, unTrabajo.documento);
    cout << "Cantidad de paginas: "; cin >> unTrabajo.paginas; cin.ignore();
    unTrabajo.tiempo = unTrabajo.paginas * 5;
    
    // Agregar a la cola
    epson380.colaImpresion.push(unTrabajo);
    // Modificar contadores
    epson380.trabajosRealizados++;
    epson380.paginasUtilizadas += unTrabajo.paginas;
}

void consultar(){
    cout << "Trabajos actuales en cola: " << epson380.colaImpresion.size() << endl;
    cout << "Trabajos totales: " << epson380.trabajosRealizados << endl;
    cout << "Total paginas utilizadas: " << epson380.paginasUtilizadas << endl;
}

void imprimir(){
    while(!epson380.colaImpresion.empty()){
        // Ver el documento que esta en el frente de la cola
        Trabajo docListoImprimirse = epson380.colaImpresion.front();
        cout << "Imprimiendo el archivo " << docListoImprimirse.documento;
        cout << " consta de " << docListoImprimirse.paginas << " paginas";
        cout << ". Tiempo: " << docListoImprimirse.tiempo << " seg" << endl;
        
        // Sacarlo para que se pueda imprimir el siguiente
        epson380.colaImpresion.pop();
    }
    cout << "Cola de impresion vacia!" << endl;
}

