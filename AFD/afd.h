#ifndef __AFD_H__
#define __AFD_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct AFD{
    char* alfabeto;
    int edad;

};

void leerAFD(char* nombreArchivo);

#endif