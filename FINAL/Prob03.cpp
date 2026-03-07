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

void crearArchivo(int N){

    fstream archivo("proyectos.dat", ios::binary | ios::out | ios::in);

    if(!archivo){
        archivo.open("proyectos.dat", ios::binary | ios:: out);
        archivo.close();
        archivo.open("proyectos.dat", ios::out | ios:: in);
    }

    Proyecto p;
    
    for(int i=0; i<N; i++){

        cout<<"\n Ingrese el ID: ";
        cin>>p.id;

        int pos = sizeof(Proyecto)*(p.id - 1);
        
        archivo.seekg(pos);
        Proyecto temp;

        if(archivo.read((char*)&temp, sizeof(Proyecto)) && temp.id == p.id){
            cout<<"La ID ya existe";
            i--;
        }else{
            cout<<"Ingrese el titulo del proyecto: ";
            cin.ignore();
            cin.getline(p[i].titulo,40);
    
            cout<<"Ingrese el presupuesto del proyecto: ";
            cin>>p[i].presupuesto;
    
            cout<<"Ingrese la duracion del proyecto: ";
            cin>>p[i].duracionMes;

            archivo.write((char*)&p, sizeof(Proyecto));
        }
    }
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
        cout<<"Duracion(por mes)"<<p.duracionMes<<endl;
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

        switch (op){
            case 1:
                cout<<"Ingresa la cantida de archivos a ingresa ";
                cin>>n;
                
                crearArchivo(n);
            break;
            
            case 2:
                mostrarArchivo();
            break;

            default:
            break;
        
        }
    } while (op != 3);

    return 0;
}
