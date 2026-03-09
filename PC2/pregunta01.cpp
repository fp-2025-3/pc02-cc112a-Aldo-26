#include <iostream>
using namespace std;

// Complete la funcion que calcula la derivada de orden k de un polinomio
// Usar EXCLUSIVAMENTE punteros (NO indices)

void derivadaK(const double* coef, int grado, int k, double* res, int& gradoRes) {
    
    const double *p = coef;
    double * resultado = res;

    for(int i=0; i<grado; i++){
        *(resultado + i) = *(p+i);
    }
    
    for (int i = k; i <= grado; i++) {
        int temp = *(resultado + i); 
        
        for (int j = 0; j < k; j++) {
            temp *= (i - j);
        }
        
        *(resultado + (i - k)) = temp;
    }

    for (int i = (grado - k + 1); i <= grado; i++) {
        *(resultado + i) = 0;
    }

    gradoRes = grado - k - 1;
}

// Complete la función auxiliar para imprimir un polinomio
void imprimirPolinomio(const double* p, int grado) {
   for(int i=0; i<grado + 1; i++){
    cout<<*(p+i)<<"x^"<<i;
        if(i<grado){
            cout<<" + ";
        }
   }
}

int main() {
    // Polinomio:
    // P(x) = 2 + 3x - x^2 + 4x^3
    double coef[] = {2, 3, -1, 4};
    const int grado = 3;

    double resultado[10] = {0}; // espacio suficiente
    int gradoResultado = 0;

    int k = 2; // derivada de orden 2

    cout<<"Polinomio original: "<<endl;
    imprimirPolinomio(coef,grado);

    // Llamar a su funcion derivadaK
    derivadaK(coef,grado+1,k,resultado,gradoResultado);


    cout<<"\nDerivada de orden "<<k<<endl;
    // Llamar la funcion imprimir para mostrar el polinomio original y  la derivada
    imprimirPolinomio(resultado,gradoResultado);

    return 0;
}
