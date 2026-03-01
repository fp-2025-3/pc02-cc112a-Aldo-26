#include<iostream>
#include<fstream>

using namespace std;

struct Empleados{
    int id;
    char nombre[30];
    double salario;
};

int main(){

    fstream lectura("empleados.dat", ios::binary);

    if(!lectura){
        cout<<"El archivo no se pudo abrir ";
        return 1;
    }

    string linea;
    int cont = 0;
    
    while(getline(lectura,linea)){
        cont++;
    }

    Empleados *E = new Empleados [cont-1];

    for(int i=0; i<cont-1; i++){
        while(lectura.read((char*)&E, sizeof(Empleados))){
            lectura >> E[i].id >> E[i].nombre >> E[i].salario;
        }
    }

    int ID;

    cout<<"Ingrese el ID del empleado: ";
    cin>>ID;

    cout<<"-------DATOS DEL EMPLEADO--------"<<endl;
    cout<<"ID: "<< E[ID].id <<endl;
    cout<<"Nombre: "<< E[ID].nombre <<endl;
    cout<<"Salario: "<< E[ID].salario <<endl;

    int sal = 0;
    cout << "Ingrese el nuevo salario: ";
    cin >> sal;

    E[ID-1].salario = sal;

    return 0;
}
