#include<iostream>
#include<cmath>
using namespace std;

struct Punto{
    int x;
    int y;
    int z;
};

void llenardatos(Punto &r){
    
    cout<<"X: "; cin>>r.x;
    cout<<"Y: ";cin>>r.y;
    cout<<"Z: ";cin>>r.z;
}

float calcularDistancia(Punto r1, Punto r2){
    
    return sqrt(pow(r1.x - r2.x, 2) + pow(r1.y - r2.y, 2) + pow(r1.z - r2.z, 2));

}

int main(){

    Punto r1, r2;
    
    cout<<"Ingrese las coordenas del primer punto: "<<endl;
    llenardatos(r1);

    cout<<"Ingrese las coordenas del segundo punto: "<<endl;
    llenardatos(r2);

    float dis = calcularDistancia(r1,r2);

    cout<<"La distancia entre los dos puntos es: "<<dis<<endl;

    return 0;
}
