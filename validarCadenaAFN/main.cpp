#include "afd.h"

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
            cout << "Nombre estado: " << automata.estados[i].nombreEstado << endl;
            cout << "Es de aceptacion (0/1): " << automata.estados[i].esDeAceptacion << endl;
            cout << "Estados con los que choca: ";
            for(int j = 0; j < automata.estados[i].estadosConLosQueChoca.size(); j++){
                cout << automata.estados[i].estadosConLosQueChoca[j] << " ";
            }
            cout << "\n";
        }   

        // Prueba si una cadena es valida dentro del alfabeto
        string cadenaPrueba = "00110101";
        // if(caracteresSonValidos(automata.estados, cadenaPrueba, automata.alfabeto)){
        //     cout << "\nLos simbolos de la cadena son validos. " << endl;
        //     cout << "Se procedera a probar la cadena con los datos ingresados." << endl;
        //     cadenaEsValida(automata);
        // } else {
        //     cout << "\nLos simbolos de la cadena no pertenecen al alfabeto. " << endl;
        // }
        cout << buscarPosicionCaracter('0',automata.alfabeto) << endl;
        if(cadenaEsValida(automata, cadenaPrueba)) {
            cout << "La cadena es correcta" << endl;
        } else {
            cout << "La cadena es incorrecta" << endl;
        }



    } else {
        cout << "El archivo no se puede abrir. " << endl;
        cout << "Es posible que no exista o que el nombre este mal escrito. \n" << endl;
    }
    return 0;
}