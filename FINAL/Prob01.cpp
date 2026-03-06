#include<iostream>
using namespace std;

int **crearMatriz(int n, int m);
void llenarMatriz(int **Matriz, int n, int m);
int* sumaFilas(int**Matriz, int n, int m);
void liberarMatriz(int **Matriz, int n);

int main(){
    int n,m;

    cout << "Ingrese el las dimensiones n y m: ";
    cin >> n; 
    cin >> m;

    int **Matriz = crearMatriz(n,m); 
    llenarMatriz(Matriz, n, m);
    cout<<"Matriz creada: "<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<*(*(Matriz+i)+j)<<"\t";
        }
        cout<<endl;
    }

    int *sumFil = sumaFilas(Matriz, n, m);
    cout<<"La matriz suma fila: "<<endl;
    for(int i=0; i<n; i++){
        cout<<*(sumFil + i)<<" ";
    }

    liberarMatriz(Matriz, n);
    delete [] sumFil;
    sumFil = nullptr;
}

int **crearMatriz(int n, int m){
    int **Matriz = new int*[n];
    for(int i=0; i<n; i++){
        Matriz[i] = new int[m];
    }

    return Matriz;
}

void llenarMatriz(int **Matriz, int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            *(*(Matriz+i)+j) = (i+1)*(j+1);
        }
    }
}

int* sumaFilas(int**Matriz, int n, int m){
    int *sumFil = new int[n];

    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=0; j<n; j++){
            sum +=*(*(Matriz+i)+j);
        }
        sumFil[i] = sum;
    }
    return sumFil;
}   

void liberarMatriz(int **Matriz, int n){
    for(int i=0; i<n; i++){
        delete[] Matriz[i];
        Matriz[i] = nullptr;
    }
    delete []Matriz;
    Matriz = nullptr;
}

