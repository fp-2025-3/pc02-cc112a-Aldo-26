#include<iostream>
using namespace std;

int sumaMaxima(int (*inicio)[5], int i1, int j1, int i2, int j2){
    int suma = 0;

    for(int i=i1; i<=i2; i++){
        for(int j=j1; j<=j2; j++){
            suma += *(*(inicio + i) + j);
        }
    }
     return suma;
}

void hallarSubmatrizMayot(int (*inicio)[5], int fil, int col){
    int maxSuma = 0;

    int mf1=0, mc1=0;
    int mf2=0, mc2=0;

    bool PrimerCalculo = true;

    for(int f1=0; f1<fil; f1++){
        for(int c1=0; c1<col; c1++){
            for(int f2=0; f2<fil; f2++){
              for(int c2=0; c2<col; c2++){
                    int sumActual = sumaMaxima(inicio, f1, c1, f2, c2);

                    if(PrimerCalculo or sumActual > maxSuma){
                       maxSuma = sumActual;
                       mf1 = f1;
                       mc1 = c1;
                       mf2 = f2;
                       mc2 = c2;
                      PrimerCalculo = false;
                  }  
               }
            }
        }
    }
    

     cout<<"SubMatriz mayor: "<<endl;
     for(int i=mf1; i<mf2; i++){
        for(int j=mc1; j<mc2; j++){
                cout<< *(*(Matriz + i) + j) <<" ";
        }
        cout<<endl;
    }

    cout<<"Cordenadas iniciales ("<<mf1<<","<<mc1<<")"<<endl;
    cout<<"Cordenadas iniciales ("<<mf2<<","<<mc2<<")"<<endl;

    cout<<"La suma Maxima es: "<<maxSuma<<endl;
}

int main(){

    int Matriz[4][5] = {{-2,1,-3,4,-1},
                        {2,3,-2,1,-5},
                        {-1,4,2,-3,2},
                        {1,-2,3,4,-1}};

    
    int (*inicio)[5] = Matriz;

    cout<<"Matriz original: "<<endl;
    for(int i=0; i<4; i++){
        for(int j=0; j<5; j++){
                cout<< *(*(Matriz + i) + j) <<" ";
        }
        cout<<endl;
    }

    int i1, j1;
    int i2, j2;

    cout<<"Ingrese las coordenada de la esquina superior izquierda: ";
    cin>>i1;
    cin>>j1;

    cout<<"\nIngrese las coordenada de la esquina superior izquierda: ";
    cin>>i2;
    cin>>j2;

    int sum= sumaMaxima(inicio, i1, j1, i2, j2); 
    cout<<"La suma de la submatriz es "<<sum<<endl;

    hallarSubmatrizMayot(inicio, 4, 5);
    

    return 0; 
}
