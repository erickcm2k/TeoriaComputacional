#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Estado {
    bool esDeAceptacion;
    string nombreEstadoActual;
    vector<string> estadosConLosQueChoca;
};


int main() {

    fstream miArchivo("texto.txt");
    string lineaActual;
    int numeroDeEstados = 0;
    vector<char> alfabeto;
    bool pasoPrimeraLinea = false;
    vector<Estado> estadosDelAutomata;

    if(miArchivo.is_open()){

        while (getline(miArchivo, lineaActual)) {        
            cout << lineaActual << endl;
            numeroDeEstados++;
 
            if (!pasoPrimeraLinea){
                pasoPrimeraLinea = true;
                cout << "Por ahora no hara nada." << endl;
            } else {
                // Ingreso de datos del AFD
                Estado estadoActual;
                if(lineaActual[0] == '*'){
                    estadoActual.esDeAceptacion = true;
                }
                for(int i = 0; i < lineaActual.size(); i++){
                    if(estadoActual.esDeAceptacion)
                        i++;

                    strin
                  
                }
                //estadoActual.esDeAceptacion = true;
                estadoActual.nombreEstadoActual = "q2";
                estadoActual.estadosConLosQueChoca.push_back("q1");
                estadoActual.estadosConLosQueChoca.push_back("q2");
                estadoActual.estadosConLosQueChoca.push_back("q3");
                estadoActual.estadosConLosQueChoca.push_back("q4");
                estadoActual.estadosConLosQueChoca.push_back("q5");
                estadosDelAutomata.push_back(estadoActual);             
            }

        }
    } else {
        cout << "El archivo no se puede abrir. " << endl;
    }

    cout << "Informacion del primer nodo del AFD" << endl;

    cout << "Es de aceptacion (0/1): " << estadosDelAutomata[0].esDeAceptacion << endl;
    cout << "Identificador del estado: " << estadosDelAutomata[0].nombreEstadoActual << endl;
    cout << "Estados con los que choca: " << endl;
    for(int i = 0; i < estadosDelAutomata[0].estadosConLosQueChoca.size(); i++){
        cout << estadosDelAutomata[0].estadosConLosQueChoca[i] << " ";
    }



    
}