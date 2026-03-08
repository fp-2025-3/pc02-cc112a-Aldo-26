#include<iostream>
#include<cstring>
using namespace std;

class protected{
    private:
        string id;
        double *posicion;

    public:
    Sensor(string _id, double x, double y) {
        id = _id;
        posicion = new double[2];
        posicion[0] = x;
        posicion[1] = y;
    }
    
    virtual ~Sensor() { 
        delete[] posicion; 
    }

    virtual double areaCobertura() const = 0;
    virtual bool detecta(double x, double y) const = 0;
    
    virtual void imprimir() const {
        cout << "ID: " << id << " | Posicion: (" << posicion[0] << ", " << posicion[1] << ")";
    }

    string getId() const { return id; }
};

class SensorCircular : public Sensor {
    double radio;
public:
    SensorCircular(string _id, double x, double y, double r) : Sensor(_id, x, y), radio(r) {}
    
    double areaCobertura() const override { return 3.14159 * radio * radio; }
    
    bool detecta(double x, double y) const override {
        double dist = sqrt(pow(x - posicion[0], 2) + pow(y - posicion[1], 2));
        return dist <= radio;
    }
    
    void imprimir() const override {
        Sensor::imprimir();
        cout << " | Tipo: Circular | Radio: " << radio << " | Area: " << areaCobertura() << endl;
    }
};

class SensorRectangular : public Sensor {
    double ancho, alto;
public:
    SensorRectangular(string _id, double x, double y, double an, double al) 
        : Sensor(_id, x, y), ancho(an), alto(al) {}

    double areaCobertura() const override { return ancho * alto; }

    bool detecta(double x, double y) const override {
        return (x >= posicion[0] && x <= posicion[0] + ancho &&
                y >= posicion[1] && y <= posicion[1] + alto);
    }

    void imprimir() const override {
        Sensor::imprimir();
        cout << " | Tipo: Rectangular | Dim: " << ancho << "x" << alto << " | Area: " << areaCobertura() << endl;
    }
};

class SistemaSensores {
    Sensor** sensores; 
    int cantidad;
    int capacidad;
public:
    SistemaSensores(int cap) : capacidad(cap), cantidad(0) {
        sensores = new Sensor*[capacidad];
    }
    
    ~SistemaSensores() {
        for(int i = 0; i < cantidad; i++) {
            delete sensores[i];
        }
        delete[] sensores;
    }

    void agregarSensor(Sensor* s) {
        if (cantidad == capacidad) {
            capacidad *= 2;
            Sensor** nuevo = new Sensor*[capacidad];
            for(int i = 0; i < cantidad; i++) {
                nuevo[i] = sensores[i];
            }
            delete[] sensores;
            sensores = nuevo;
            cout << "(Sistema: Capacidad aumentada a " << capacidad << ")" << endl;
        }
        sensores[cantidad++] = s;
    }

    void mostrarTodos() const {
        cout << "\n--- Inventario de Sensores ---" << endl;
        for(int i = 0; i < cantidad; i++) {
            sensores[i]->imprimir();
        }
    }

    void verificarPunto(double x, double y) const {
        cout << "\nEscaneando punto (" << x << ", " << y << "):" << endl;
        bool deteccion = false;
        for(int i = 0; i < cantidad; i++) {
            if (sensores[i]->detecta(x, y)) {
                cout << "  > Detectado por: " << sensores[i]->getId() << endl;
                deteccion = true;
            }
        }
        if (!deteccion) cout << "  > Sin detecciones en esta zona." << endl;
    }
};

int main(){

    SistemaSensores sistema(2);

    sistema.agregarSensor(new SensorCircular("C_1", 0, 0, 10));
    sistema.agregarSensor(new SensorRectangular("R_2", 5, 5, 10, 5));
    sistema.agregarSensor(new SensorCircular("C_3", -2, -2, 3));

    sistema.mostrarTodos();

    sistema.verificarPunto(1, 1);   
    sistema.verificarPunto(12, 7);   
    sistema.verificarPunto(50, 50);  

    return 0;
}
