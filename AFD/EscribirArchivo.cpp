#include "iostream"
#include "fstream"
using namespace std;

void leerTablaTransicion(string nombreArchivo){

    ofstream tablaTransicion(nombreArchivo);

    if(tablaTransicion.is_open()){
        for(int i = 0; i < 10; i++)
            tablaTransicion << i << endl;
    } else {
        cout << "El archivo solicitado no existe o esta mal escrito." << endl;
    }
    
    tablaTransicion.close();
}

