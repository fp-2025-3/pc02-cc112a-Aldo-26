#include<iostream>
using namespace std;

struct Fecha{
    int dia;
    int mes;
    int anio;
};

struct Contacto{
    char nombre[10];
    Fecha nacimiento;
};  


void llenarDatos(Contacto *cont, int N){
    cout<<"----------------CONTACTOS------------------"<<endl;    
    for(int i = 0; i < N; i++){
        cout<<"Contacto "<< i + 1 <<endl;
        
        cout<<"Ingresa su nombre: ";
        cin>>cont[i].nombre;

        cout<<"Ingrese el dia de su nacimiento: ";
        cin>>cont[i].nacimiento.dia;

        cout<<"Ingrese el mes de su nacimiento: ";
        cin>>cont[i].nacimiento.mes;

        cout<<"Ingrese el anio de su nacimiento: ";
        cin>>cont[i].nacimiento.anio;
    }
}

void mostrarNacidos(Contacto *cont, int N, int dato){
    cout<<"----------------Nacidos------------------"<<endl;    

    for(int i = 0; i < N; i++){
        if(cont[i].nacimiento.anio == dato){
            cout<<"\nNombre: "<< cont[i].nombre <<"\t| Nacimiento: "<< cont[i].nacimiento.dia <<
            "\t| Mes: "<< cont[i].nacimiento.mes <<"\t| Anio: "<< cont[i].nacimiento.anio <<endl;
        }
    }
}

int main(){

    int N;
    cout<<"Ingrese la cantidad de contactos: ";
    cin>>N;

    Contacto* cont = new Contacto[N];

    llenarDatos(cont,N);
    int clave;
    cout<<"Ingrese el año a escoger: ";
    cin>>clave;

    mostrarNacidos(cont,N,clave);

    delete [] cont;
    cont = nullptr;

    return 0;
}
