#include <iostream>

using namespace std;


bool esPico(int (*matriz)[5], int filas, int cols, int i, int j) {
    
    int centro = *(*(matriz + i) + j);

    bool mayorOIgual = true;       
    bool estrictamenteMayor = false; 


    if ((i - 1) >= 0) {
        int valArriba = *(*(matriz + (i - 1)) + j);
        if (centro < valArriba) mayorOIgual = false;
        if (centro > valArriba) estrictamenteMayor = true;
    }

    if ((i + 1) < filas) {
        int valAbajo = *(*(matriz + (i + 1)) + j);
        if (centro < valAbajo) mayorOIgual = false;
        if (centro > valAbajo) estrictamenteMayor = true;
    }

    if ((j - 1) >= 0) {
        int valIzq = *(*(matriz + i) + (j - 1));
        if (centro < valIzq) mayorOIgual = false;
        if (centro > valIzq) estrictamenteMayor = true;
    }

    if ((j + 1) < cols) {
        int valDer = *(*(matriz + i) + (j + 1));
        if (centro < valDer) mayorOIgual = false;
        if (centro > valDer) estrictamenteMayor = true;
    }

    return mayorOIgual && estrictamenteMayor;
}

void encontrarPicos(int (*matriz)[5], int filas, int cols) {
    cout << "Elementos pico:" << endl;
    
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < cols; j++) {
            
            if (esPico(matriz, filas, cols, i, j)) {
                int valor = *(*(matriz + i) + j);
                cout << "Pico en (" << i << ", " << j << "): " << valor << endl;
            }
        }
    }
}

int main() {

    int A[4][5] = {
        {3, 3, 3, 3, 3},
        {3, 4, 4, 2, 3},
        {3, 4, 5, 4, 3},
        {3, 3, 3, 3, 3}
    };

    int (*ptr)[5] = A;

    cout << "Matriz:" << endl;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 5; j++) {

            cout << *(*(ptr + i) + j) << "\t";
        }
        cout << endl;
    }
    cout << "------------------" << endl;

    encontrarPicos(ptr, 4, 5);

    return 0;
}
