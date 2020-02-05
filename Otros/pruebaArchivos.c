#include "stdio.h"

void escribirEnArchivoTexto(char* nombreArchivo){
    int numero;
    FILE* miArchivo;
    miArchivo = fopen(nombreArchivo, "w");
    if (miArchivo == NULL) {
        printf("El archivo no se pudo abrir.");
    } else {
        printf("Introduce un numero: ");
        scanf("%d", &numero);

        fprintf(miArchivo, "El numero introducido es: %d", numero);
        fclose(miArchivo);
    }
}

void leerArchivoTexto(char* nombreArchivo){
    FILE* miArchivo;
    int numero;
    miArchivo = fopen(nombreArchivo, "r");

    if (miArchivo == NULL) {
        printf("El archivo no se pudo abrir.");
    } else {
        fscanf(miArchivo, "El numero introducido es: %d", &numero);
        printf("%d",numero);
    }
    
}

int main(int argc, char const *argv[])
{

    char* nombreArchivo = "textoPruebaArchivo.txt";
    escribirEnArchivoTexto(nombreArchivo);
    leerArchivoTexto(nombreArchivo);

    return 0;
}