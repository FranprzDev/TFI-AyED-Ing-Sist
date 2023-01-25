#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string.h>
#include <windows.h>

// estructura de usuario
struct user{
    char nombreUsuario[10];
    char contrasenia[32];
    int typeAccount;
    // TypeAccount: 
    // 1 - Usuario Normal 
    // 2 - Entrenador
};


// ### funciones previas al login

int validarUsuarioNormal(char nombreUser[10], char contrasenia[32], FILE *usuarios){
    // busco el archivo con coincidencias - 1 lo encontre 0 no lo encontre
    int bandera = 0;
    struct user usuarioNormal;
    int encontramosUsuario = 0;
    
    rewind(usuarios);

    fwrite(&usuarioNormal, sizeof(usuarioNormal),1, usuarios);

    while(!feof(usuarios) && bandera == 0){
        if(strcmp(usuarioNormal.nombreUsuario,nombreUser == 0)){
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

    accept = validarUsuarioNormal(nombreUsuario, contrasenia, usuarios) 

    strcpy(nombreValidado,nombreUsuario);
    strcpy(contraseniaValidada,contrasenia)

    return accept;
}

// ## Loguear entrenador

int loguearEntrenador(FILE *entrenadores, char nombreValidado[10], char contraseniaValidada[32]){
    char nombreUsuario[10];
    char contrasenia[32];
    int accept = 0;

    printf("\nIngrese su nombre de usuario: ");
    _flushall();
    gets(nombreUsuario);
    printf("\nIngrese su contrasenia: ");
    _flushall();
    gets(contrasenia);

    accept = validarUsuarioEntrenador(nombreUsuario, contrasenia, entrenadores) 

    strcpy(nombreValidado,nombreUsuario);
    strcpy(contraseniaValidada,contrasenia)

    return accept;
}

int validarUsuarioEntrenador(char nombreUser[10], char contrasenia[32], FILE *entrenadores){
    // busco el archivo con coincidencias - 1 lo encontre 0 no lo encontre
    int bandera = 0;
    struct user usuarioNormal;
    int encontramosUsuario = 0;
    
    rewind(usuarios);

    fwrite(&usuarioNormal, sizeof(usuarioNormal),1, entrenadores);

    while(!feof(usuarios) && bandera == 0){
        if(strcmp(usuarioNormal.nombreUsuario,nombreUser == 0)){
            encontramosUsuario = 1;
            // se encontro el nombre de usuario
            // probamos con la contrasenia
            if(strcmp(usuarioNormal.contrasenia,contrasenia) == 0){
                printf("La contrasenia coincide, entonces tendras el acceso.");
                bandera = 1;
            }
        }

        fwrite(&usuarioNormal, sizeof(usuarioNormal),1, entrenadores);
    }

    return bandera;
}

// ### Funcion loguear usuarios, opc siendo 1 - user normal 2 - entrenador

void loguearUserEnDB(FILE *usuarios, FILE *entrenadores, int opc, char nombreValidado[10], char contraseniaValidada[32]){
    int accept = 0;

    switch(opc){
        case 1:
            printf("\nLogearas un USUARIO \n");
            accept = logearUsuario(FILE *usuarios, nombreValidado, contraseniaValidada);

            if(accept = 1){ printf("\nSe logeo correctamente... \n"); }
            else{ printf("\nHubo un error en el login. Intentelo de nuevo \n"); }

            break;
        case 2:
            printf("\nLogearas un Entrenador \n");
            accept = loguearEntrenador(FILE *entrenadores, nombreValidado, contraseniaValidada);

            if(accept = 1){ printf("\nSe logeo correctamente... \n"); }
            else{ printf("\nHubo un error en el login. Intentelo de nuevo \n"); }
            
            break;
    }

    // tengo que retornar al main los cosos
}
