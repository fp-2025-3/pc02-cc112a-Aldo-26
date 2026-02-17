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

Producto crearProducto(int codigo, const char* nombre, double precio, int stock);
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
    
    Producto* encontrado = buscarProducto(inv, n, codigo);
    if(encontrado){
        cout << "Producto encontrado: " 
             << encontrado->nombre << " | Precio: " 
             << encontrado->precio << " | Stock: " 
             << encontrado->stock << endl;
    } else {
        cout << "Producto no encontrado." << endl;
    }
    
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

Producto* CrearInventario(int n){
    Producto *inv = new Producto[n];

    for(int i=0; i<n; i++){
        cout<<"Producto " << i+1 <<endl;
        inv[i] = crearProducto(0,"",0,0);
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
    if(!inventario) return;
    for(int i=0; i<n; i++){
        delete[] inventario[i].nombre; // liberar cada nombre
    }
    delete[] inventario;
}

