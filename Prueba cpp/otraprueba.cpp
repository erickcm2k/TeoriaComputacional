#include "iostream"
#include "vector"
using namespace std;

int main(int argc, char const *argv[])
{
    string linea = "q0 q1 q3";
    string nombreEstado;
    vector<string> estados;
    cout << "La linea actual es: " << linea << endl;

    for(int i = 0; i < linea.length(); i++){
        cout << linea[i] << " " << endl;
        if(linea[i] != 32){
            nombreEstado += linea[i];
            if(linea[i] != 'q'){
                estados.push_back(nombreEstado);
                nombreEstado = "";
            }
        }
        
    }

    cout << "Nombre primer estado de aceptacion: " << nombreEstado << endl;

    cout << "Los estados de aceptacion son: " << endl;
    for(int i = 0; i < estados.size(); i++){
        cout << estados[i] << endl;
    }


    return 0;
}
