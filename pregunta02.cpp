#include <iostream>
using namespace std;

// Complete la funcion de busqueda
int* buscar(
    int* inicio,                 // Estos dos primeros parametros
    int* fin,                    // delimitan el rango de busqueda a [inicio, fin)
    bool (*equivale)(int, int),  // equivale es una funcion que determina cuando dos enteros se condideran equivalentes
    int clave                    // clave es el valor a buscar segun el criterio indicado
) {
    
    for(int* i= inicio; i<fin; i++){
        if(equivale(*i,clave)){
            cout<<"Encontrado valor: "<< *i <<endl;
            return i;
        }
    }
}

bool igual(int a, int b){
    if(a == b){
        cout<<"Igualdad exacta: ";
        return true;
    }
    return false;
}

bool mismaParidad(int a, int b){
    if((a+b)%2 == 0){
        cout<<"Misma paridad: ";
        return true;
    }

    return false;
}

bool divideA(int a, int b){
    if(a%b == 0){
        cout<<"Divide A: ";
        return true;
    }
    return false;
}

bool mismaCantidadDigitos(int a, int b){
    if(a/b < 1 and b/a < 1){
        cout<<"Misma cantidad de digitos: ";
        return true;
    }
    return false;
}

bool minimoResiduoMOD5(int a, int b){
    if(a%5 < b){
        cout<<"Minimo residuo: ";
        return true;
    }
    return false;
}

// Implemente aqui los Criterios de equivalencia
// y si es necesario algunas funciones adicionales para reproducir el ejemplo de salida



int main() {
    int A[] = { -1, 21, 2, -2, 8, 13, 25 };
    int* inicio = A;
    int* fin = A + 7;

    int clave = 13;

    cout<<"Arreglo: ";
    for(int i=0; i<7; i++){
        cout<<*(A + i)<<" ";
    }
    cout<<endl;

    cout<<"Clave: "<<clave<<endl;


    // Llame a la funcion buscar para cada criterio implementado
    buscar(inicio ,fin, igual, clave);
    int *p1 = buscar(inicio ,fin, igual, clave);
    cout<<"Pos: "<<p1<<endl;

    buscar(inicio ,fin, mismaParidad, clave);
    int *p2 = buscar(inicio ,fin, mismaParidad, clave);
    cout<<"Pos: "<<p2<<endl;

    buscar(inicio ,fin, divideA, clave);
    int *p3 = buscar(inicio ,fin, divideA, clave);
    cout<<"Pos: "<<p3<<endl;

    buscar(inicio ,fin, mismaCantidadDigitos, clave);
    int *p4 = buscar(inicio ,fin, mismaCantidadDigitos, clave);
    cout<<"Pos: "<<p4<<endl;

    buscar(inicio ,fin, minimoResiduoMOD5, clave);
    int *p5 = buscar(inicio ,fin, minimoResiduoMOD5, clave);
    cout<<"Pos: "<<p5<<endl;

    return 0;
}
