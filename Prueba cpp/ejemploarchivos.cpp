#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(void) {

    fstream miArchivo("texto.txt");
    string linea;
    vector<char> alfabeto;
    bool noPasoPorPrimeraLinea = true;

    if(miArchivo.is_open()){

        while (getline(miArchivo, linea)) {        
            cout << linea << endl;
            if(noPasoPorPrimeraLinea == true){

                for(int i = 0; i < linea.size(); i++){
                    alfabeto.push_back(linea[i]);
                    //cout << "Linea: " <<linea[i] << " Alfabeto: " <<alfabeto[i] << endl;
                }
                noPasoPorPrimeraLinea = false;
            }
        }
    } else {
        cout << "El archivo no se puede abrir. " << endl;
    }

    cout << "El alfabeto es: " << endl;
    for(int i = 0; i < alfabeto.size() - 1; i++){
        cout << alfabeto[i] << endl;
    }
    
}