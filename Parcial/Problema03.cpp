#include<iostream>
using namespace std;

const int N = 4;

bool esFilaDominanteEstricta(int (*M)[N], int f) {
    for (int j = 0; j < N; j++) { 
        int valorFilaF = *(*(M + f) + j); 
        for (int i = 0; i < N; i++) { 
            if (i == f) continue; 
            
            if (*(*(M + i) + j) >= valorFilaF) {
                return false;
            }
        }
    }
    return true;
}

bool esFilaFuerteDominante(int (*M)[N], int f) {
    int sumaFilaF = 0;
    
    for (int j = 0; j < N; j++) {
        sumaFilaF += *(*(M + f) + j);
    }

    for (int i = 0; i < N; i++) {
        if (i == f) continue;

        int sumaOtraFila = 0;
        for (int j = 0; j < N; j++) {
            sumaOtraFila += *(*(M + i) + j);
        }

        if (sumaOtraFila >= sumaFilaF) {
            return false;
        }
    }
    return true;
}

int main() {

    int M[N][N] = {
        {2, 3, 1, 4},
        {1, 2, 3, 2},
        {9, 9, 9, 9}, 
        {0, 1, 2, 1}
    };

    cout << "Fila   Dominante Estricta      Fueretemente Dominante" << endl;
    cout << "--------------------------------------------------" << endl;

    for (int i = 0; i < N; i++) {
        cout << i << ": ";
        
        if (esFilaDominanteEstricta(M, i)){
            cout << "\tSi\t\t";
        }else{
            cout << "\tNo\t\t";
        }

        if (esFilaFuerteDominante(M, i)){
            cout << "\tSi\t\t";
        }else{
            cout << "\tNo\t\t";
        }
            
        cout << endl;
    }

    return 0;
}
