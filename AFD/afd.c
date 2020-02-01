#include "afd.h"

/* Esta función extraerá desde un archivo la tabla de transición del autómata finito determinista  
    así como el lenguaje y los estados.
*/
void leerAFD(char* nombreArchivo){
    FILE* miArchivo;
    miArchivo = fopen(nombreArchivo, "r"); 
    if (miArchivo == NULL) {
        printf("El archivo no se puede abrir, es posible que no exista o el nombre esté mal escrito.");
    } else {
        char alfabeto[] = "";
        char estados[] = "";
        fscanf(miArchivo, "alfabeto: %s", &alfabeto);
        fscanf(miArchivo, "estados: %s %s %s", &alfabeto);

        printf("El alfabeto que se usara es: {%s}", alfabeto);
    }
}