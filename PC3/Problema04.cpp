#include <iostream>

using namespace std;

int construir_indice(char* texto, char** indice) {
    int n = 0;
    char* p = texto;
    bool enPalabra = false;
#include <iostream>

using namespace std;

int construir_indice(char* texto, char** indice) {
    int n = 0;
    char* p = texto;
    bool enPalabra = false;

    while (*p != '\0') {
        if (*p != ' ') {
            if (!enPalabra) {
                *(indice + n) = p; 
                n++;
                enPalabra = true;
            }
        } else {
            enPalabra = false;
        }
        p++;
    }
    return n;
}

int comparar(const char* a, const char* b) {
    while (*a != '\0' && *a != ' ' && *b != '\0' && *b != ' ' && *a == *b) {
        a++;
        b++;
    }
    int v1 = *a;
    int v2 = *b;
    if (v1 == ' ') v1 = 0;
    if (v2 == ' ') v2 = 0;
    return v1 - v2;
}

void ordenar_indice(char** indice, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (comparar(*(indice + j), *(indice + j + 1)) > 0) {
                char* temp = *(indice + j);
                *(indice + j) = *(indice + j + 1);
                *(indice + j + 1) = temp;
            }
        }
    }
}

void imprimir_indice(char* texto, char** indice, int n) {
    for (int i = 0; i < n; i++) {
        char* p = *(indice + i);
        
        char* aux = p;
        while (*aux != '\0' && *aux != ' ') {
            cout << *aux;
            aux++;
        }

        cout << "\t(posicion " << (int)(p - texto) << ")" << endl;
    }
}

int main() {
    char texto[300] = "los punteros no se copian se referencian y se ordenan";
    char* indice[60];

    int n = construir_indice(texto, indice);
    ordenar_indice(indice, n);
    imprimir_indice(texto, indice, n);

    return 0;
}
    while (*p != '\0') {
        if (*p != ' ') {
            if (!enPalabra) {
                *(indice + n) = p; 
                n++;
                enPalabra = true;
            }
        } else {
            enPalabra = false;
        }
        p++;
    }
    return n;
}

int comparar(const char* a, const char* b) {
    while (*a != '\0' && *a != ' ' && *b != '\0' && *b != ' ' && *a == *b) {
        a++;
        b++;
    }
    int v1 = *a;
    int v2 = *b;
    if (v1 == ' ') v1 = 0;
    if (v2 == ' ') v2 = 0;
    return v1 - v2;
}

void ordenar_indice(char** indice, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (comparar(*(indice + j), *(indice + j + 1)) > 0) {
                char* temp = *(indice + j);
                *(indice + j) = *(indice + j + 1);
                *(indice + j + 1) = temp;
            }
        }
    }
}

void imprimir_indice(char* texto, char** indice, int n) {
    for (int i = 0; i < n; i++) {
        char* p = *(indice + i);
        
        char* aux = p;
        while (*aux != '\0' && *aux != ' ') {
            cout << *aux;
            aux++;
        }

        cout << "\t(posicion " << (int)(p - texto) << ")" << endl;
    }
}

int main() {
    char texto[300] = "los punteros no se copian se referencian y se ordenan";
    char* indice[60];

    int n = construir_indice(texto, indice);
    ordenar_indice(indice, n);
    imprimir_indice(texto, indice, n);

    return 0;
}
