#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
using namespace std;

vector<char> obtenerAlfabeto(string lineaActual){
    vector<char> alfabeto;
    for(int i = 0; i < lineaActual.size(); i++){
        alfabeto.push_back(lineaActual[i]);
    }
    return alfabeto;
}

int main() {

    fstream miArchivo("texto.txt");
    string lineaActual;
    int numeroDeEstados = 0;
    vector<char> alfabeto;
    bool pasoPrimeraLinea = false;


    if(miArchivo.is_open()){

        while (getline(miArchivo, lineaActual)) {        
            cout << lineaActual << endl;
            numeroDeEstados++;
            if (!pasoPrimeraLinea) {
                pasoPrimeraLinea = true;
                alfabeto = obtenerAlfabeto(lineaActual);
            }
        }
    } else {
        cout << "El archivo no se puede abrir. " << endl;
    }

    int numeroSimbolosAlfabeto = alfabeto.size() - 1;
    numeroDeEstados--;


    cout << "El alfabeto es: " << endl;
    for(int i = 0; i < numeroSimbolosAlfabeto; i++){
        cout << alfabeto[i] << endl;
    }


    cout << "Simbolos del alfabeto: " << numeroSimbolosAlfabeto << endl;
    cout << "Numero de estados del automata: " << numeroDeEstados << endl;

    
}