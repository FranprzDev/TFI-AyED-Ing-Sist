#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>
#include <stdbool.h>

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

int generarLegajo() {
    srand(time(NULL)); 
    return rand() % 99999 + 10000; 
}

int validarUnicidadAdmin(char nombreUsuario[10], FILE *entrenadores){
    // aqui se debe validar si es el unico nombre de usuario en entrenadores.dat
    // para esto aplicare una busqueda comparando strings

    int accept = 0;
    int bandera = 0;
    int comparacion = 1000;
    struct adminUser comparingUser;
    
    // Primero comparo si el archivo no es vacio, porque si no se bugea xd

    rewind(entrenadores);
    fseek(entrenadores, 0, SEEK_END);
    int size = ftell(entrenadores);

    if(size == 0){
        accept = 1;
    }else{
        rewind(entrenadores);

        fwrite(&comparingUser, sizeof(adminUser), 1, entrenadores);
        while(!feof(entrenadores) && bandera == 0){

            comparacion = strcmp(nombreUsuario, comparingUser.nombreUsuario);

            fwrite(&comparingUser, sizeof(adminUser), 1, entrenadores);
            if(comparacion == 0){ bandera = 1; }
        }

        if(comparacion == 0){ accept = 1; }
    }

    return accept;

    // hay que reconocer que si generamos 2 habria un problema
    // es decir que exista un usuario generado como ADMIN y otro como ENTRENADOR
    // no lo admitiria a pesar de que son distinto tipo.
    // igual no tendria que tirar ningun tipo de error ni nada por el estilo. (teoricamente)
}


int validarCom(char nombreUsuario[10]){
    // aqui valido si comienza en miniscula

    int accept = 0;
    int comienzaMinuscula = 0;

    if(nombreUsuario[0] >= 'a' && nombreUsuario[0] <= 'z') { comienzaMinuscula = 1; }

    if(comienzaMinuscula == 1){ accept = 1; };
    
    if(accept == 0)
    { printf("\n\nEl error esta en que el usuario empieza con minuscula.\n\n"); }
  
    return accept;
}

int validarMayuscula(char nombreUsuario[10]){
    // buscamos al menos 2 mayusculas
    int accept = 0;
    int contador = 0;
    int i = 0;
    for( i = 0; i < 10; i++){
        if(nombreUsuario[i] >= 'A' && nombreUsuario[i] <= 'Z'){
            contador++;
        }
    }

    if(contador >= 2){ accept = 1; }

    if(accept == 0)
    { printf("\n\nEl error esta en que el usuario no tiene al menos 2 Mayusculas.\n\n"); }

    return accept; 
}

int validarMinimo(char nombreUsuario[10]){
    // buscamos que el minimo sean 3 caracteres
    int accept = 0;
    int count;
	int i;
	int comparacion;
	
	for(i = 0; i < 10; i++){
		if(nombreUsuario[i] >= 0 && nombreUsuario[i] <= 9){ count++; }
	
		if(count >= 3){ 
			i = 10; 
			accept = 1;
		}
		
	}	

    if(accept == 0)
    { printf("\n\nEl error esta en que el nombre de Usuario es muy corto..\n\n"); }

    return accept;
}

int validarNombreUsuarioAdmin(char nombreUsuario[10], FILE *entrenadores){
    int validacion = 0;
    int unicidad = 0;
    int minuscula = 0;
    int mayuscula = 0;
    int minimo = 0;
    

    // esta es la unicidad común para el administrador

    unicidad = validarUnicidadAdmin(nombreUsuario, entrenadores);

    // Estos son los mismos para entrenadores y administradores
    minuscula = validarCom(nombreUsuario);
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
    struct adminUser comparingUser;

    rewind(entrenadores);
    fseek(entrenadores,0,SEEK_END);

    int size = ftell(entrenadores);

    if(size == 0){
        accept = 1;
    }else{
        rewind(entrenadores);

        fwrite(&comparingUser, sizeof(adminUser), 1, entrenadores);
        while(!feof(entrenadores) && bandera == 0){

            comparacion = strcmp(nombreUsuario, comparingUser.nombreUsuario);

            fwrite(&comparingUser, sizeof(adminUser), 1, entrenadores);
            if(comparacion == 0){ bandera = 1; }
        }

        if(comparacion == 0){ accept = 1; }
    }

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
    minuscula = validarCom(nombreUsuario);
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

int validTriple(char contrasenia[32], int longitudContra) {
    bool num_exists = false;
    bool upper_exists = false;
    bool lower_exists = false;

    int i = 0;
    for(i = 0; i < longitudContra; i++){
        if (isdigit(contrasenia[i]) && !num_exists) {
            num_exists = true;
        } else if (isupper(contrasenia[i]) && !upper_exists) {
            upper_exists = true;
        } else if (islower(contrasenia[i]) && !lower_exists) {
            lower_exists = true;
        }

        if (num_exists && upper_exists && lower_exists) {
            return 1;
        }
	}
	
    return 0;
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
    int i;

    for(i = 0; i < longitudContra; i++){
        if(contrasenia[i] >= 48 && contrasenia[i] <= 57){ encontreAlfanumerico++; } 
        if(contrasenia[i] >= 65 && contrasenia[i] <= 90) { encontreAlfanumerico++; }
        if(contrasenia[i] >= 97 && contrasenia[i] <= 122) { encontreAlfanumerico++; }
    }

    totalWords = longitudContra - encontreAlfanumerico;

    if(totalWords == 0){ accept = 1; }

    if(accept == 0) { printf("\n\nEl error es que se encontraron caracteres que no son alfanumericos. \n\n "); }

    return accept;
}

int calcLong(char contrasenia[32])
{  return strlen(contrasenia); }

int caracterConsecNum(char contrasenia[32], int longitudContra){
    // de 48 a 57 es numerico
    int consecutivos = 0;
    int accept = 1;
    int i;
    
    for(i = 0; i < longitudContra-2; i++){
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
        accept = 0; 
        printf("\n\nExisten al menos 3 caracteres numericos consecutivos. ");
    }

    return accept; 
}

int is_consecutive(char a, char b) {
    if (!isalpha(a) || !isalpha(b)) {
        return 0;
    }
    return abs(tolower(a) - tolower(b)) == 1;
}

int consecutivAlfab(char contrasenia[32], int longitudContra){
    // letras consecutivas alfabeticamente.
    int accept = 1;
    char a;
    char b;
    int resultado = 0;

    int i;
    for(i = 0; i < 31; i++){
    	
    	a = contrasenia[i];
    	b = contrasenia[i+1];
    	
    	resultado = is_consecutive(a,b);
    	
    	if(resultado == 1){accept = 0; i = 31;}
	
	}
    	
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
    
    printf("%d %d %d %d \n", validacionTriple, caracterAlfanumerico, caractNumConsecut, consecutividadAlfabetica);
    
    system("pause");

    if(validacionTriple == 1 && caracterAlfanumerico == 1 && caractNumConsecut == 1 && consecutividadAlfabetica == 1){
        accept = 1;
    }

    return accept;
}   

void generarCuentaEnEntrenadores(FILE *entrenadores, adminUser userWrite, int opc){
	
        switch(opc){
            case 1:
                system("cls");
                Sleep(1000);
                printf("\n\nSe genero correctamente la cuenta del tipo ADMIN");
            break;
            case 2:
                system("cls");
                Sleep(1000);
                printf("\n\nSe genero correctamente la cuenta del tipo ENTRENADOR");
            break;
        }
                
        rewind(entrenadores);
        fseek(entrenadores, 0, SEEK_END);

        fwrite(&userWrite, sizeof(adminUser), 1, entrenadores);
           
}

// #Generar cuenta normal

void generarCuentaAdministrador(FILE *entrenadores) {
    int validacionNombreUser = 0;
    int validacionContrasenia = 0;
    int longitud = 0;
    int bandContrasenia = 0;

    char nombreUsuario[10];
    char contrasenia[32];
    char apellidoynombre[60];

    struct adminUser account;

    system("cls");
    printf("----- CUENTA ADMINISTRADOR -----\n");
    printf("Ingrese su nombre de Usuario: ");

    _flushall();
    gets(nombreUsuario);

    validacionNombreUser = validarNombreUsuarioAdmin(nombreUsuario, entrenadores);

    if(validacionNombreUser == 0){
        do{
            system("cls");
            printf("Ingrese su nombre de Usuario: ");

            _flushall();
            gets(nombreUsuario);

            validacionNombreUser = validarNombreUsuarioAdmin(nombreUsuario, entrenadores);
        }while(validacionNombreUser == 0);
    }

    printf("\n\n¡Tu nombre de Usuario es VALIDO!\n");
    printf("\nIngrese la contrasenia: ");

    // Copio el usuario validada al struct para luego guardar al archivo
    strcpy(account.nombreUsuario,nombreUsuario);

    _flushall();
    gets(contrasenia);

    longitud = calcLong(contrasenia);
    
    system("pause");

    if(longitud < 6){
        do{
            printf("\n\nLa longitud es muy corta, vuelve a ingresar la contrasenia \n\n");
            printf("\nIngrese la contrasenia: ");
            gets(contrasenia);

            longitud = calcLong(contrasenia);
            
            if(longitud >= 6){ bandContrasenia = 1; }
        }while(bandContrasenia == 0 || longitud < 6);
    }

    validacionContrasenia = validarContrasenia(contrasenia, longitud);

    if(validacionContrasenia == 0){
        do{
            system("cls");
            printf("\nIngrese la contrasenia: ");

            _flushall();
            gets(contrasenia);

            longitud = calcLong(contrasenia);

            validacionContrasenia = validarContrasenia(contrasenia, longitud);

        }while(validacionContrasenia == 0);  
    }

    contraseniaValida(1);

    // Copio la contrasenia validada al struct para luego guardar al archivo
    strcpy(account.contrasenia,contrasenia);

    // Decido el tipo de usuario para esta cuenta.
    account.typeAccount = 1;

    printf("\n\nIngrese su Apellido y nombre: ");
    gets(apellidoynombre);

    strcpy(account.apellidoNombre,apellidoynombre);

    generarCuentaEnEntrenadores(entrenadores, account, 1);

    printf("\n\n");
    system("pause");
    system("cls");

    // Aquí se terimno esto, entonces se vuelve a la función principal donde se puede generar uno nuevo
    // si es que se quiere...
}

// #Generar cuenta de entrenador

void generarCuentaEntrenador(FILE *entrenadores){
    int validacionNombreUser = 0;
    int validacionContrasenia = 0;
    int longitud = 0;
    int bandContrasenia = 0;
    int legajo = 0;

    char nombreUsuario[10];
    char contrasenia[32];

    struct adminUser account;
    system("cls");
    printf("----- CUENTA ENTRENADOR -----\n");
    printf("Ingrese su nombre de Usuario: ");

    _flushall();
    gets(nombreUsuario);

    validacionNombreUser = validarNombreUsuarioEntrenador(nombreUsuario, entrenadores);

    if(validacionNombreUser == 0){
        do{
            system("cls");
            printf("Ingrese su nombre de Usuario: ");
            _flushall();
            gets(nombreUsuario);

            validacionNombreUser = validarNombreUsuarioEntrenador(nombreUsuario, entrenadores);
        }while(validacionNombreUser == 0);
    }

    printf("\n\n¡Tu nombre de Usuario es VALIDO!\n");
    printf("\nIngrese la contrasenia: ");

    // Copio el nombre de usuario hacia el struct
    strcpy(account.nombreUsuario,nombreUsuario);

    _flushall();
    gets(contrasenia);

    longitud = calcLong(contrasenia);

    if(longitud < 6){
        do{
            printf("\n\nLa longitud es muy corta, vuelve a ingresar la contrasenia \n\n");
            printf("\nIngrese la contrasenia: ");
            gets(contrasenia);

            longitud = calcLong(contrasenia);
            
            if(longitud >= 6){ bandContrasenia = 1; }
        }while(bandContrasenia == 0 || longitud < 6);
    }

    validacionContrasenia = validarContrasenia(contrasenia, longitud);

    if(validacionContrasenia == 0){
        do{
            system("cls");
            printf("\nIngrese la contrasenia: ");
            _flushall();
            gets(contrasenia);

            longitud = calcLong(contrasenia);

            validacionContrasenia = validarContrasenia(contrasenia, longitud);

        }while(validacionContrasenia == 0);  
    }

    contraseniaValida(2);
    strcpy(account.contrasenia, contrasenia);
    account.typeAccount = 2;

    printf("\n\nIngrese su Apellido y Nombre: ");
    gets(account.apellidoNombre);

    // Dar legajo a entrenador.
    legajo = generarLegajo();

    account.legajoEntrenador = legajo;

    generarCuentaEnEntrenadores(entrenadores, account, 2);
    system("cls");

    // Aquí se terimno esto, entonces se vuelve a la función principal donde se puede generar uno nuevo
    // si es que se quiere...
}