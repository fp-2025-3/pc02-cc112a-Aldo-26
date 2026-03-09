#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;

int main(){

    ifstream entrada("notas.txt");
    if(!entrada){
        cout<<"El archivo no se pudo abrir ";
        return 1;
    }

    ofstream salida("reporteAlumnos.txt");
    if(!salida){
        cout<<"El archivo no se pudo abrir ";
        return 1;
    }

    salida.setf(ios::fixed);    //Agregado para la precision de las notas
    salida.precision(1);
    
    int cant = 0;
    int n1, n2, n3;
    double prom = 0;
    double promGeneral = 0, promMax = 0, promMin = 20;
    string codigo, nombre, nombreMax, nombreMin;

    salida << "Codigo\tNombre\tPromedio\t\tCondicion "<<endl;
    salida << "-----------------------------------------------------------"<<endl;

    while(entrada >> codigo >> nombre >> n1 >> n2 >> n3){
        
        prom = (n1+ n2 + n3)/3.0;
        promGeneral += prom;
        salida << codigo << "\t" << nombre << "\t\t" << prom << "\t";

        if(prom >= 10.0 && n1 >= 5.0 && n2 >= 5.0 && n3 >= 5.0){
            salida << "\tAPROBADO ";
        }else{
            salida << " \tDESAPROBADO ";
        }

        if(prom > promMax){
            promMax = prom;
            nombreMax = nombre;
        }

        if(prom < promMin){
            promMin = prom;
            nombreMin = nombre;
        }
        
        cant++;
        salida<<endl;
    }

    promGeneral = promGeneral/cant;

    salida << "\n---------------------REPORTE GENERAL-------------------\n "<< endl;
    salida << "Total de estudiantes: " << cant << endl;
    salida << "Promedio general del curso " << promGeneral << endl;
    salida << "El estudiante con mayor promedio: " << promMax << " ("<< nombreMax << ") " << endl;
    salida << "El estudiante con menor promedio: " << promMin << " ("<< nombreMin << ") " << endl;

    entrada.close();
    salida.close();

    cout << "Se genero el registro correctamente " << endl;
    return 0;
}
