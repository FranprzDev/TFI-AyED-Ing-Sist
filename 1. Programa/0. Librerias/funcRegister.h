#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string.h>
#include <windows.h>

void iniciarSesion(); // este lo llevo despues a menus.h
void generarCuentaNormal();
void generarCuentaEntrenador();
int validarNombreUsuarioNormal(char nombreUsuario[10]);
int validarUnicidadNormal(char nombreUsuario[10]);
int validarUnicidadNormal(char nombreUsuario[10]);
int validarComienzoEnMinuscula(char nombreUsuario[10]);
int validarMayuscula(char nombreUsuario[10]);
int validarMinimo(char nombreUsuario[10]);
int validarContrasenia(char contrasenia[32], int longitudContra);
int validTriple(char contrasenia[32], int longitudContra);
int caractAlfa(char contrasenia[32], int longitudContra);
int calcLong(char contrasenia[32], int longitudContra);
int caracterConsecNum(char contrasenia[32], int longitudContra);
int consecutivAlfab(char contrasenia[32], int longitudContra);