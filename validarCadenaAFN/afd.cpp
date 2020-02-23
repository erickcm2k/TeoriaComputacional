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
                    estadoActual.nombreEstado = nombreEstado;
                    seAsignoElPrimero = true;
                    estadoActual.estadosConLosQueChoca.erase(estadoActual.estadosConLosQueChoca.begin());
                }
                nombreEstado = "";
            }
        }
    }
    return estadoActual;
 }

bool perteneceAlAlfabeto(char simbolo, string alfabeto){
    int caracteresValidos = 0;
    for(int i = 0; i < alfabeto.length(); i++){
        if(simbolo == (char)alfabeto[i]){
            caracteresValidos++;
        } 
    }
   if(caracteresValidos == 1){
       return true;
   } else {
       return false;
   }
}

bool caracteresSonValidos(vector<Estado> estadosDelAutomata,string cadenaPrueba, string alfabeto){
        bool esValida = false;
        int validaciones = 0;

        cout << "La cadena a evaluar es: " << cadenaPrueba << endl;
        for(int i = 0; i < cadenaPrueba.length(); i++){
        // Revisar que el alfabeto sea correcto
            if(perteneceAlAlfabeto((char)cadenaPrueba[i], alfabeto))
                validaciones++;
        }
        validaciones == cadenaPrueba.length() ? esValida = true : esValida = false;

    return esValida;
}

bool verificarEstadoPertenezca(AFD automata, int indiceEstado, string nombreEstadoAComprobar) {
    bool pertenece;
    int verificaciones = 0;
    for(int i = 0; i < automata.estados[indiceEstado].estadosConLosQueChoca.size() ; i++) {
        if(nombreEstadoAComprobar == automata.estados[indiceEstado].estadosConLosQueChoca[i]) {
            verificaciones++;
        }
    }

    if(verificaciones > 0) {
        return true;
    } else {
        return false;
    }

}

bool esDeAceptacion(AFD automata, int indiceEstado) {
    if(automata.estados[indiceEstado].esDeAceptacion) {
        return true;
    } else {
        return false;
    }
}

bool cadenaEsValida(AFD automata, string cadenaPrueba){
    int numeroEstados = automata.estados.size();
    int validaciones = 0;
    string estadoInicial = automata.estados[0].nombreEstado;
    // Lineas necesarias para obtener la informacion a partir del primer caracter de la cadena de prueba.
    int indiceEstado = (int)automata.estados[0].nombreEstado.at(1) - '0';
    int indiceSimbolo = buscarPosicionCaracter(cadenaPrueba.at(0), automata.alfabeto);
    buscarPosicionCaracter(cadenaPrueba.at(0), automata.alfabeto);

    string estadoDestino = automata.estados[indiceEstado].estadosConLosQueChoca[indiceSimbolo];
    int estado;
    string estadoActual;
    // cout << "El simbolo a evaluar es: " << cadenaPrueba[0] << endl;
    // cout << (int)estadoInicial.at(1) - '0' << endl;
    // cout << "Simbolo recibido: " << cadenaPrueba[0] << " Posicion: " << indiceSimbolo << endl;
    // cout << "Indice del estado actual: " << indiceEstado << endl;
    // cout << "Destino -> " << estadoDestino << endl;
    if(verificarEstadoPertenezca(automata, indiceEstado, estadoDestino)){
        validaciones++;
    } else {
        return false;
    }
    // VERIFICAR QUE EL ESTADO DESTINO ESTE DENTRO DE LOS ESTADOS CON LOS QUE 
    // COLISIONAN CON EL ESTADO ACTUAL --- PRACTICAMENTE LISTO

    for(int i = 1; i < cadenaPrueba.length(); i++) {
        estadoActual = automata.estados[(int)estadoDestino.at(1) - '0'].nombreEstado;
        indiceSimbolo = buscarPosicionCaracter(cadenaPrueba.at(i), automata.alfabeto);
        indiceEstado = (int)estadoDestino.at(1) - '0';
        estadoDestino = automata.estados[indiceEstado].estadosConLosQueChoca[indiceSimbolo];

        // cout << "Estado actual: " << estadoActual << endl;
        // cout << "Simbolo recibido: " << cadenaPrueba[i] << " Posicion: " << indiceSimbolo << endl;
        // cout << "Indice del estado actual: " << indiceEstado << endl;
        // cout << "Destino -> " << estadoDestino << endl;

        if(verificarEstadoPertenezca(automata, indiceEstado, estadoDestino)){
            validaciones++;
        } else {
            cout << "El estado actual es invalido, revisar la tabla de transicion" << endl;
            return false;
        }        
    }

    bool confirmacion = esDeAceptacion(automata, (int)estadoDestino.at(1) - '0');
    // VERIFICAR QUE EL ESTADO DESTINO SEA DE ACEPTACION
    
    //cout << confirmacion << endl;
    //cout << "El estado inicial es: " << estadoInicial << endl;
    // Mostrar datos finales
    //cout <<"Validaciones: " << validaciones << " Longitud cadena: " << cadenaPrueba.length() << endl;
    if(validaciones == cadenaPrueba.length() and confirmacion == true){
        return true;
    } else {
        return false;
    }
}

int buscarPosicionCaracter(char letra, string palabra) {    
    for(int i = 0; i < palabra.length(); i++) {
        if(palabra.at(i) == letra){
            return i;
        }
    }
    return 0;
}

void imprimirInformacion(AFD automata){

    for(int i = 0; i < automata.estados.size(); i++){

        cout << "Elemento numero " << i << " del automata ingresado." << endl;
        cout << "Nombre estado: " << automata.estados[i].nombreEstado << endl;
        cout << "Es de aceptacion (0/1): " << automata.estados[i].esDeAceptacion << endl;
        cout << "Estados a los que puede llegar: ";
        for(int j = 0; j < automata.estados[i].estadosConLosQueChoca.size(); j++){
            cout << automata.estados[i].estadosConLosQueChoca[j] << " ";
        }
        cout << endl;
     }     
        cout << "Los simbolos del alfabeto son: " << endl;
        for(int i = 0; i < automata.alfabeto.length(); i++) {
            cout << automata.alfabeto.at(i) << " ";
        }   
        cout <<"\n" << endl;
}

/*
Ejecución de todo
*/

void ejecutarPrograma() {

    char ingresarNuevaTabla;
    do {
    system("cls||clear");
    string nombreArchivo;
    cout << "Ingresa el nombre del archivo de la tabla de transicion: "; cin >> nombreArchivo;
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

        //imprimirInformacion(automata);
        char respuesta;
        cout << "Presione 's' si desea ver la tabla de transicion: " << endl; cin >> respuesta;
        if(respuesta == 's' or respuesta == 'S'){
            imprimirInformacion(automata);
        }
        char ingresarOtraCadena;
        do {
            cout << "Ingresa el nombre con el archivo de la cadena. " << endl;
            string archivoCadenaPrueba;
            cin >> archivoCadenaPrueba;
            archivoCadenaPrueba += ".txt";
            fstream miArchivo(archivoCadenaPrueba);
            string cadenaPrueba;
            if(miArchivo.is_open()) {
                getline(miArchivo, cadenaPrueba);

                if(caracteresSonValidos(automata.estados, cadenaPrueba, automata.alfabeto)){
                    //cout << "\nLos simbolos de la cadena son validos. " << endl;
                    //cout << "Se procedera a probar la cadena con los datos ingresados." << endl;
                    cadenaEsValida(automata, cadenaPrueba);
                } else {
                    cout << "\nLos simbolos de la cadena no pertenecen al alfabeto. " << endl;
                }
                
                if(cadenaEsValida(automata, cadenaPrueba)) {
                    cout << "La cadena es correcta" << endl;
                } else {
                    cout << "La cadena es incorrecta" << endl;
                }
            } else {
                  cout << "El archivo no se puede abrir. " << endl;
                  cout << "Es posible que no exista o que el nombre este mal escrito. \n" << endl;             
            }
            cout << "Presione 's' si desea evaluar otra cadena." << endl;
            cin >> ingresarOtraCadena;
        } while(ingresarOtraCadena == 's' or ingresarOtraCadena == 'S');
        
    } else {
        cout << "El archivo no se puede abrir. " << endl;
        cout << "Es posible que no exista o que el nombre este mal escrito. \n" << endl;
    }
        
    cout << "Presiona 's' si quieres ingresar otro diagrama de transicion " << endl;
    cin >> ingresarNuevaTabla;

    } while(ingresarNuevaTabla == 's' or ingresarNuevaTabla == 'S');
    
}