//Vector desde cero, agrega un elemento a la lista

#include <iostream>
using namespace std;

// Estructura de la lista
struct node{  //La estructura se llama nodo
    int n;
    node* sig;  //declara un puntero siguiente de tipo nodo, apunta al nodo siguiente
};
//Prototipo para agregar un elemento a la lista
node* agregar(node* pInicio, int n);
//Prototipo para inserta el elemento en desorden en la lista
node* insertarDesorden(node* pInicio, int n);
//Prototipo para buscar en cualquier nodo
int buscarPosicion(node* pInicio, int n);
//Imprime la lista
void imprimir(node* lista);


int main(void){
    // Puntero al inicio de la lista
    node* pInicio = NULL;   //Inicializacion del puntero pInicio que esta al principio de la lista
    
    // Agregando datos a la lista de manera ordenada
    pInicio = agregar(pInicio, 5); //Se llama a la funcion agregar para insertar en el inicio el numero 5 y se guarda en el puntero pInicio
    pInicio = agregar(pInicio, 9);  //Se llama a la funcion agregar para insertar en el inicio el numero 9 y se guarda en el puntero pInicio
    pInicio = agregar(pInicio, 18);  //Se llama a la funcion agregar para insertar en el inicio el numero 18 y se guarda en el puntero pInicio
    pInicio = agregar(pInicio, 21);  //Se llama a la funcion agregar para insertar en el inicio el numero 21 y se guarda en el puntero pInicio

    // Agregando elementos a la lista desordenados
    pInicio = insertarDesorden(pInicio, 2);
    imprimir(pInicio); cout << endl << endl;
    pInicio = insertarDesorden(pInicio, 10);
    imprimir(pInicio); cout << endl << endl;
    pInicio = insertarDesorden(pInicio, 100);
    imprimir(pInicio); cout << endl << endl;
    pInicio = insertarDesorden(pInicio, 10);
    imprimir(pInicio); cout << endl << endl;
    pInicio = insertarDesorden(pInicio, 99);
    imprimir(pInicio); cout << endl << endl;

    return 0;
}

// Impresion recursiva de la lista
void imprimir(node* lista){  //Como no retorna nada es de tipo void
    if(lista){  //Si la lista no esta vacia
        cout << lista->n << "\t";  //mostrar el elemento n al principio de la lista
        imprimir(lista->sig); //Se llama a la funcion y se le dice que va a mostrar los nodos siguientes de la lista
    }
}

// Agregar elementos a la lista (en forma de cola)
node* agregar(node* pInicio, int n){
    node* nuevo = new node;  //Reserva el espacio de memoria y crea un nodo. Se crea un puntero llamado nuevo de tipo nodo
    nuevo->n = n; //nuevo apunta al elemento n y guarda el contenido en n
    nuevo->sig = NULL;  //como no hay nada ahorita el puntero siguiente apunta a NULL

    if(!pInicio) //Si pInicio esta vacio
        pInicio = nuevo; //pInicio es igual a lo que tenga nuevo
    else{  //Si no esta vacio
        node* aux = pInicio;  //Se necesita un puntero auxiliar que es igual a donde apunte pInicio
        
        while(aux->sig) //Mientras el auxiliar apunte a al nodo siguiente
            aux = aux->sig; //El auxiliar va a guardar lo que este en el nodo siguiente

        aux->sig = nuevo; //el puntero siguiente va a guardar lo que hay en un nuevo nodo
    }

    return pInicio;  //La funcion tiene que retornar la lista modificada
}

// Busca la posicion en la cual debe insertarse el elemento en orden ascendente, devuelve el numero de la posicion
int buscarPosicion(node* pInicio, int n){
    node* aux = pInicio;  //El auxiliar de tipo nodo guarda lo que esta en pInicio
    int pos = 0;  //La posicion empieza en 0

    // Recorre la lista y aumenta el valor de pos si el numero acutal es menor, si es mayor no
    while(aux){ //Mientras haya un auxiliar
        if(n > aux->n)  //si n (numero actual) es mayor de lo que esta en el auxiliar
            pos++; //La posicion aumenta 

        // Cambia de posicion en la lista
        aux = aux->sig; //el auxiliar ahora guarda el elemento que estaba en el nodo siguiente
    }
    return pos;  //retorna la posicion modificada
}


// Modifica y añade el elemento pasado por argumento en la lista
node* insertarDesorden(node* pInicio, int n){
    // Posicion en la que se inserta
    int pos = buscarPosicion(pInicio, n);  //llama a la funcion buscarPosicion que se guarda en la posicion en la que se inserta

    // Creacion del nodo a insertar, asignando el numero en su campo de informacion
    node* nuevo = new node;
    nuevo->n = n;  //al nuevo nodo creado se le asigna el elemento en su campo

    // Declaracion de nodos auxiliares, iran con diferencia de un nodo
    node* aux = pInicio; //el primero auxiliar guarda lo que hay en pInicio
    node* aux2 = pInicio; //el segundo auxiliar guarda lo que hay en pInicio

    // Ciclo para llegar hasta la posicion en la que se debe insertar
    for(int i = 0; i < pos; i++){  //recorre toda la posicion
        // En aux2 se guarda el nodo en pos - 1, y en aux el nodo en pos
        aux2 = aux;
        aux = aux->sig;
    }

    // Si el nodo a insertar debe estar al inicio de la lista
    if(pos == 0){
        // El enlace del nuevo nodo a insertar apunta a aux, aux contiene la lista entera
        nuevo->sig = aux;

        // Se hace que aux ahora apunte a nuevo, ya que contiene el nuevo nodo + la lista completa
        aux = nuevo;

        // Se iguala pInicio con aux para que pInicio siempre apunte al inicio de la lista
        pInicio = aux;
    }
    // Si el nodo a insertar debe estar entre dos nodos, o al final de la lista
    else{
        // aux2 al ser el nodo anterior a la posicion donde se debe insertar, su siguiente corresponde al nuevo
        aux2->sig = nuevo;

        // El siguiente del nuevo nodo sera lo restante de la lista, almacenado en aux
        nuevo->sig = aux;
    }

    // Se retorna pInicio para que se almacene la modificacion de la lista
    return pInicio;
}