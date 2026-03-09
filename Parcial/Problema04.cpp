#include<iostream>
using namespace std;

int* llenarCodigo(){
    int tempCodigo[3];

    for(int i = 0; i < 3; i++){
        cout<<"Ingrese el codigo del Estudiante: ";
        cin>>tempCodigo[i];
    }

    int *Codigo = new int[6];

    for(int i = 0; i < 3; i++){
        Codigo[i] = tempCodigo[i];
    }
    
    for(int i = 3; i < 6; i++){
        cout<<"Ingrese el codigo del Estudiante: ";
        cin>>Codigo[i];
    }

    return Codigo;
}

float* llenarPromedios(){
    float tempPromedios[3];
    
    for(int i = 0; i < 3; i++){
        cout<<"Ingrese el Promedio del Estudiante: ";
        cin>>tempPromedios[i];
    }

    float *Promedios = new float[6];

    for(int i = 0; i < 3; i++){
        Promedios[i] = tempPromedios[i];
    }

    for(int i = 3; i < 6; i++){
        cout<<"Ingrese el Promedio del Estudiante: ";
        cin>>Promedios[i];
    }

    return Promedios;
}

void imprimirEstudiantes(int arr1[], float arr2[], int n){
    for(int i = 0; i < n; i++){
        cout<<"Codigo: "<< arr1[i] << " Promedios: "<< arr2[i] << endl;
    }
}

int cantidadFiltrados = 0; 

int* filtrarCodigo(int arr1[], float arr2[]){
    int temp1[6];
    int j = 0;

    for(int i = 0; i < 6; i++){
        if(arr2[i] >= 10){
            temp1[j] = arr1[i];
            j++;
        }
    }

    cantidadFiltrados = j; 
    int* CodigoFiltrado = new int[j];

    for(int i = 0; i < j; i++){ 
        CodigoFiltrado[i] = temp1[i];
    }

    return CodigoFiltrado;
}

float* filtrarPromedio(int arr1[], float arr2[]){
    float temp2[6]; 
    int j = 0;

    for(int i = 0; i < 6; i++){
        if(arr2[i] >= 10){
            temp2[j] = arr2[i];
            j++;
        }
    }

    float* PromedioFiltrado = new float[j];

    for(int i = 0; i < j; i++){ 
        PromedioFiltrado[i] = temp2[i];
    }

    return PromedioFiltrado;
}

int main(){
    int *Codigo = llenarCodigo();
    float *Promedio = llenarPromedios();

    cout << "\n--- Todos los Estudiantes ---\n";
    imprimirEstudiantes(Codigo, Promedio, 6);

    int *CodigoNuevo = filtrarCodigo(Codigo, Promedio);
    float *PromedioNuevo = filtrarPromedio(Codigo, Promedio);
    
    cout << "\n--- Estudiantes Filtrados (>= 10) ---\n";
    
    imprimirEstudiantes(CodigoNuevo, PromedioNuevo, cantidadFiltrados);

    delete []Codigo;
    delete []Promedio;
    delete []CodigoNuevo;
    delete []PromedioNuevo;

    return 0;
}
