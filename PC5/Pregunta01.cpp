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

    int cant = 0;
    int n1, n2, n3;
    double prom = 0;
    double promGeneral = 0;
    double promMax = 0;
    double promMin = 20;

    ofstream salida("reporteAlumnos.txt");

    if(!salida){
        cout<<"El archivo no se pudo abrir ";
        return 1;
    }
    
    string linea;

    salida << "Codigo\tNombre\tPromedio\t\tCondicion "<<endl;
    salida << "-----------------------------------------------------------"<<endl;

    while(entrada >> linea){
        
        salida << linea << "\t";

        getline(entrada,linea, ' ');
        salida << linea << "\t";

        getline(entrada,linea,' ');
        entrada >> n1;

        getline(entrada,linea,' ');
        entrada >> n2;

        getline(entrada,linea,' ');
        entrada >> n3;

        salida << "Promedio: ";
        prom = (n1+ n2 + n3)/3.0;
        promGeneral += prom;
        salida << prom <<"\t";

        if(prom >= 10.0 && n1 >= 5.0 && n2 >= 5.0 && n3 >= 5.0){
            salida << "\tAPROBADO ";
        }else{
            salida << " \tDESAPROBADO ";
        }

        if(prom > promMax){
            promMax = prom;
        }

        if(prom < promMin){
            promMin = prom;
        }
        
        cant++;
        salida<<endl;
    }

    promGeneral = promGeneral/cant;

    salida << "\n---------------------REPORTE GENERAL-------------------\n "<< endl;
    salida << "Total de estudiantes: " << cant << endl;
    salida << "Promedio general del curso " << promGeneral << endl;
    salida << "El estudiante con mayor promedio: " << promMax << endl;
    salida << "El estudiante con menor promedio: " << promMin << endl;

    entrada.close();
    salida.close();

    cout << "Se genero el registro correctamente " << endl;
    return 0;
}
