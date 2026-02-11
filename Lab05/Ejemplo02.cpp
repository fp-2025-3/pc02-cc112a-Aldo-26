#include<iostream>
using namespace std;

struct Estudiantes{
    int codigo;
    float promedio;
};

int main (){

    int N;
    cout<<"Ingrese el numero de estudiantes: ";
    cin>>N;

    Estudiantes *e = new Estudiantes[N];

    for(int i = 0; i < N; i++){
        cout<<"Ingrese el codigo del estudiantes "<< i + 1 <<": ";
        cin>>e[i].codigo;

        cout<<"Ingrese el Promedio del estudiante "<< i + 1 <<": ";
        cin>>e[i].promedio;
    }

    cout<<"Los aprobados son: "<<endl;
    for(int i = 0; i < N; i++){
        if(e[i].promedio >= 10){
            cout<<"Codigo: "<< e[i].codigo <<" | Estudiante: "<< e[i].promedio <<endl;
        }
    }

    delete []e;
    e = nullptr;
    
    return 0;
}
