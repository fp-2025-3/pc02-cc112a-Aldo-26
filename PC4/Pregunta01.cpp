#include<iostream>
using namespace std;

struct Polinomio{
    int coef;
    int exp;
};

Polinomio* sumaPolinomio(Polinomio *pol1, Polinomio *pol2, Polinomio *pol3){
    int c1;
    int c2; 
    int c3;

    Polinomio *Suma = new Polinomio[3];
    for(int i=0; i<=2; i++){
        
        if(2 >= i){
            c1 = pol1[i].coef;
        }else{
            c1 = 0;
        }

        if(1 >= i){
            c2 = pol2[i].coef;
        }else{
            c2 = 0;
        }

        if(2 >= i){
            c3 = pol3[i].coef;
        }else{
            c3 = 0;
        }

        Suma[i].coef = c1 + c2 + c3;
        Suma[i].exp = i;
    }

    return Suma;
}

void Producto(Polinomio *pol1, Polinomio* pol2, Polinomio *pol3){

    Polinomio* prod = new Polinomio[5];

    int ind = 0;
    for(int i=0; i<=2; i++){
        for(int j=0; j<=1; j++){
            for(int k=0; k<=2; k++){
                prod[i + j + k] = pol1[i].coef*pol2[j].coef*pol3[k].coef;  //me falto completar 
            }
        }
    }
}

void imprimir(Polinomio *pol, int n){
    for(int i=0; i<=n; i++){
        if(pol[i].coef == 0 && i <= n-1){
            i++;
        }
        cout<<pol[i].coef<<"x^"<<pol[i].exp<<" ";

        if(i<=n-1){
            cout<<"+ ";
        }
    }
    cout<<endl;
}

int main(){
    
    Polinomio *Pol1 = new Polinomio[2];
    Polinomio *Pol2 = new Polinomio[1];
    Polinomio *Pol3 = new Polinomio[2];

    Pol1[0] = {3,2};
    Pol1[1] = {0,1};
    Pol1[2] = {1,0};

    Pol2[0] = {5,1};
    Pol2[1] = {-4,0};

    Pol3[0] = {1,2};
    Pol3[1] = {0,1};
    Pol3[2] = {3,0};

    Polinomio *SumaPol = new Polinomio[2];
    SumaPol = sumaPolinomio(Pol1,Pol2, Pol3);

    Polinomio *ProdPol = new Polinomio[5];
    ProdPol = 

    cout<<"Polinomio 1: ";
    imprimir(Pol1,2);

    cout<<"Polinomio 2: ";
    imprimir(Pol2,1);

    cout<<"Polinomio 3: ";
    imprimir(Pol3,2);

    cout<<"Suma de los tres Polinomios: ";
    imprimir(SumaPol,2);
};
