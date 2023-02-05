#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>
#include <stdbool.h>


/*
	--- ESTRUCTURAS --- (10 - 60)
*/
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


/*
	Register (55 a 620 aprox)
*/


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

        fwrite(&comparingUser, sizeof(comparingUser), 1, entrenadores);
        while(!feof(entrenadores) && bandera == 0){

            comparacion = strcmp(nombreUsuario, comparingUser.nombreUsuario);

            fwrite(&comparingUser, sizeof(comparingUser), 1, entrenadores);
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
    

    // esta es la unicidad comÃƒÂºn para el administrador

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

        fwrite(&comparingUser, sizeof(comparingUser), 1, entrenadores);
        while(!feof(entrenadores) && bandera == 0){

            comparacion = strcmp(nombreUsuario, comparingUser.nombreUsuario);

            fwrite(&comparingUser, sizeof(comparingUser), 1, entrenadores);
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
    

    // Aqui hacemos una nueva funciÃƒÂ³n...

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
    ################################ VALIDACIÃƒâ€œN DE USUARIO ########################

    ################################ VALIDACIÃƒâ€œN DE CONTRASENIA ########################
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
    // No podrÃƒÂ¡ contener ningÃƒÂºn carÃƒÂ¡cter de puntuaciÃƒÂ³n, ni acentos, ni espacios. 
    // SÃƒÂ³lo caracteres alfanumÃƒÂ©ricos. 
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

    printf("\n\nÃ‚Â¡Tu nombre de Usuario es VALIDO!\n");
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

    printf("\n\nTu Contrasenia es VALIDA!!!\n");
    printf("\n\nGeneraremos tu Usuario de tipo ADMINISTRADOR!!!\n");
    printf("\nEspere... \n");
    Sleep(2000);

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

    // AquÃƒÂ­ se terimno esto, entonces se vuelve a la funciÃƒÂ³n principal donde se puede generar uno nuevo
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

    printf("\n\nÃ‚Â¡Tu nombre de Usuario es VALIDO!\n");
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

    printf("\n\nTu Contrasenia es VALIDA!!!\n");
    printf("\n\nGeneraremos tu Usuario de tipo ENTRENADOR!!!\n");
    printf("\nEspere... \n");
    Sleep(2000);
    strcpy(account.contrasenia, contrasenia);
    account.typeAccount = 2;

    printf("\n\nIngrese su Apellido y Nombre: ");
    gets(account.apellidoNombre);

    // Dar legajo a entrenador.
    legajo = generarLegajo();

    account.legajoEntrenador = legajo;

    generarCuentaEnEntrenadores(entrenadores, account, 2);
    system("cls");

    // AquÃƒÂ­ se terimno esto, entonces se vuelve a la funciÃƒÂ³n principal donde se puede generar uno nuevo
    // si es que se quiere...
}

/*

	DESDE 620 A 760
	AQUI SE ENCUENTRAN TODOS LOS MENUS
	

	






*/

int menuPrincipal(){
    int opc = 0;
    printf("--- Menu Principal ---\n");

    printf("Bienvenido al Sistema 8teenGym");

    printf("\nDecide a que modulo del sistema quiere ingresar: ");
    printf("\n(Para acceder a los modulos antes necesitas tener una cuenta)");
    printf("\nen el sistema. Para ello primero accede a la opcion 0)");
    printf("\n(Luego segun tu cuenta y permisos podes usar los modulos)");

    printf("\n\n0. Registrarse/Iniciar Sesion.");
    printf("\n1. Modulo GYM (ENTRENADORES)");
    printf("\n2. Modulo Recepcion (ADMINISTRADOR)"); 
    printf("\n3. Modulo Adminsitracion (ADMINISTRADORES)");
    printf("\n4. Cerrar el programa");

    printf("\nIngrese su opcion: ");
    scanf("%d", &opc);

    return opc;
}

int menuGym(){
    int opc = 0;
    printf("--- SubMenu GYM ---\n");
    
    printf("1.  Iniciar sesion como entrenador para mas opciones\n");
    printf("2. Cerrar el programa\n");
    printf("10. VOLVER ATRAS\n");

    printf("\nIngrese su opcion: ");
    scanf("%d", &opc);

    return opc; 
}

int submenuRecepcion(){
    int opc = 0;
    printf("--- SubMenu Recepcion ---\n");
    printf("1. Iniciar sesion\n");
    printf("2. Cerrar Aplicacion\n");
    printf("10. VOLVER ATRAS\n");
}

int menuRecepcion(){
    int opc = 0;
    printf("--- SubMenu Recepcion ---\n");
    
    printf("1. Registrar Socios\n");
    printf("2. Registrar actividades de Socios\n");
    printf("3. Listado de Socios\n");
    printf("4. Listado de fechas de pagos\n");
    printf("5. Cerrar Aplicacion\n");
    printf("10. VOLVER ATRAS\n");

    printf("\nIngrese su opcion: ");
    scanf("%d", &opc);

    return opc; 
}

int menuAdmin(){
    int opc = 0;
    printf("--- SubMenu Administracion ---\n");
    
    printf("1. Registrar usuario de Recepcion\n");
    printf("2. Registrar actividades del Gym\n");
    printf("3. Calcular pago del entrenador\n");
    printf("4. Entrenador con mayor carga horaria\n");
    printf("5. Cerrar Aplicacion\n");
    printf("10. VOLVER ATRAS\n");

    printf("\nIngrese su opcion: ");
    scanf("%d", &opc);

    return opc; 
}

int ingresar(){

    int inittial = 0;
    system("cls");

    Sleep(500);

    printf("Elige una opcion: \n");
    printf("\n1. Registrar un Usuario (ADMIN/ENTRENADOR)");
    printf("\n10. Volver atras ");
    
    printf("\nSu opcion es: ");
    scanf("%d", &inittial);

    return inittial;
}

int typeUser(){
    int type = 0;
    system("cls");

    Sleep(500);

    printf("Elige una opcion: \n");
    printf("\n1. Usuario ADMINISTRADOR");
    printf("\n2. Usuario ENTRENADOR");

    printf("\nSu opcion es: ");
    scanf("%d", &type);

    return type;
}

void casoDiez(){

    system("cls");
    printf("\n\nVolviendo atras...");
    printf("\n\n");
    Sleep(1000);

    system("cls");

}

int menuJoinGym(){
    int opc = 0;
    printf("--- SubMenu GYM ---\n");
    
    printf("1. Listar socios y la actividad que desarollan\n");
    printf("2. AÃƒÂ±adir rutina a un grupo especÃƒÂ­fico.\n");
    printf("3. Cerrar el programa\n");
    printf("10. VOLVER ATRAS\n");

    printf("\nIngrese su opcion: ");
    scanf("%d", &opc);

    return opc; 
}

/*

	MODULO GYM --> (765 - 830)


*/

int validarUsuarioEntrenador(FILE *entrenadores, char contrasenia[32], char nombreUser[10]){
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
                if(entrenador.typeAccount == 2){
                    printf("\n\n\t\tLa contrasenia coincide, entonces tendras el acceso.\n\n");
                    bandera = 1;
                }
            }
        }

        fwrite(&entrenador, sizeof(entrenador), 1, entrenadores);
    }

    return bandera;
}

int loguearEntrenador(FILE *entrenadores, char nombreValidado[10]){
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

// ### Funcion loguear base

int loguearEntrenadorEnDB(FILE *entrenadores, char nombreValidado[10]){
    int accept = 0;

    system("cls");

    Sleep(200);
    printf("\nLogearas un Entrenador \n");
    accept = loguearEntrenador(entrenadores, nombreValidado);

    if(accept == 0){ printf("\nHubo un error en el login. Intentelo de nuevo \n"); }

    return accept;
}


/*
 LOGEO DE ADMIN (835 - 900)
*/

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