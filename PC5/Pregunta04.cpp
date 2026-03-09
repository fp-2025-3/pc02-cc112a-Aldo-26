#include <iostream>
#include <fstream>
using namespace std;

struct Venta {
    int idVenta;
    int idVendedor;
    int idProducto;
    int cantidad;
    double precioUnitario;
};

// Función para contar registros en un archivo binario
int contarRegistros(const char* nombreArchivo) {
    ifstream archivo(nombreArchivo, ios::binary | ios::ate);
    if (!archivo) return 0;
    int tam = archivo.tellg();
    archivo.close();
    return tam / sizeof(Venta);
}

// Función para encontrar el ID máximo
void encontrarMaximos(Venta* v, int n, int& maxVend, int& maxProd) {
    maxVend = 0; maxProd = 0;
    for (int i = 0; i < n; i++) {
        if (v[i].idVendedor > maxVend) maxVend = v[i].idVendedor;
        if (v[i].idProducto > maxProd) maxProd = v[i].idProducto;
    }
}

int main() {
    const char* fileBin = "ventas.dat";
    int n = contarRegistros(fileBin);

    if (n == 0) {
        cout << "El archivo no existe o esta vacío." << endl;
        return 1;
    }

    // 1. Cargar datos con memoria dinámica
    Venta* ventas = new Venta[n];
    ifstream archivo(fileBin, ios::binary);
    archivo.read((char*)ventas, n * sizeof(Venta));
    archivo.close();

    // 2. Cálculos principales
    double montoTotal = 0;
    int idMaxVend, idMaxProd;
    encontrarMaximos(ventas, n, idMaxVend, idMaxProd);

    double* recaudacionVendedor = new double[idMaxVend + 1]{0};
    int* cantidadProducto = new int[idMaxProd + 1]{0};

    for (int i = 0; i < n; i++) {
        double subtotal = ventas[i].cantidad * ventas[i].precioUnitario;
        montoTotal += subtotal;
        recaudacionVendedor[ventas[i].idVendedor] += subtotal;
        cantidadProducto[ventas[i].idProducto] += ventas[i].cantidad;
    }

    // Determinar mejores
    int mejorVendedor = 0;
    for (int i = 1; i <= idMaxVend; i++) {
        if (recaudacionVendedor[i] > recaudacionVendedor[mejorVendedor])
            mejorVendedor = i;
    }

    int mejorProducto = 0;
    for (int i = 1; i <= idMaxProd; i++) {
        if (cantidadProducto[i] > cantidadProducto[mejorProducto])
            mejorProducto = i;
    }

    // 3. Generar Reporte
    ofstream reporte("reporte.txt");
    reporte.setf(ios::fixed);
    reporte.precision(2);

    reporte << "--- REPORTE GENERAL DE VENTAS ---" << endl;
    reporte << "Total de registros: " << n << endl;
    reporte << "MONTO TOTAL VENDIDO: S/. " << montoTotal << endl;
    reporte << "VENDEDOR CON MAYOR RECAUDACION: ID Vendedor: " << mejorVendedor
            << " | Total vendido: S/. " << recaudacionVendedor[mejorVendedor] << endl;
    reporte << "PRODUCTO MAS VENDIDO: ID Producto: " << mejorProducto
            << " | Total unidades: " << cantidadProducto[mejorProducto] << endl;

    reporte << "\nVENTAS SOSPECHOSAS (cantidad > 100):" << endl;
    for (int i = 0; i < n; i++) {
        if (ventas[i].cantidad > 100) {
            reporte << "ID Venta: " << ventas[i].idVenta
                    << " | Vendedor: " << ventas[i].idVendedor
                    << " | Producto: " << ventas[i].idProducto
                    << " | Cantidad: " << ventas[i].cantidad << endl;
        }
    }

    reporte.close();
    cout << "Reporte generado con exito en reporte." << endl;

    // 4. Liberar memoria
    delete[] ventas;
    delete[] recaudacionVendedor;
    delete[] cantidadProducto;

    return 0;
}
