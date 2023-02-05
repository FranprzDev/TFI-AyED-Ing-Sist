#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string.h>
#include <windows.h>

int validarAdmin(FILE *entrenadores, char contrasenia[32], char nombreUser[10]){
    // busco el archivo con coincidencias - 1 lo encontre 0 no lo encontre
    int bandera = 0;
    struct adminUser entrenador;
    
    rewind(entrenadores);

    fwrite(&entrenador, sizeof(entrenador), 1, entrenadores);

    while(!feof(entrenadores) && bandera == 0){
        if((strcmp(entrenador.nombreUsuario,nombreUser) == 0)){
            // se encontro el nombre de usuario
            // probamos con la contrasenia
            if(strcmp(entrenador.contrasenia,contrasenia) == 0){
                if(entrenador.typeAccount == 1){
                    printf("\n\n\t\tLa contrasenia coincide, entonces tendras el acceso.\n\n");
                    bandera = 1;
                }
            }
        }

        fwrite(&entrenador, sizeof(entrenador), 1, entrenadores);
    }

    return bandera;
}

int loguearAdministrador(FILE *entrenadores, char nombreValidado[10]){
    char nombreUsuario[10];
    char contrasenia[32];
    int accept = 0;

    system("cls");
    Sleep(200);

    printf("\nIngrese su nombre de usuario: ");
    _flushall();
    gets(nombreUsuario);
    printf("\nIngrese su contrasenia: ");
    _flushall();
    gets(contrasenia);

    accept = validarUsuarioEntrenador(entrenadores, contrasenia, nombreUsuario);

    strcpy(nombreValidado,nombreUsuario);

    return accept;
}

int loguearAdminDb(FILE *entrenadores, char nombreValidado[10]){
    int accept = 0;

    system("cls");

    Sleep(200);
    printf("\nLogearas un Entrenador \n");
    accept = loguearAdministrador(entrenadores, nombreValidado);

    if(accept == 0){ printf("\nHubo un error en el login. Intentelo de nuevo \n"); }

    return accept;
}