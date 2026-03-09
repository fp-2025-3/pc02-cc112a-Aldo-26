#include<iostream>
#include<cstring>
using namespace std;

const int N = 100; 

void llenarDatos(char nombres[][20], int tiempo[], int n){

    for(int i = 0; i < n; i++){
        cout<<"Nombre del corredor "<< i + 1 <<": ";
        cin>>nombres[i];
        cout<<"Tiempo (en segundos): ";
        cin>>tiempo[i];
    }
}

void burbuja(char nombres[][20], int tiempo[], int n){
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(tiempo[j] > tiempo[j + 1]){
                swap(tiempo[j],tiempo[j + 1]);
                swap(nombres[j], nombres[j + 1]);
            }
        }
    }
}

int buscar(char nombres[][20], int tiempo[], int n, char* clave){

    for(int i = 0; i < n; i++){
        if(strcmp(nombres[i],clave) == 0){
            return i;
        }
    }
    return -1;
}

void intervalo(char nombres[][20], int tiempo[], int n, int limiteMayor, int limiteMenor) {
    cout << "\nCorredores en el rango de tiempo [" << limiteMenor << "s, " << limiteMayor << "s]: " << endl;
    bool huboResultados = false;

    for (int i = 0; i < n; i++) {
        if (tiempo[i] <= limiteMayor && tiempo[i] >= limiteMenor) {
            cout << nombres[i] << " - " << tiempo[i] << " segundos " << endl;
            huboResultados = true;
        }
    }
    if (!huboResultados) cout << "Ninguno en este rango." << endl;
}

void imprimir(char nombres[][20], int tiempo[], int n){
    
    for(int i = 0; i < n; i++){
        cout<< i + 1 <<". "<<nombres[i] << " - " <<tiempo[i] <<" segundos "<<endl;
    }
}



int main(){

    int n;
    cout<<"Ingrese el numero de corredores: ";
    cin>>n;

    char nombres[5][20];
    int tiempo[5];

    llenarDatos(nombres,tiempo,5);
    burbuja(nombres,tiempo,5);
    imprimir(nombres,tiempo,5);

    char clave[20];
    cout<<"Ingrese el nombre a buscar: ";
    cin>>clave;

    int m = buscar(nombres,tiempo,n,clave);

    if(m == -1){
        cout<<"El corredor no existe"<<endl;
    }else{
        cout<<"Corredor encontrado "<<endl;
        cout<<"Posicion: "<< m + 1 <<endl;
        cout<<"Tiempo: " << tiempo[m] <<endl;
    }

    int indMenor;
    int indMayor;

    cout << "Ingrese el indice mayor: ";
    cin>>indMayor;

    cout<<"Ingrese el indice menor: ";
    cin>>indMenor;

    intervalo(nombres, tiempo, n, indMayor,indMenor);

    return 0;
}
