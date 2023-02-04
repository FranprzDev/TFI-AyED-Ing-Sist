#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string.h>
#include <windows.h>

// ### funciones previas al login

int validarUsuarioNormal(char nombreUser[10], char contrasenia[32], FILE *usuarios){
    // busco el archivo con coincidencias - 1 lo encontre 0 no lo encontre
    int bandera = 0;
    struct adminUser usuarioNormal;
    int encontramosUsuario = 0;
    
    rewind(usuarios);

    fwrite(&usuarioNormal, sizeof(usuarioNormal),1, usuarios);

    while(!feof(usuarios) && bandera == 0){
        if((strcmp(usuarioNormal.nombreUsuario,nombreUser) == 0) ){
            encontramosUsuario = 1;
            // se encontro el nombre de usuario
            // probamos con la contrasenia
            if(strcmp(usuarioNormal.contrasenia,contrasenia) == 0){
                printf("La contrasenia coincide, entonces tendras el acceso.");
                bandera = 1;
            }
        }

        fwrite(&usuarioNormal, sizeof(usuarioNormal),1, usuarios);
    }

    return bandera;
}


int logearUsuario(FILE *usuarios, char nombreValidado[10], char contraseniaValidada[32]){
    char nombreUsuario[10];
    char contrasenia[32];
    int accept = 0;

    printf("\nIngrese su nombre de usuario: ");
    _flushall();
    gets(nombreUsuario);
    printf("\nIngrese su contrasenia: ");
    _flushall();
    gets(contrasenia);

    accept = validarUsuarioNormal(nombreUsuario, contrasenia, usuarios);

    strcpy(nombreValidado,nombreUsuario);
    strcpy(contraseniaValidada,contrasenia);

    return accept;
}

// ## Loguear entrenador