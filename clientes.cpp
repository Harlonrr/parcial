#include <iostream>
#include <queue>

using namespace std;

// Definición de la estructura Cliente
struct Cliente {
    int numeroCuenta;
    int tipoCuenta; // 1 para preferencial, 2 para tradicional
};

// Función para mostrar los clientes en una fila
void mostrarFila(queue<Cliente>& fila, string tipoFila) {
    cout << "Clientes en la fila " << tipoFila << ":" << endl;
    int turno = 1;
    while (!fila.empty()) {
        cout << "Turno " << turno << ": Cuenta " << fila.front().numeroCuenta << endl;
        fila.pop();
        turno++;
    }
}

// Función para gestionar las filas
void gestionarFilas(queue<Cliente>& filaTradicional, queue<Cliente>& filaPreferencial) {
    if (filaTradicional.size() >= 5 && filaPreferencial.size() <= 2) {
        for (int i = 0; i < 3; i++) {
            Cliente clienteMovido = filaTradicional.front();
            filaTradicional.pop();
            clienteMovido.tipoCuenta = 1; // Cambia el tipo de cuenta a preferencial
            filaPreferencial.push(clienteMovido);
        }
    }
}

int main() {
    queue<Cliente> filaTradicional;
    queue<Cliente> filaPreferencial;

    // Registro de clientes (simulado)
    for (int i = 1; i <= 10; i++) {
        Cliente cliente;
        cliente.numeroCuenta = i;
        cliente.tipoCuenta = i % 2 == 0 ? 2 : 1; // Alternando entre preferencial y tradicional
        if (cliente.tipoCuenta == 1) {
            filaPreferencial.push(cliente);
        } else {
            filaTradicional.push(cliente);
        }

        // Gestión de filas después de registrar un cliente
        gestionarFilas(filaTradicional, filaPreferencial);
    }

    // Mostrar filas
    mostrarFila(filaTradicional, "tradicional");
    mostrarFila(filaPreferencial, "preferencial");

    return 0;
}