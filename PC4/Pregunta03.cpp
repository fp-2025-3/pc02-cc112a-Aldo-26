#include<iostream>
#include<cstring>
using namespace std;

struct Producto
{
    int codigo;
    char* nombre;
    double precio;
    int stock;
};

//Funciones utlizadas en el programa
Producto crearProducto(int codigo, const char* nombre, double precio, int stock);
Producto* CrearInventario(int n);
Producto* buscarProducto(Producto* inventario, int n, int codigoBuscado);
void imprimirInventario(Producto* inventario, int n);
void liberarInventario(Producto* inventario, int n);

int main(){
    //Introducimos el numero de inventario 
    int n;
    cout<<"Ingresa el numero de inventario: ";
    cin>>n;
    //Llenamos el inventario
    Producto *inv = CrearInventario(n);
    //Imprimi el inventario
    cout << "\n--- Inventario completo ---\n";
    imprimirInventario(inv, n);

    int codigo;
    cout<<"Ingrese el codigo del producto: ";
    cin>>codigo;

    //Producto incontrado y precios sino no se encuentra nada y todo se guarda en una estructura dinamica encontrado
    Producto* encontrado = buscarProducto(inv, n, codigo);
    if(encontrado){
        cout << "Producto encontrado: " 
             << encontrado->nombre << " | Precio: " 
             << encontrado->precio << " | Stock: " 
             << encontrado->stock << endl;
    } else {
        cout << "Producto no encontrado." << endl;
    }
    //Liberamos la memoria
    liberarInventario(inv,n);

    return 0;
}

Producto crearProducto(int codigo, const char* nombre, double precio, int stock) {
    Producto p;

    //Se guarda la informacion de cada producto
    p.codigo = codigo;
    p.precio = precio;
    p.stock = stock;

    // Reservar memoria dinámica para el nombre basado en el parámetro 'nombre'
    p.nombre = new char[strlen(nombre) + 1];
    strcpy(p.nombre, nombre);    //Se copia el producto del con el nombre

    return p; //Retorna en p
}

Producto* CrearInventario(int n) {
    Producto *inv = new Producto[n];

    for (int i = 0; i < n; i++) {
        int cod, stk;
        double pre;
        char tempNom[100];
        //Introducir los datos 
        cout << "\n--- Datos del Producto " << i + 1 << " ---" << endl;
        cout << "Codigo: "; cin >> cod;
        //Introducimos el nombre
        cout << "Nombre: "; 
        cin.ignore(); 
        cin.getline(tempNom, 100);
        cout << "Precio: "; cin >> pre;
        cout << "Stock: "; cin >> stk;

        // Llamamos a la función pasando los datos agregados
        inv[i] = crearProducto(cod, tempNom, pre, stk); 
    }
    return inv;
}

//Funcion que busca el producto
Producto* buscarProducto(Producto* inventario, int n, int codigoBuscado){
    //Usamos una busqueda lineal para encontrar el codigo buscado
    for(int i=0; i<n; i++){
        if(inventario[i].codigo == codigoBuscado){    //Si encuentra retorna el inventario
            return &inventario[i];
        }
    }
    return nullptr;    //Si no encuentra nada retorna nullptr
}

//Imprimir el inventario 
void imprimirInventario(Producto* inventario, int n) {
    for(int i=0; i<n; i++){
        //Llamamos cada elemento para imprimirlo
        cout << "Codigo: " << inventario[i].codigo
             << " | Nombre: " << inventario[i].nombre
             << " | Precio: " << inventario[i].precio
             << " | Stock: " << inventario[i].stock << endl;
    }
}

//Liberacion completa del inventario y de la liberacion de la memoria dinamica del nombre
void liberarInventario(Producto* inventario, int n){
    //Si el inventario es nulo o no
    if(!inventario) return;
    for(int i=0; i<n; i++){
        delete[] inventario[i].nombre; // liberar cada nombre
    }
    delete[] inventario;    //Libera el inventario
}

