#include "afd.h"
using namespace std;

int main() {

    string nombreArchivo;
    cout << "Ingresa el nombre del archivo de texto: "; cin >> nombreArchivo;
    nombreArchivo += ".txt";
    cout << endl;
    fstream miArchivo(nombreArchivo);

    string lineaActual = "";
    int numeroDeEstados = 0;
    //string alfabeto;
    bool pasoPrimeraLinea = false;
    Estado estadoActual;
    vector<Estado> estadosObtenidos;
    AFD automata;

    if(miArchivo.is_open()){
        while (getline(miArchivo, lineaActual)) {        
            numeroDeEstados++;
            if (!pasoPrimeraLinea) {
                pasoPrimeraLinea = true;
                //alfabeto = (string)lineaActual;//= obtenerAlfabeto(lineaActual);
                automata.alfabeto = lineaActual;
            } else {
                estadoActual = obtenerDatosAFD(lineaActual);
                estadosObtenidos.push_back(estadoActual);
            }
        }
        automata.estados = estadosObtenidos;
        numeroDeEstados--;

         // Informacion unicamente
        cout << "Los simbolos del alfabeto son: " << endl;
        for(int i = 0; i < automata.alfabeto.length(); i++) {
            cout << automata.alfabeto.at(i) << endl;
        }

        // Imprime la informacion del automata
        for(int i = 0; i < automata.estados.size(); i++){

            cout << "Elemento numero " << i << " del automata ingresado." << endl;
            cout << "Nombre estado: " << automata.estados[i].nombreEstadoActual << endl;
            cout << "Es de aceptacion (0/1): " << automata.estados[i].esDeAceptacion << endl;
            cout << "Estados con los que choca: ";
            for(int j = 0; j < automata.estados[i].estadosConLosQueChoca.size(); j++){
                cout << automata.estados[i].estadosConLosQueChoca[j] << " ";
            }
            cout << "\n\n";
        }   

        // Prueba si una cadena es valida dentro del alfabeto
        string cadenaPrueba = "1010a1";
        if(cadenaEsValida(automata.estados, cadenaPrueba, automata.alfabeto)){
            cout << "\nLos simbolos de la cadena son validos. " << endl;
        } else {
            cout << "\nLos simbolos de la cadena no pertenecen al alfabeto. " << endl;
        }

    } else {
        cout << "El archivo no se puede abrir. " << endl;
        cout << "Es posible que no exista o que el nombre este mal escrito. \n" << endl;
    }
}