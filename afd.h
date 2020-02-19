#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Estado {
    bool esDeAceptacion;
    string nombreEstadoActual;
    vector<string> estadosConLosQueChoca;
};

struct AFD {
    vector<Estado> estados;
    string alfabeto;
};

string obtenerAlfabeto(string textoLinea);
Estado obtenerDatosAFD(string textoLinea);
bool cadenaEsValida(vector<Estado> estadosDelAutomata,string cadenaPrueba, string alfabeto);
bool perteneceAlAlfabeto(char simbolo, string alfabeto);