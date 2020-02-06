#include "iostream"
#include "vector"
using namespace std;
struct Estado {
    bool esDeAceptacion;
    string nombreEstadoActual;
    vector<string> estadosConLosQueChoca;
};
int main(int argc, char const *argv[])
{
    string linea = "*q0 q1 q3";


    string nombreEstado, nombrePrimerEstado;
    vector<string> estados;
    cout << "\nLos estados presentes son: " << linea << endl;
    bool seAsignoElPrimero = false;
    int caracteresDesplazados;

    
        if(linea[0] == '*'){
            cout << "este es un estado de aceptacion" << linea[0] <<endl;
            caracteresDesplazados = 1;
        } else {
            cout << "este no es un estado de aceptacion" << linea[0] <<endl;
            caracteresDesplazados = 0;
        }
    for(int i = caracteresDesplazados; i < linea.length(); i++){
        //cout << linea[i] << " " << endl;
        if(linea[i] != 32){
            nombreEstado += linea[i];
            if(linea[i] != 'q'){
                estados.push_back(nombreEstado);
                if(!seAsignoElPrimero){
                    nombrePrimerEstado = nombreEstado;
                    seAsignoElPrimero = true;
                    estados.erase(estados.begin());
                }
                nombreEstado = "";
            }
        }
        
    }

    cout << "Nombre primer estado: " << nombrePrimerEstado << endl;

    cout << "Los estados con los que choca son: ";
    for(int i = 0; i < estados.size(); i++){
        cout << estados[i] << " ";
    }


    return 0;
}
