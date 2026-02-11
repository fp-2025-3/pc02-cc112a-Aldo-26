#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

struct Seleccion{
    int PP;
    int PE;
    int PG;
    int punt;
    float rend;
};

void llenarDatos(Seleccion* eq){

    for(int i=0; i<100; i++){
        
        int temp1 = 0;
        int temp2 = 0;
        int temp3 = 0;
        
        temp1 = rand() % 100;
        eq[i].PG = temp1;
        
        temp2 = rand() % (100 - temp1);
        eq[i].PP = temp2;
        
        temp3 = 100 - temp1 - temp2;
        eq[i].PE = temp3;

        eq[i].punt = 3*temp1 + temp2;

        eq[i].rend = (3*temp1 + temp2)/3.0;
    }
}   

void mejorSeleccion(Seleccion* eq){
    int j = 0;
    int nota = 0;

    for(int i=0; i<100; i++){
        if(eq[i].punt > nota){
            nota = eq[i].punt;
            j = i;
        }
    }

    cout<<"\nLa seleccion con mejor rendimiento es: Seleccion "<< j + 1<<endl;
    cout<<"Rendimiento "<<eq[j].rend;
}

void imprimir(Seleccion* eq){

    cout<<"Seleccion               PG      PP      PE      Puntaje       Rendimiento "<<endl;

    for(int i=0; i<100; i++){
        cout<<"Pais_Seleccion "<< i+1 <<":\t"<< eq[i].PG <<"\t"<< eq[i].PP <<"\t"<< eq[i].PE <<"\t"<< eq[i].punt <<"\t\t" << eq[i].rend <<endl;
    }
}

int main(){

    Seleccion* eq = new Seleccion[100];

    srand(time(NULL));

    llenarDatos(eq);
    imprimir(eq);
    mejorSeleccion(eq);

    delete[] eq;
    eq = nullptr;

    return 0;
}
