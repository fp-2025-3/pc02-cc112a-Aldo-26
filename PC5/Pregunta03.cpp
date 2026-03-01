#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

struct Punto
{
    int x;
    int y;
};


int main(){

    Punto *p = new Punto[80];

    for(int i=0; i<80; i++){
        p[i].x = i;
        p[i].y = sin(i);
    }

    ofstream grafica("grafico.txt");

    if(!grafica){
        cout << "No se pudo abrir el archivo";
        return 1;
    }

    for(int i=0; i<80; i++){
        grafica.seekp(p[i].x* grafica, ios::beg);

    }

    
    



    return 0;
}
