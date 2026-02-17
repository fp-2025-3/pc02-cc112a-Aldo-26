#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

struct Seleccion{
    int id;
    int PG;
    int PE;
    int PP;
    int GF;
    int GC;
    int dif;
    int punt;
    float rend;
};

//Llenar la seleccion
void llenarSeleccion(Seleccion *sel){

    for(int i = 0; i < 5; i++){
        //Guara la ubicacion 
        sel[i].id = i + 1;

        //Simulacion de los 100 partidos
        int temp1 = 0;
        temp1 = rand() % 100;
        sel[i].PG = temp1;

        int temp2 = 0;
        temp2 = rand()% (100- temp1);
        sel[i].PE = temp2;

        int temp3 = 0;
        temp3 = 100 - temp1 - temp2;
        sel[i].PP = temp3;

        //Simulacion de goles basada en el desempeño
        int sum1 = 0;
        int sum2 = 0;
        for(int j=0; j<100; j++){
            if(sel[i].PG > sel[i].PP){
                sum1 += rand() % 4;    //Mas goles a favor 
                sum2 += rand() % 2;
            }else{
                sum1 += rand() % 2;    
                sum2 += rand() % 4;    //Mas goles en contra
                }
            }
        sel[i].GF = sum2;
        sel[i].GC = sum1;
        sel[i].dif = sum1 - sum2;

        //Rendimiento y puntaje
        sel[i].punt = 3*sel[i].PG + sel[i].PE;
        sel[i].rend = (3*sel[i].PG + sel[i].PE)/3.0;
    }

}

//Ordenar la seleccion
void ordenar(Seleccion *sel){
    //Uso un algoritmo burbuja para ordenarlo
    for(int i=0; i<5; i++){
        for(int j=0; j < 5 - i - 1; j++){
            if(sel[j].punt < sel[j+1].punt){   //Correccion el orden de forma creciente 
                swap(sel[j],sel[j+1]);    /* Se puede intercambiar la estructura
                                            swap(sel[j].id,sel[j+1].id);
                                            swap(sel[j].PG, sel[j+1].PG);
                                            swap(sel[j].PE, sel[j+1].PE);
                                            swap(sel[j].PP, sel[j+1].PP);
                                            swap(sel[j].GF, sel[j+1].GF);
                                            swap(sel[j].GC, sel[j+1].GC);
                                            swap(sel[j].dif, sel[j+1].dif);
                                            swap(sel[j].punt, sel[j+1].punt);
                                            swap(sel[j].rend, sel[j+1].rend); */
                                            
            }
        }
    }
}

//Imprime la seleccion
void imprimirSeleccion(Seleccion *sel){

    cout<<"Seleccion\tPG\tPE\tPP\tGF\tGC\tDG\tpts\trend(%)"<<endl;
    cout<<"---------------------------------------------------------------------"<<endl;
    for(int i=0; i<5; i++){
        cout<<"Pais_"<<sel[i].id<<"\t\t"<<sel[i].PG<<"\t"<<sel[i].PE<<"\t"<<sel[i].PP<<"\t"<<sel[i].GF
        <<"\t"<<sel[i].GC<<"\t"<<sel[i].dif<<"\t"<<sel[i].punt<<"\t"<<sel[i].rend<<endl;
    }
    cout<<endl;
}

void buscarCampeon(Seleccion *sel){
    
    int j = 0;    //Guarda el indice maximo
    int temp = 0;    //Guarda el puntaje temporal

    //Usa una busqueda lineal para hallar el campeon
    for(int i=0; i<5; i++){
         if(sel[i].punt > temp){ //Compara los puntaje hasta encontar el puntaje mayor
            j = i;    //Guarda el indice maximo
            temp = sel[i].punt;    //Puntaje temporal es guardado para encontrar el mayor 
        }  
    }

    //Imprime el campeon
    cout<<"CAMPEON ES: PAIS_"<<sel[j].id<<" | "<<sel[j].PG<<" | "<<sel[j].PE<<" | "<<sel[j].GF
        <<" | "<<sel[j].GC<<" | "<<sel[j].dif<<" | "<<sel[j].punt<<" | "<<sel[j].rend<<endl;
}

int main(){
    //Se crea el arreglo dinamico 
    Seleccion *sel = new Seleccion[5];

    
    srand(time(NULL));    //Se inicia la generacion de los numeros reales 

    //Llamado de la funciones
    llenarSeleccion(sel);   
    imprimirSeleccion(sel);
    
    ordenar(sel);
    
    imprimirSeleccion(sel);
    buscarCampeon(sel);
    
    //Liberacion de la memoria
    delete[] sel;
    sel = nullptr;

    return 0;
}
