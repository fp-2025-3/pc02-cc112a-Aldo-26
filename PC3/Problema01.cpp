#include <iostream>
using namespace std;

void suma(char* p, int k) {
    int valores[10]; 
    int n = 0;
    
    char* aux = p;
    while (*aux != '\0') {
        if (*aux >= '0' && *aux <= '9') {
            int num = 0;

            while (*aux >= '0' && *aux <= '9') {
                num = (num * 10) + (*aux - '0');
                aux++;
            }
            valores[n] = num;
            n++;
        } else {
            aux++; 
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (valores[i] + valores[j] == k) {
                cout << "Encontrado: " << valores[i] << " + " << valores[j] << " = " << k << endl;
            }
        }
    }
}

int main() {
    char texto[] = "1,2,4,7,11"; 
    int k = 15; 

    suma(texto, k);

    return 0;
}
