#include "afd.h"

/*string obtenerAlfabeto(string textoLinea){
    string alfabeto;
    for(int i = 0; i < textoLinea.size(); i++){
        if(textoLinea[i] != 32){
            alfabeto += textoLinea[i];
            cout << "Agregando: " <<textoLinea[i] << " a la cadena: " << alfabeto << endl;
        }
    }
    cout << "La cadena resultante es " << alfabeto << " asies" << endl;
    return alfabeto;
}*/

Estado obtenerDatosAFD(string textoLinea){
    
    string nombreEstado;
    Estado estadoActual;
    bool seAsignoElPrimero = false;

    int caracteresDesplazados;

        if(textoLinea[0] == '*'){
            estadoActual.esDeAceptacion = true;
            caracteresDesplazados = 1;
        } else {
            estadoActual.esDeAceptacion = false;
            caracteresDesplazados = 0;
        }

    for(int i = caracteresDesplazados; i < textoLinea.length(); i++){
        if(textoLinea[i] != 32){
            nombreEstado += textoLinea[i];
            if(textoLinea[i] != 'q'){
                estadoActual.estadosConLosQueChoca.push_back(nombreEstado);
                if(!seAsignoElPrimero){
                    estadoActual.nombreEstadoActual = nombreEstado;
                    seAsignoElPrimero = true;
                    estadoActual.estadosConLosQueChoca.erase(estadoActual.estadosConLosQueChoca.begin());
                }
                nombreEstado = "";
            }
        }
        
    }
    return estadoActual;
 }