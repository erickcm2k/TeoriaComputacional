#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Estado {
    bool esDeAceptacion;
    string nombreEstado;
    vector<string> estadosConLosQueChoca;
};

struct AFD {
    vector<Estado> estados;
    string alfabeto;
};

string obtenerAlfabeto(string textoLinea);
Estado obtenerDatosAFD(string textoLinea);
bool caracteresSonValidos(vector<Estado> estadosDelAutomata,string cadenaPrueba, string alfabeto);
bool perteneceAlAlfabeto(char simbolo, string alfabeto);
bool cadenaEsValida(AFD automata, string cadenaPrueba);
bool verificarEstadoPertenezca(AFD automata, int indiceEstado, string nombreEstadoAComprobar);
int buscarPosicionCaracter(char letra, string palabra);