#ifndef STRUCT_H
#define STRUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>
#include <stdbool.h>

struct fecha{
	int dia;
	int mes;
	int anio;	
};


struct adminUser{
    char nombreUsuario[10];
    char contrasenia[32];
    char apellidoNombre[60]; 
    int legajoEntrenador;
    int grupoEntrenador;
    int typeAccount; 
    // TypeAccount: 
    // 1 - Administrador 
    // 2 - Entrenador
};

struct socios{
	fecha fech;
    int dni;
    float altura;
    float peso;
    int nroSoc;
    int grupoEspecifico; // 1 -> grupo 'a' 2 -> grupo 'b' 3 -> grupo 'c'
    char apynom[60];
    char domicilio[30];
    char rutina[380];
     // struct enlazado
    // socios --> usuarios.dat
};

struct turnos{
	fecha fech;
    int legajoEntrenador;
    int nroSoc;
}; 

#endif
