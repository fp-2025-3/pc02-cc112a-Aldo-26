#include<iostream>
#include<fstream>

using namespace std;

struct Empleados{
    int id;
    char nombre[30];
    double salario;
};

int main(){

    fstream lectura("empleados.dat", ios::binary | ios::in | ios:: out);

    if(!lectura){
        cout<<"El archivo no se pudo abrir ";
        return 1;
    }
    
    lectura.seekg(0, ios::end); // Ir al final
    long tamanoArchivo = lectura.tellg();
    int cont = tamanoArchivo / sizeof(Empleados);
    lectura.seekg(0, ios::beg); // Regresar al inicio

    Empleados *E = new Empleados [cont];

    for (int i = 0; i < cont; i++) {
        lectura.read((char*)&E[i], sizeof(Empleados));
    }

    int ID;
    cout<<"Ingrese el ID del empleado: ";
    cin>>ID;

    int indice = ID - 1;
    if (indice >= 0 && indice < cont) {
        cout << "-------DATOS ACTUALES--------" << endl;
        cout << "ID: " << E[indice].id << endl;
        cout << "Nombre: " << E[indice].nombre << endl;
        cout << "Salario: " << E[indice].salario << endl;

        double nuevoSal;
        cout << "Ingrese el nuevo salario: ";
        cin >> nuevoSal;

        E[indice].salario = nuevoSal;

        lectura.seekp(indice * sizeof(Empleados), ios::beg);
        lectura.write((char*)&E[indice], sizeof(Empleados));

        cout << "Salario actualizado en el archivo." << endl;
    } else {
        cout << "ID fuera de rango." << endl;
    }

    delete[] E;
    lectura.close();
    return 0;
}
