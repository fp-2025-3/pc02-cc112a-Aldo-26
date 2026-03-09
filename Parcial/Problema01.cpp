#include <iostream>

using namespace std;


long long obtenerCostoMaximo(int A[], int n, int pos) {
    if (pos == n) {
        return 0;
    }

    long long maxCostoTotal = -1;
    long long productoSegmentoActual = 1;

    for (int i = pos; i < n; i++) {
        productoSegmentoActual *= A[i];

        long long costoDeEstaDivision = productoSegmentoActual + obtenerCostoMaximo(A, n, i + 1);

        if (costoDeEstaDivision > maxCostoTotal) {
            maxCostoTotal = costoDeEstaDivision;
        }
    }

    return maxCostoTotal;
}

int main() {
    int A[] = {1, 2, 3, 4, 5};
    int n = 5;

    cout << "Costo maximo para [1,2,3,4,5]: " << obtenerCostoMaximo(A, n, 0) << endl;

    int B[] = {2, 1, 3};
    cout << "Costo maximo para [2,1,3]: " << obtenerCostoMaximo(B, 3, 0) << endl;

    return 0;
}
