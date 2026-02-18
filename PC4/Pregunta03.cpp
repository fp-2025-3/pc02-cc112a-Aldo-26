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

Producto crearProducto(int codigo, const char* nombre, double precio, int stock){
    char temp[100];    //Asignamos una memoria dinamica para guardar el nombre del Producto

    //Ingresamos los datos del Producto
    cout<<"Ingrese el codigio: ";
    cin>>codigo;

    cout<<"Ingrese el nombre del producto: ";
    cin.ignore();
    cin.getline(temp,100);

    cout<<"Ingrese el precio ";
    cin>>precio;

    cout<<"Ingrese el stock";
    cin>>stock;

    // Reservar memoria para nombre del Producto
    char* nombreCopia = new char[strlen(temp) + 1];
    strcpy(nombreCopia, temp);    //Copiamos el temp en la memoria dinamica
    
    Producto prod = {codigo, nombreCopia, precio, stock};    //Creamos prod con los datos dados
    return prod;    //Retornamos el Producto
}

//Creamos el inventario 
Producto* CrearInventario(int n){
    //Se crea una estructura con n valores
    Producto *inv = new Producto[n];

    //Llenamos cada uno de los inventarios
    for(int i=0; i<n; i++){
        cout<<"--- Producto " << i+1 <<" ---"<<endl;
        //Llamamos a la funcion crear producto para llenar cada inventario 
        inv[i] = crearProducto(0,"",0,0);    //Inicializamos en 0, "", 0 y 0 y luego sera modificado
    }
    return inv;    //Retorna el inventario completo
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

