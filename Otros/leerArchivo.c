/*
AUTOR: Edgardo AdriÃ¡n Franco MartÃ­nez (C) Febrero 2011
VERSIÃ“N: 1.0 

DESCRIPCIÃ“N: Programa que demuestra el uso de archivos en mod texto y binario
Problema: Escribe un programa en C que solicite los datos de 10 empleados y los almacene 
en un archivo plano (â€œempleados.txtâ€).  Los datos que deberÃ¡n solicitarse para cada empleado, 
son los siguientes:
#empleado (entero).
Nombre del empleado (cadena de mÃ¡ximo 45 caracteres).
Departamento (cadena de mÃ¡ximo 45 caracteres).
Salario (real).
Domicilio (cadena de mÃ¡ximo 100 caracteres).

OBSERVACIONES: Se definio NUM_EMP como constante para hacer mÃ¡s compatible el programa

COMPILACIÃ“N: gcc problema_empleados.c -o problema_empleados
EJECUCIÃ“N: problema_empleados.exe (En Windows) - ./problema_empleados (En Linux)
*/
//LIBRERAS
#include<stdio.h>

//DEFINICIÃ“N DE ESTRUCTURAS Y CONSTANTES
//NÃºmero de empleados
#define NUM_EMP 2

//DefiniciÃ³n de la estructura
typedef struct empleado
{
	int no_empleado;
	char nombre[45];
	char departamento[45];
	float salario;
	char direccion[100];
}empleado;


//DECLARACIÃ“N DE FUNCIONES

void ImprimeEmpleados(empleado *lista);
/*Procedimiento para guardar en un archivo de texto a los empleados 
(Recibe la referencia al arreglo de empleados y la ruta del archivo a escribir)*/
void LeeEmpleadosTexto(empleado *lista, char* ruta_leer);
/*Procedimiento para guardar en un archivo de binario a los empleados 
(Recibe la referencia al arreglo de empleados y la ruta del archivo a escribir)*/

//PROGRAMA PRINCIPAL
int main(void)
{
	empleado lista[NUM_EMP];

	LeeEmpleadosTexto(lista,"empleados.txt");
	ImprimeEmpleados(lista);

	
	return 0;
}

//DEFINICIÃ“N DE FUNCIONES

void ImprimeEmpleados(empleado *lista)
{
	int i;
	for(i=0;i<NUM_EMP;i++)
	{
		printf("\n\n\nEmpleado #%d",lista[i].no_empleado);
		printf("\nNombre: %s",lista[i].nombre);
		printf("\nDepartamento: %s",lista[i].departamento);
		printf("\nSalario: %.2f",lista[i].salario);
		printf("\nDirecciÃ³n: %s",lista[i].direccion);
	}
}

/*
void LeeEmpleadosTexto(empleado *lista, char* ruta_escribir);
DescripciÃ³n: Procedimiento para leer de un archivo de texto a los empleados
Recibe: empleado *lista (Referencia al arreglo de empleados), char *ruta(Cadena con la ruta del archivo a escribir) 
Devuelve:
Observaciones: Si la esctructura empleado se modifica, o si se cambia la la manera de guardar a los empleados, 
tambiÃ©n se modificarÃ¡ esta funciÃ³n, el archivo a escribir se maneja en modo texto.
*/
void LeeEmpleadosTexto(empleado *lista, char* ruta_leer)
{
	int i,n; 
	FILE *archivo;
	archivo=fopen(ruta_leer,"r");
	fseek(archivo,0,SEEK_SET);	
	for(i=0;i<NUM_EMP;i++)
	{
		fscanf(archivo,"\n\nEmpleado %d de la lista",&n);	
		fscanf(archivo,"\nNÃºmero de empleado: %d",&lista[i].no_empleado);
		fscanf(archivo,"\nNombre de empleado: %s",&lista[i].nombre);
		fscanf(archivo,"\nDepartamento del empleado: %s",&lista[i].departamento);
		fscanf(archivo,"\nSalario de empleado: %f",&lista[i].salario);
		fscanf(archivo,"\nDirecciÃ³n del empleado: %s",&lista[i].direccion);	
	}
	fclose(archivo);
}
