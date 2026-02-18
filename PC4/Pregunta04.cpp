#include <iostream>
#include <cstring> 

using namespace std;

struct Item {
    char* descripcion; 
    int cantidad;
    double precioUnitario;
};

struct Pedido {
    int numeroPedido;
    char* nombreCliente; // memoria dinámica
    Item* items;         // arreglo dinámico de items
    int cantidadItems;
};

// --- Función Auxiliar para crear Ítems ---
Item crearItem(const char* descripcion, int cantidad, double precio) {
    Item nuevo;
    // Reservar memoria para la descripción (+1 para el carácter nulo '\0')
    nuevo.descripcion = new char[strlen(descripcion) + 1];
    strcpy(nuevo.descripcion, descripcion);
    
    nuevo.cantidad = cantidad;
    nuevo.precioUnitario = precio;
    return nuevo;
}

//  Función para crear el Pedido 
Pedido* crearPedido(int numero, const char* cliente, int cantItems) {
    // Reservar memoria para un Pedido
    Pedido* p = new Pedido;
    
    p->numeroPedido = numero;
    p->cantidadItems = cantItems;

    // Reservar memoria para nombreCliente
    p->nombreCliente = new char[strlen(cliente) + 1];
    strcpy(p->nombreCliente, cliente);

    // Reservar un arreglo dinámico de Item
    p->items = new Item[cantItems];

    // Inicializar los Item (aquí podrías pedir datos al usuario, pero para el ejemplo usaremos datos genéricos)
    for(int i = 0; i < cantItems; i++) {
        p->items[i] = crearItem("Producto Generico", 1, 0.0);
    }
    return p;
}

// Función para calcular el Total 
double calcularTotal(const Pedido* p) {
    double total = 0;
    for(int i = 0; i < p->cantidadItems; i++) {
        total += (p->items[i].cantidad * p->items[i].precioUnitario);
    }
    return total;
}

// Función para encontrar el ítem más caro 
Item* itemMasCaro(Pedido* p) {
    if (p->cantidadItems == 0) return nullptr;
    
    Item* masCaro = &p->items[0];
    for(int i = 1; i < p->cantidadItems; i++) {
        if(p->items[i].precioUnitario > masCaro->precioUnitario) {
            masCaro = &p->items[i];
        }
    }
    return masCaro;
}

//Funcion para imprimir los items
void imprimirItems(Item* items, int n) {
    for(int i = 0; i < n; i++) {
        cout << "Item " << i + 1 
             << " " << items[i].descripcion
             << " | Cant: " << items[i].cantidad
             << " | Precio: " << items[i].precioUnitario << endl;
    }
}

// Función para liberar memoria adecuadamente 
void liberarPedido(Pedido* p) {
    if (p == nullptr) return;

    // Liberar la descripción de cada Ítem dentro del arreglo
    for(int i = 0; i < p->cantidadItems; i++) {
        delete[] p->items[i].descripcion;
    }

    // Liberar el arreglo de Ítems
    delete[] p->items;

    // Liberar el nombre del cliente
    delete[] p->nombreCliente;

    // Liberar la estructura Pedido en sí
    delete p;
}

int main() {
    // Ejemplo de uso
    Pedido* miPedido = crearPedido(101, "Juan Perez", 2);

    // Editamos los items manualmente para probar
    miPedido->items[0] = crearItem("Laptop", 1, 100.0);
    miPedido->items[1] = crearItem("Mouse", 2, 200.0);
    miPedido->items[2] = crearItem("Teclado", 3, 300.0);

    cout << "Cliente: " << miPedido->nombreCliente << endl;
    cout << "--- Detalle de Items ---" << endl;
    
    // Corregido: El nombre del puntero es miPedido->items
    imprimirItems(miPedido->items, miPedido->cantidadItems);

    cout << "------------------------" << endl;
    cout << "Total del pedido: " << calcularTotal(miPedido) << endl;

    Item* caro = itemMasCaro(miPedido);
    if(caro) {
        cout << "Item mas caro: " << caro->descripcion << " | " << caro->precioUnitario << endl;
    }

    //Liberar todo al finalizar
    liberarPedido(miPedido);
    miPedido = nullptr;

    return 0;
}
