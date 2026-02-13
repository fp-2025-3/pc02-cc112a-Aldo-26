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

Producto crearProducto(int codigo, char* nombre, double precio, int stock);
Producto* CrearInventario(int n);
Producto* buscarProducto(Producto* inventario, int n, int codigoBuscado);
void liberarInventario(Producto* inventario, int n);

int main(){

    int n;
    cout<<"Ingresa el numero de inventario: ";
    cin>>n;

    Producto *inv = CrearInventario(n);

    int codigo;
    cout<<"Ingrese el codigo del producto: ";
    cin>>codigo;
    
    buscarProducto(inv,n,codigo);

    liberarInventario(inv,n);

    return 0;
}

Producto crearProducto(int codigo, char* nombre, double precio, int stock){

    Producto prod;
    cout<<"Ingrese el codigio: ";
    cin>>codigo;

    cout<<"Ingrese el nombre del producto: ";
    cin.ignore();
    cin.getline(nombre,10);

    cout<<"Ingrese el precio ";
    cin>>precio;

    cout<<"Ingrese el stock";
    cin>>stock;

    return prod = {codigo,nombre,precio,stock};
}

Producto* CrearInventario(int n){
    Producto *inv = new Producto[n];

    for(int i=0; i<n; i++){
        int codigo;
        char *nombre;
        double precio;
        int stock;

        inv[i] = crearProducto(codigo,nombre,precio,stock);
    }

    return inv;
}

Producto* buscarProducto(Producto* inventario, int n, int codigoBuscado){
    int i = 0;
    for(int i=0; i<n; i++){
        if(inventario[i].codigo == codigoBuscado){
            return &inventario[i];
        }
    }

    return nullptr;
}

void liberarInventario(Producto* inventario, int n){

    if(!inventario){
        return ;
    }

    delete []inventario;
}

