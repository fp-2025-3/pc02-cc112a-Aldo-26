#include<iostream>
#include <cmath>
using namespace std;

struct Punto{
    double x;
    double y;
};

void leerPunto(Punto *p);
double distanciaOrigen(const Punto *p);
Punto *masLejano(Punto *p1, Punto *p2);

int main(){

    Punto p1;
    Punto p2;

    cout<<"Ingrese los datos del punto 1:"<<endl;
    leerPunto(&p1);
    
    cout<<"Ingrese los datos del punto 2:"<<endl;
    leerPunto(&p2);

    double dis1 = distanciaOrigen(&p1);
    cout<<"La distancia del punto 1 al origen es: "<<dis1<<endl;;

    double dis2 = distanciaOrigen(&p2);
    cout<<"La distancia del punto 2 al origen es: "<<dis2<<endl;

    Punto *pMayor = masLejano(&p1,&p2);
    
    cout<<"El punto mas lejano el que tiene las componentes "<<endl;
    cout<<"X: "<< pMayor->x << endl;
    cout<<"Y: "<< pMayor->y << endl;

    return 0;
}

void leerPunto(Punto *p){
    Punto temp;
    cout << "Ingrese el valor del x: ";
    cin >> temp.x;

    cout << "Ingrese el valor del y: ";
    cin >> temp.y;

    p->x = temp.x;
    p->y = temp.y;
}

double distanciaOrigen(const Punto *p){
    return sqrt(pow(p->x,2) + pow(p->y,2));
}

Punto *masLejano(Punto *p1, Punto *p2){
    double v1 = distanciaOrigen(p1);
    double v2 = distanciaOrigen(p2);

    if(v1 < v2){
        cout << "EL punto mas lejano es el punto 2" << endl;
        return p2;
    }else{
        cout << "EL punto mas lejano es el punto 1" << endl;
        return p1;
    }
}
