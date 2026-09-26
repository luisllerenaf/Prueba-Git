#include <iostream>
using namespace std;

struct Empleado{

    string nombre;
    int codigo;
};

struct Nodo {
    Empleado info;
    Nodo* sig;
};

Nodo* crearNodo(Empleado valor) {
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->info.nombre = valor.nombre;
    nuevoNodo->info.codigo = valor.codigo;
    nuevoNodo->sig = NULL;
    return nuevoNodo;
}

// Imprimir una lista enlazada simple
void imprimirLista(Nodo* inicio) {
    Nodo* actual = inicio;
    while (actual != NULL) {
        cout << actual->info.codigo << " ";
        cout << actual->info.nombre << " ";
        actual = actual->sig;
    }
    cout << endl;
}

Nodo* insertarOrdenado(Nodo* inicio, Empleado valor) {

    Nodo* nuevoNodo = crearNodo(valor);

    // Caso especial: lista vacia o el valor va primero
    if (inicio == NULL || valor.codigo < inicio->info.codigo) {

        nuevoNodo->sig = inicio;
        return nuevoNodo;
    }

    Nodo* actual = inicio;
    
    while (actual->sig != NULL && actual->sig->info.codigo < valor.codigo) {
        actual = actual->sig;
    }

    nuevoNodo->sig = actual->sig;
    actual->sig = nuevoNodo;
    return inicio;
}

Nodo* buscarElemento(Nodo* inicio, int valor) {
    
    Nodo* actual = inicio;
    
    while (actual != NULL) {

        if (actual->info.codigo == valor) {
        return actual; // devuelve el nodo que contiene el valor
        }
        actual = actual->sig;
    }
    return NULL; // no se encontro
}

Nodo* eliminarNodo(Nodo* inicio, int valor) {
    if (inicio == NULL) {
    return NULL; // lista vacia
    }

    if (inicio->info.codigo == valor) { // el valor esta en el primer nodo
        Nodo* temp = inicio;
        inicio = inicio->sig;
        delete temp;
        return inicio;
    }

    Nodo* actual = inicio;
    while (actual->sig != NULL) {
        if (actual->sig->info.codigo == valor) {
        Nodo* temp = actual->sig;
            actual->sig = actual->sig->sig;
            delete temp;
            return inicio;
        }
        actual = actual->sig;
    }
    return inicio; // valor no encontrado
}

int main(){

    string menu [150] = {
        "Elija una opcion:",
        "1.Insertar Empleados a la lista",
        "2.Mostrar Empleado",
        "3.Eiminar Empleado",
        "4.Mostrar Todos los Empleados",
        "5.Salir"
    };

    Nodo* lista;
    Nodo* nodoAuxiliar;
    Empleado aux;
    bool siga = true;
    int opcion;
    while(siga == true){

        cout<<menu<<endl;
        cin>>opcion;

        switch (opcion){

            case 1:
                //Pide datos del nuevo Empleado a ingresar
                cout<<"Ingrese el codigo del Empleado";
                cin>>aux.codigo;
                cout<<"Ingrese el nombre del Empleado";
                cin>>aux.nombre;

                //carga el nuevo Empleado a ingresar
                insertarOrdenado(lista,aux);                
                break;
            case 2:
                //Pide codigo a buscar
                cout<< "Ingrese el codigo del empleado";
                int codigoBuscado;
                cin>> codigoBuscado;

                //Guarda el nodo buscado de la lista
                nodoAuxiliar = buscarElemento(lista,codigoBuscado);

                cout<<"Nombre: "<<nodoAuxiliar->info.nombre;
                break;
            case 3:
                //Pide codigo a eliminar
                cout<< "Ingrese el codigo del empleado";
                int codigoBuscado;
                cin>> codigoBuscado;

                //Guarda el nodo a eliminar de la lista
                nodoAuxiliar = eliminarNodo(lista, codigoBuscado);

                cout<<"Empleado "<< nodoAuxiliar->info.nombre<< ", fue eliminado";
                break;
            case 4:
                imprimirLista(lista);
                break;
            case 5:
                siga = false;
                break;
            default:
                cout<< "Opcion incorrecta!";
                break;

        }

    }
    
    return 0;
}