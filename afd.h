#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Estado {
    bool esDeAceptacion;
    string nombreEstadoActual;
    vector<string> estadosConLosQueChoca;
};

string obtenerAlfabeto(string textoLinea);
Estado obtenerDatosAFD(string textoLinea);


