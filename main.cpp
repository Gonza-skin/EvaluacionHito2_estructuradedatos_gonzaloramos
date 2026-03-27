#include <iostream>
#include <string>
using namespace std;
struct Nodo {
    string nombre;           //lista
    int codigo;
    Nodo* siguiente;
};

class Cola {
private:
    Nodo* frente;
    Nodo* final;

public:
    Cola() {
        frente = NULL;
        final = NULL;
    }
    void registrar(string nombre, int codigo) {            //registro de almuno
        Nodo* nuevo = new Nodo();
        nuevo->nombre = nombre;
        nuevo->codigo = codigo;
        nuevo->siguiente = NULL;

        if (final == NULL) {
            frente = nuevo;
            final = nuevo;
        } else {
            final->siguiente = nuevo;
            final = nuevo;
        }
        cout << "Estudiante registrado";
    }


    void atender() {
        if (frente == NULL) {
            cout << "No hay estudiantes";
            return;
        }

        Nodo* temp = frente;
        cout << "Atendiendo: " << temp->nombre << " - " << temp->codigo << endl;

        frente = frente->siguiente;
        delete temp;

        if (frente == NULL) {
            final = NULL;
        }
    }
    void mostrar() {
        Nodo* temp = frente;      //muestra estudiantes

        if (temp == NULL) {
            cout << "Cola vacia\n";
            return;
        }

        int pos = 1;
        while (temp != NULL) {
            cout << pos << ". " << temp->nombre << " - " << temp->codigo << endl;
            temp = temp->siguiente;
            pos++;
        }
    }

    void buscar(string nombre) {           //aqui se busaca los estudiantes
        Nodo* temp = frente;
        int pos = 1;

        while (temp != NULL) {
            if (temp->nombre == nombre) {
                cout << "Encontrado en posicion: " << pos << endl;
                return;
            }
            temp = temp->siguiente;
            pos++;
        }

        cout << "No encontrado\n";
    }
};

int main() {
    Cola cola;               //el menu
    int opcion;
    string nombre;
    int codigo;

    do {
        cout << "1. Registrar2. Atender3. Mostrar4. Buscar5. Salir";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Nombre: ";
            cin >> nombre;
            cout << "Codigo: ";
            cin >> codigo;
            cola.registrar(nombre, codigo);
            break;

        case 2:
            cola.atender();
            break;

        case 3:
            cola.mostrar();
            break;

        case 4:
            cout << "Nombre a buscar: ";
            cin >> nombre;
            cola.buscar(nombre);
            break;
        }

    } while (opcion != 5);

    return 0;
}