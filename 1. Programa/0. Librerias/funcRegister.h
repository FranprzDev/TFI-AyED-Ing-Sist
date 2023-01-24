#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string.h>
#include <windows.h>

struct user{
    char nombreUsuario[10];
    char contrasenia[32];
    int typeAccount;
    // TypeAccount: 
    // 1 - Usuario Normal 
    // 2 - Entrenador
};

int validarUnicidadNormal(char nombreUsuario[10], FILE *usuarios){
    // aqui se debe validar si es el unico nombre de usuario en usuarios.dat
    // para esto aplicare una busqueda comparando strings

    int accept = 0;
    int bandera = 0;
    int comparacion = 1000;
    struct user comparingUser;

    rewind(usuarios);

    fwrite(&comparingUser, sizeof(comparingUser), 1, usuarios);
    while(!feof(usuarios) && bandera == 0){

        comparacion = strcmp(nombreUsuario, comparingUser.nombreUsuario);

        fwrite(&comparingUser, sizeof(comparingUser), 1, usuarios);
        if(comparacion == 0){ bandera = 1; }
    }

    if(comparacion == 0){ accept = 1; }

    return accept;
}

int validarComienzoEnMinuscula(char nombreUsuario[10]){
    // aqui valido si comienza en miniscula

    int accept = 0;
    int comienzaMinuscula = 0;

    if(nombreUsuario[0] >= 'a' && nombreUsuario[0] <= 'z') { comienzaMinuscula = 1; }

    if(comienzaMinuscula == 1){ accept = 1; };
    
    if(accept = 0)
    { erroresRegister(1); }
    return accept;
}

int validarMayuscula(char nombreUsuario[10]){
    // buscamos al menos 2 mayusculas
    int accept = 0;
    int contador = 0;
    for(int i = 0; i < 10; i++){
        if(nombreUsuario[i] >= 'A' && nombreUsuario[i] <= 'Z'){
            contador++;
        }
    }

    if(contador >= 2){ accept = 1; }

    if(accept = 0)
    { erroresRegister(2); }

    return accept; 
}

int validarMinimo(char nombreUsuario[10]){
    // buscamos que el minimo sean 3 caracteres
    int accept = 0;
    int count;

    for(int i = 0; i < 10; i++)
    { if(nombreUsuario[i] != '\0') count++; }

    if(count >= 3) {
        accept = 1;
    }

    if(accept = 0)
    { erroresRegister(3); }

    return accept;
}

int validarNombreUsuarioNormal(char nombreUsuario[10], FILE *usuarios){
    int validacion = 0;
    int unicidad = 0;
    int minuscula = 0;
    int mayuscula = 0;
    int minimo = 0;
    

    // esta es la unicidad común para el normal

    unicidad = validarUnicidadNormal(nombreUsuario, usuarios);

    // Estos son los mismos para entrenadores y normales
    minuscula = validarComienzoEnMinuscula(nombreUsuario);
    mayuscula = validarMayuscula(nombreUsuario);
    minimo = validarMinimo(nombreUsuario);

    // Para que deje crear todos los accept tienen que ser 1

    if(unicidad == 1 && minuscula == 1 && mayuscula == 1 && minimo == 1)
    {  validacion = 1; }

    return validacion;
}

int validarUnicidadEntrenador(char nombreUsuario[10], FILE *entrenadores){
    // aqui se debe validar si es el unico nombre de usuario en entrenadores.dat
    // para esto aplicare una busqueda comparando strings

    int accept = 0;
    int bandera = 0;
    int comparacion = 1000;
    struct user comparingUser;

    rewind(entrenadores);

    fwrite(&comparingUser, sizeof(comparingUser), 1, entrenadores);
    while(!feof(entrenadores) && bandera == 0){

        comparacion = strcmp(nombreUsuario, comparingUser.nombreUsuario);

        fwrite(&comparingUser, sizeof(comparingUser), 1, entrenadores);
        if(comparacion == 0){ bandera = 1; }
    }

    if(comparacion == 0){ accept = 1; }

    return accept;
}

int validarNombreUsuarioEntrenador(char nombreUsuario[10], FILE *entrenadores){
    int validacion = 0;
    int unicidad = 0;
    int minuscula = 0;
    int mayuscula = 0;
    int minimo = 0;
    

    // Aqui hacemos una nueva función...

    unicidad = validarUnicidadEntrenador(nombreUsuario, entrenadores);

    // Estos 3 reutilizamos las funciones...
    minuscula = validarComienzoEnMinuscula(nombreUsuario);
    mayuscula = validarMayuscula(nombreUsuario);
    minimo = validarMinimo(nombreUsuario);

    // Para que deje crear todos los accept tienen que ser 1

    if(unicidad == 1 && minuscula == 1 && mayuscula == 1 && minimo == 1)
    {  validacion = 1; }

    return validacion;
}

/*
    ################################ VALIDACIÓN DE USUARIO ########################

    ################################ VALIDACIÓN DE CONTRASENIA ########################
*/

int validTriple(char contrasenia[32], int longitudContra){
    int accept = 0;
    // 1 mayus 1 min 1 numero
    int mayus = 0, min = 0, num = 0;

    for(int i = 0; i < longitudContra; i++){
        if(contrasenia[i] >= 0 && contrasenia[i] <= 9){ num++; }
        if(contrasenia[i] >= 'a' && contrasenia[i] <= 'z'){ min++; }
        if(contrasenia[i] >= 'A' && contrasenia[i] <= 'Z'){ mayus++; }

        if(num >= 1 && min >= 1 && mayus >= 1){
            i = longitudContra;
        }
    }

    if(num >= 1 && min >= 1 && mayus >= 1){ accept = 1; }

    if(accept = 0) { erroresRegister(4); }
    return accept;
}

int caractAlfa(char contrasenia[32], int longitudContra){
    // No podrá contener ningún carácter de puntuación, ni acentos, ni espacios. 
    // Sólo caracteres alfanuméricos. 
    /*
        de 65 a 90
        de 97 a 122
        de 48 a 57
    */
    int encontreAlfanumerico = 0;
    int totalWords = 0;
    int accept = 0;

    for(int i = 0; i < longitudContra; i++){
        if(contrasenia[i] >= 48 && contrasenia[i] <= 57){ encontreAlfanumerico++; } 
        if(contrasenia[i] >= 65 && contrasenia[i] <= 90) { encontreAlfanumerico++; }
        if(contrasenia[i] >= 97 && contrasenia[i] <= 122) { encontreAlfanumerico++; }
    }

    totalWords = longitudContra - encontreAlfanumerico;

    if(totalWords == 0){ accept = 1; }

    if(accept == 0) { erroresRegister(5); }

    return accept;
}

int calcLong(char contrasenia[32])
{  return strlen(contrasenia); }

int caracterConsecNum(char contrasenia[32], int longitudContra){
    // de 48 a 57 es numerico
    int consecutivos = 0;
    int accept = 0;
    for(int i = 0; i < longitudContra-2; i++){
        if(contrasenia[i] >= 48 && contrasenia[i] <= 57){
            if(contrasenia[i+1] >= 48 && contrasenia[i+1] <= 57){
                if(contrasenia[i+2] >= 48 && contrasenia[i+2] <= 57){
                    consecutivos++;
                    if(consecutivos == 1){ i = longitudContra-2; }
                }
            }
        }
    }

    if(consecutivos == 1){ 
        accept = 1; 
        erroresRegister(6);
    }

    return accept; 
}

int consecutivAlfab(char contrasenia[32], int longitudContra){
    // letras consecutivas alfabeticamente.
    int seguidos = 0;
    int accept = 0;

    for(int i=0; i<longitudContra-1; i++){
        if(contrasenia[i] >= 48 && contrasenia[i] <= 57){
            // determino si es un numero...
            if(contrasenia[i] == 48 && contrasenia[i+1] == 49){ seguidos++; }
            if(contrasenia[i] == 49 && contrasenia[i+1] == 50){ seguidos++; }
            if(contrasenia[i] == 50 && contrasenia[i+1] == 51){ seguidos++; }
            if(contrasenia[i] == 51 && contrasenia[i+1] == 52){ seguidos++; }
            if(contrasenia[i] == 52 && contrasenia[i+1] == 53){ seguidos++; }
            if(contrasenia[i] == 53 && contrasenia[i+1] == 54){ seguidos++; }
            if(contrasenia[i] == 54 && contrasenia[i+1] == 55){ seguidos++; }
            if(contrasenia[i] == 55 && contrasenia[i+1] == 56){ seguidos++; }
            if(contrasenia[i] == 55 && contrasenia[i+1] == 57){ seguidos++; }

            if(seguidos >= 1){ i = longitudContra-1; }
        }
    }
        if(seguidos >= 1){ accept = 1; }

        return accept;
}

int validarContrasenia(char contrasenia[32], int longitudContra){
    int validacionTriple = 0;
    int caracterAlfanumerico = 0;
    int caractNumConsecut = 0;
    int consecutividadAlfabetica = 0;

    validacionTriple = validTriple(contrasenia, longitudContra);
    caracterAlfanumerico = caractAlfa(contrasenia, longitudContra);
    caractNumConsecut = caracterConsecNum(contrasenia, longitudContra); 
    consecutividadAlfabetica = consecutivAlfab(contrasenia, longitudContra);

    int accept = 0;

    if(validacionTriple == 1 && caracterAlfanumerico == 1 && caractNumConsecut == 1 && consecutividadAlfabetica == 1){
        accept = 1;
    }

    return accept;
}   

void generarCuentaEnArchivoUsuario(FILE *usuarios, struct  user userWrite){
        generacionCuentas(1);
                
        rewind(usuarios);
        fseek(usuarios, 0, SEEK_END);

        fwrite(&userWrite, sizeof(userWrite), 1, usuarios);
           
}

void generarCuentaEnArchivoEntrenadores(FILE *entrenadores, struct user userWrite){
        generacionCuentas(2);
                
        rewind(entrenadores);
        fseek(entrenadores, 0, SEEK_END);

        fwrite(&userWrite, sizeof(userWrite), 1, entrenadores);
           
}

// #Generar cuenta normal

void generarCuentaNormal(FILE *usuarios) {
    int validacionNombreUser = 0;
    int validacionContrasenia = 0;
    int longitud = 0;
    int bandContrasenia = 0;

    char nombreUsuario[10];
    char contrasenia[32];

    struct user normalAccount;

    menuDeRegister(1);

    _flushall();
    gets(nombreUsuario);

    validacionNombreUser = validarNombreUsuarioNormal(nombreUsuario, usuarios);

    if(validacionNombreUser == 0){
        do{
            menuDeRegister(3);

            _flushall();
            gets(nombreUsuario);

            validacionNombreUser = validarNombreUsuarioNormal(nombreUsuario, usuarios);
        }while(validacionNombreUser == 0);
    }

    menuDeRegister(4);

    // Copio la contrasenia validada al struct para luego guardar al archivo
    strcpy(normalAccount.nombreUsuario,nombreUsuario);

    _flushall();
    gets(contrasenia);

    longitud = calcLong(contrasenia);

    if(longitud < 6){
        do{
            menuDeRegister(5);
            gets(contrasenia);

            longitud = calcLong(contrasenia);
            
            if(longitud >= 6){ bandContrasenia = 1; }
        }while(bandContrasenia == 0 || longitud < 6);
    }

    validacionContrasenia = validarContrasenia(contrasenia, longitud);

    if(validacionContrasenia == 0){
        do{
            menuDeRegister(6);

            _flushall();
            gets(contrasenia);

            longitud = calcLong(contrasenia);

            validacionContrasenia = validarContrasenia(contrasenia, longitud);

        }while(validacionContrasenia == 0);  
    }

    contraseniaValida(1);

    // Copio la contrasenia validada al struct para luego guardar al archivo
    strcpy(normalAccount.contrasenia,contrasenia);

    // Decido el tipo de usuario para esta cuenta.
    normalAccount.typeAccount = 1;

    generarCuentaEnArchivoUsuario(usuarios, normalAccount);
    system("cls");

    // Aquí se terimno esto, entonces se vuelve a la función principal donde se puede generar uno nuevo
    // si es que se quiere...
}

// #Generar cuenta de entrenador

void generarCuentaEntrenador(FILE *entrenadores){
    int validacionNombreUser = 0;
    int validacionContrasenia = 0;
    int longitud = 0;
    int bandContrasenia;

    char nombreUsuario[10];
    char contrasenia[32];

    struct user entrenadorAccount;
    menuDeRegister(2);

    _flushall();
    gets(nombreUsuario);

    validacionNombreUser = validarNombreUsuarioEntrenador(nombreUsuario, entrenadores);

    if(validacionNombreUser == 0){
        do{
            menuDeRegister(3);
            _flushall();
            gets(nombreUsuario);

            validacionNombreUser = validarNombreUsuarioEntrenador(nombreUsuario, entrenadores);
        }while(validacionNombreUser == 0);
    }

    menuDeRegister(4);

    // Copio el nombre de usuario hacia el struct
    strcpy(entrenadorAccount.nombreUsuario,nombreUsuario);

    _flushall();
    gets(contrasenia);

    longitud = calcLong(contrasenia);

    if(longitud < 6){
        do{
            menuDeRegister(5);
            gets(contrasenia);

            longitud = calcLong(contrasenia);
            
            if(longitud >= 6){ bandContrasenia = 1; }
        }while(bandContrasenia == 0 || longitud < 6);
    }

    validacionContrasenia = validarContrasenia(contrasenia, longitud);

    if(validacionContrasenia == 0){
        do{
            menuDeRegister(6);
            _flushall();
            gets(contrasenia);

            longitud = calcLong(contrasenia);

            validacionContrasenia = validarContrasenia(contrasenia, longitud);

        }while(validacionContrasenia == 0);  
    }

    contraseniaValida(2);
    strcpy(entrenadorAccount.contrasenia, contrasenia);
    entrenadorAccount.typeAccount = 2;

    generarCuentaEnArchivoEntrenadores(entrenadores, entrenadorAccount);
    system("cls");

    // Aquí se terimno esto, entonces se vuelve a la función principal donde se puede generar uno nuevo
    // si es que se quiere...
}