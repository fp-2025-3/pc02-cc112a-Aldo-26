#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

int main(){
    const int FILAS = 21;
    const int COLUMNAS = 80;
    const double PI = 3.141592653589793;
    
    // Crear un lienzo 
    char lienzo[FILAS][COLUMNAS];
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            lienzo[i][j] = ' ';
        }
    }

    // 1. Dibujar el eje x en la fila central
    for (int j = 0; j < COLUMNAS; j++) {
        lienzo[10][j] = '-';
    }

    // 2. Dibujar el eje y en la primera columna 
    for (int i = 0; i < FILAS; i++) {
        lienzo[i][0] = '|';
    }

    // 3. Evaluar la función y ubicar los puntos '*'
    for (int i = 0; i < COLUMNAS; i++) {
        // x va de 0 a 2*PI distribuido en 80 columnas
        double x = (double)i * (2.0 * PI / (COLUMNAS - 1));
        double y_val = sin(5 * x);

        // Mapear los valores de y pertenciente de [-1, 1] al rango de filas 
        // y = 1 es fila 0, y = 0 es fila 10, y = -1 es fila 20
        int fila = (int)round(10 - (y_val * 10));

        // Asegurar que el punto este dentro de los límites y dibujar
        if (fila >= 0 && fila < FILAS) {
            lienzo[fila][i] = '*';
        }
    }

    // 4. Guardar el lienzo en el archivo grafico.txt
    ofstream grafica("grafico.txt");

    if(!grafica){
        cout << "No se pudo abrir el archivo";
        return 1;
    }
    
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            grafica << lienzo[i][j];
        }
        grafica << endl;
    }

    grafica.close();
    cout << "Grafico generado exitosamente en 'grafico.txt'." << endl;
    
    return 0;
}
