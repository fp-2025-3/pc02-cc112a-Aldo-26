#include<iostream>
using namespace std;

struct Estudiante{
    char nombre[30];
    int nota;
};

void llenarDatos(Estudiante *e, int N){
    for(int i=0; i<N; i++){
        cout<<"Ingrese el nombre del estudiante "<< i + 1<<": ";
        cin.ignore();
        cin.getline(e[i].nombre,29);

        cout<<"Ingrese la nota del estudiante "<< i + 1<<": ";
        cin>>e[i].nota;
    }
}

void mayorNota(Estudiante* e, int N){
    int j = 0;
    int temp = 0;

    for(int i=0; i<N; i++){
        if(e[i].nota > temp){
            temp = e[i].nota;
            j = i;
        }
    }

    cout<<"El estudiante con Mayor es: "<< e[j].nombre << endl;
    cout<<"Nota: "<<e[j].nota;
}

int main(){

    int N;
    cout<<"Ingrese el numero de estudiantes: ";
    cin>>N;

    Estudiante* e = new Estudiante[N];

    llenarDatos(e,N);
    mayorNota(e,N);

    delete[] e;
    e = nullptr;

    return 0;
}
