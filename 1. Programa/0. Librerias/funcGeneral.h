#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string.h>
#include <windows.h>

void iniciarSesion();
void generarCuentaNormal();
int validarNombreUsuarioNormal(char nombreUsuario[10]);
int validarUnicidadNormal(char nombreUsuario[10]);
int validarUnicidadNormal(char nombreUsuario[10]);
int validarComienzoEnMinusculaNormal(char nombreUsuario[10]);
int validarMayusculaNormal(char nombreUsuario[10]);
int validarMinimoNormal(char nombreUsuario[10]);
int validarContraseniaUsuarioNormal(char contrasenia[32], int longitudContra);
int validTriple(char contrasenia[32], int longitudContra);
int caractAlfa(char contrasenia[32], int longitudContra);
int calcLong(char contrasenia[32], int longitudContra);
int caracterConsecNum(char contrasenia[32], int longitudContra);
int consecutivAlfab(char contrasenia[32], int longitudContra);