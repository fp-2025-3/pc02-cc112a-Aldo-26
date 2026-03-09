#include<iostream>
#include<cstring>
#include <fstream>
using namespace std;

struct Proyecto
{
    int id;
    char titulo[40];
    double presupuesto;
    int duracionMes;
};

bool idExiste(int id) {
    ifstream archivo("proyecto.dat", ios::binary);
    if (!archivo) {
        return false;
    }

    Proyecto p;
    while (archivo.read((char*)&p, sizeof(Proyecto))) {
        if (p.id == id){
            return true;
        }
    }
    return false;
}

void crearArchivo(Proyecto nuevo){
    if (idExiste(nuevo.id)) {
        cout << "Error: El ID " << nuevo.id << " ya existe. Registro saltado." << endl;
        return;
    }

    fstream archivo("proyectos.dat", ios::binary | ios::out | ios::in);

    if(!archivo){
        archivo.open("proyectos.dat", ios::binary | ios:: out);
        archivo.close();
        archivo.open("proyectos.dat", ios::out | ios:: in);
    }

    archivo.seekg(0, ios::end);
    long tamanoArchivo = archivo.tellg();
    int n = tamanoArchivo / sizeof(Proyecto);
    
    int i = n - 1;
    Proyecto temp;

    while (i >= 0) {
        archivo.seekg(i * sizeof(Proyecto));
        archivo.read((char*)&temp, sizeof(Proyecto));

        if (temp.presupuesto < nuevo.presupuesto) {
            archivo.seekp((i + 1) * sizeof(Proyecto));
            archivo.write((char*)&temp, sizeof(Proyecto));
            i--;
        } else {
            break; 
        }
    }

    archivo.clear();
    archivo.seekp((i + 1) * sizeof(Proyecto));
    archivo.write((char*)&nuevo, sizeof(Proyecto));
    archivo.close();
}

void mostrarArchivo(){
    
    ifstream archivo("proyectos.dat", ios::binary | ios::in);
    if (!archivo) {
        cout << "No existe el archivo de datos." << endl;
        return;
    }

    Proyecto p;

    int i=1;
    while(archivo.read((char*)&p, sizeof(Proyecto))){
        cout<<"---Proyecto "<< i<<"----"<<endl;
        cout<<"ID: "<<p.id<<endl;
        cout<<"Titulo: "<<p.titulo<<endl;
        cout<<"Presupuesto: "<<p.presupuesto<<endl;
        cout<<"Duracion(por mes): "<<p.duracionMes<<endl;
        i++;
    }

    archivo.close();
}

int main(){

    int n;
    int op;
    do
    {
        cout<<"Ingrese la opcion que quiera realizar: "<<endl;
        cout<<"1. Crear archivo" << endl;
        cout<<"2. Mostrar todos los archivos" << endl;
        cout<<"3. Salir "<<endl;
        cin>>op;

        if (op == 1) {
            cout << "Cantidad de proyectos: ";
            cin >> n;
            for (int i = 0; i < n; i++) {
                Proyecto p;
                cout << "\nProyecto " << i + 1 << endl;
                cout << "ID: "; cin >> p.id;
                cout << "Titulo: "; cin.ignore(); cin.getline(p.titulo, 40);
                cout << "Presupuesto: "; cin >> p.presupuesto;
                cout << "Duracion (meses): "; cin >> p.duracionMes;
                crearArchivo(p);
            }
        } else if (op == 2) {
            mostrarArchivo();
        }
    } while (op != 3);

    return 0;
}
