// Librerias utilizadas
#include "iostream"
#include "fstream"
using namespace std;

// Funciones secundarias
void escibirArchivo(string nombreArchivo);

// Función principal
using namespace std;

int main(){ 

//  escibirArchivo("texto1.txt");

    string nuevaCadena;
    ifstream MyFileRead("texto.txt");

    if(MyFileRead.is_open()){
        while(getline(MyFileRead, nuevaCadena))
                cout << nuevaCadena << endl;
    } else {
        cout << "El archivo solicitado no existe o el nombre esta mal escrito." << endl;
    }


}

void escibirArchivo(string nombreArchivo){

    ofstream tablaTransicion(nombreArchivo);

    if(tablaTransicion.is_open()){
        for(int i = 0; i < 10; i++)
            tablaTransicion << i << endl;
    } else {
        cout << "El archivo solicitado no existe o el nombre esta mal escrito." << endl;
    }

    tablaTransicion.close();
}