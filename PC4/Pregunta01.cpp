#include<iostream>
using namespace std;

struct Polinomio{
    int coef;
    int exp;
};

//Funcion suma de polinomios
Polinomio* sumaPolinomio(Polinomio *pol1, Polinomio *pol2, Polinomio *pol3){
    //c1, c2 y c3 guardan el valor temporalmente de los coeficientes de los polinomios pol1, pol2 y pol3
    int c1 = 0; 
    int c2 = 0; 
    int c3 = 0;

    //Separa la memoria dinamica de la suma 
    Polinomio *Suma = new Polinomio[3];
    for(int i=0; i<=2; i++){

        //La funcion ve que si el exponente es menor a i entonces copia el valor del coeficiente, sino el valor es cero
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

        Suma[i].coef = c1 + c2 + c3;  //Se suma todos c1, c2 y c3 para hallar el coef suma
        Suma[i].exp = i; //Para mantener el orden ascendente
    }
    return Suma;
}

Polinomio* Producto(Polinomio *pol1, Polinomio* pol2, Polinomio *pol3){
    // Grado maximo
    int gradoMax = 5;
    Polinomio* prod = new Polinomio[gradoMax + 1];

    // Inicializar coeficientes en 0
    for(int i=0; i <= gradoMax; i++) {
        prod[i].coef = 0;
        prod[i].exp = i;
    }

    // Triple ciclo para multiplicar término a término
    for(int i=0; i<=2; i++){
        for(int j=0; j<=1; j++){
            for(int k=0; k<=2; k++){
                int nuevoCoef = pol1[i].coef * pol2[j].coef * pol3[k].coef;
                int nuevoExp = pol1[i].exp + pol2[j].exp + pol3[k].exp;
                
                // El índice en el arreglo prod es: gradoMax - nuevoExp
                prod[gradoMax - nuevoExp].coef += nuevoCoef;
            }
        }
    }
    return prod;
}

void imprimir(Polinomio *pol, int n){
    for(int i=n; i>=n; i--){
        if(pol[i].coef != 0){
            cout<<pol[i].coef<<"x^"<<pol[i].exp;
            if(i>0) cout<<" + ";
        }
    }
    cout<<endl;
}

int main(){

    //Reservar la memoria 
    Polinomio *Pol1 = new Polinomio[3]; //correcion de la memoria asignada 
    Polinomio *Pol2 = new Polinomio[2]; //correcion de la memoria asignada 
    Polinomio *Pol3 = new Polinomio[3]; //correcion de la memoria asignada 

    Pol1[0] = {3,0};
    Pol1[1] = {0,1};
    Pol1[2] = {1,2};

    Pol2[0] = {5,0};
    Pol2[1] = {-4,1};

    Pol3[0] = {1,0};
    Pol3[1] = {0,1};
    Pol3[2] = {3,2};

    //Llamar la operacion suma
    Polinomio *SumaPol = sumaPolinomio(Pol1,Pol2, Pol3);

    //LLamar la operacion producto
    Polinomio *ProdPol = Producto(Pol1,Pol2,Pol3);

    cout<<"Polinomio 1: ";
    imprimir(Pol1,2);

    cout<<"Polinomio 2: ";
    imprimir(Pol2,1);

    cout<<"Polinomio 3: ";
    imprimir(Pol3,2);

    cout<<"Suma de los tres Polinomios: ";
    imprimir(SumaPol,2);
    cout << "Producto de los tres: "; imprimir(ProdPol, 5);

    // Liberacion de la memoria 
    delete[] Pol1;
    Pol1 = nullptr;
    delete[] Pol2;
    Pol2= nullptr;
    delete[] Pol3;
    Pol3=nullptr;
    delete[] SumaPol;
    SumaPol = nullptr;
    delete[] ProdPol;
    ProdPol = nullptr;
};

