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


struct dia{
    int lunes;
    int martes;
    int miercoles;
    int jueves;
    int viernes;
    int sabado;
};

struct turnos{
    int turnoManiana;
    int turnoTarde;
    int turnoNoche;
};

struct actividades{
    int legajoEntrenador;
    char nombreActividad[25];
    int codigoActividad;
    dia dias;
    turnos turno;
};

struct socios{
	fecha fech;
    int dni;
    float altura;
    float peso;
    int nroSoc;
    char apynom[60];
    char domicilio[30];
    char rutina[4000];
    actividades actividad;
    // struct enlazado
    // socios --> usuarios.dat
};
 
/*
	Register (55 a 620 aprox)
*/


void listarEntrenadores(FILE *entrenadores, int tipoListar){
	struct adminUser reg;
    int contador = 1;
	
	rewind(entrenadores);
	
	fseek(entrenadores, 0, SEEK_SET);
	
	switch(tipoListar){
		case 1:
            system("cls");
            printf("--- Listado de Entrenadores ---\n", contador);
			fread(&reg, sizeof(reg), 1, entrenadores);

            while(!feof(entrenadores)){
                if(reg.typeAccount == 1){
                    printf("\n\n--- %d ---\n", contador);
                    printf("Nombre Usuario: %s", reg.nombreUsuario);
                    printf("\nLegajo: %d", reg.legajoEntrenador);
                }

                if(reg.typeAccount == 1){ contador++; }
				
                fread(&reg, sizeof(reg), 1, entrenadores);
            }

            printf("\n\n");
		break;
		case 2:
            system("cls");
            printf("--- Listado de Entrenadores ---\n", contador);
			fread(&reg, sizeof(reg), 1, entrenadores);

            while(!feof(entrenadores)){
                if(reg.typeAccount == 2){
                    printf("\n\n--- %d ---\n", contador);
                    printf("Nombre Usuario: %s", reg.nombreUsuario);
                    printf("\nLegajo: %d", reg.legajoEntrenador);
                }

                if(reg.typeAccount == 2){ contador++; }
                fread(&reg, sizeof(reg), 1, entrenadores);
            }

            printf("\n\n");
		break;		
	}
}

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

        fread(&comparingUser, sizeof(comparingUser), 1, entrenadores);
        while(!feof(entrenadores) && bandera == 0){

            comparacion = strcmp(nombreUsuario, comparingUser.nombreUsuario);

            fread(&comparingUser, sizeof(comparingUser), 1, entrenadores);
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
    

    // esta es la unicidad para el administrador

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

        fread(&comparingUser, sizeof(comparingUser), 1, entrenadores);
        while(!feof(entrenadores) && bandera == 0){

            comparacion = strcmp(nombreUsuario, comparingUser.nombreUsuario);

            fread(&comparingUser, sizeof(comparingUser), 1, entrenadores);
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
    

    // Aqui hacemos una nueva

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
    ################################ VALIDACION DE USUARIO ########################

    ################################ VALIDACION DE CONTRASENIA ########################
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

        fwrite(&userWrite, sizeof(userWrite), 1, entrenadores);
        
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

    // Copio el usuario validada al struct para luego guardar al archivo
    strcpy(account.nombreUsuario,nombreUsuario);

    printf("\n\nÂ¡Tu nombre de Usuario es VALIDO!\n");
    printf("\nIngrese la contrasenia: ");

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

    // se terimno esto, entonces se vuelve a la func
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

    // se terimno esto, entonces se vuelve a la func
    // si es que se quiere...
}

/*

	DESDE 620 A 760
	AQUI SE ENCUENTRAN TODOS LOS MENUS
	

	






*/

int menuPrincipal(){
    int opc = 0;
    printf("--- Menu Principal ---\n");

    printf("Bienvenido al Sistema 'Mothers on the move'");

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
    
    printf("1. Iniciar sesion como entrenador para mas opciones\n");
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
    
    printf("\nIngrese su opcion: ");
    scanf("%d", &opc);

    return opc; 
}

int menuRecepcion(){
    int opc = 0;
    printf("--- SubMenu Recepcion ---\n");
    
    printf("1. Registrar Socios\n");
    printf("2. Listado de Socios\n");
    printf("3. Listado de fechas de pagos\n");
    printf("4. Cerrar Aplicacion\n");
    printf("10. VOLVER ATRAS\n");

    printf("\nIngrese su opcion: ");
    scanf("%d", &opc);

    return opc; 
}

int menuAdmin(){
    int opc = 0;
    printf("--- SubMenu Administracion ---\n");
    
    printf("1. Registrar Actividades en el Gym\n");
    printf("2. Calcular pago del entrenador\n");
    printf("3. Entrenador con mayor carga horaria\n");
    printf("4. Cerrar Aplicacion\n");
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
    printf("\n2. Listar Administradores / Entrenadores (con legajo)");
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
    printf("2. Registrar una rutina para un grupo especifico.\n");
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
    
    fclose(entrenadores);
    
    entrenadores = fopen("Entrenadores.dat","a+b");
    rewind(entrenadores);

    fread(&entrenador, sizeof(entrenador), 1, entrenadores);

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

        fread(&entrenador, sizeof(entrenador), 1, entrenadores);
    }

    return bandera;
}

int loguearEntrenador(FILE *entrenadores, char nombreValidado[10]){
    char nombreUsuario[10];
    char contrasenia[32];
    int accept = 0;

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
    
    fclose(entrenadores);
    entrenadores = fopen("Entrenadores.dat","a+b"); // abrir archivo
    
    rewind(entrenadores);
    fseek(entrenadores, 0, SEEK_END);
    
    int size = ftell(entrenadores);
   	
	if(size == 0) {
		printf("\nError, no existen administradores para ingresar. Crea uno... \n\n");
		system("pause");
		
		system("cls");
	}else{
		
    	rewind(entrenadores);

    	fread(&entrenador, sizeof(entrenador), 1, entrenadores);	
    	
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

        	fread(&entrenador, sizeof(entrenador), 1, entrenadores);
    	}
    	
	}

	printf("\n"); system("pause");
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

    accept = validarAdmin(entrenadores, contrasenia, nombreUsuario);

    strcpy(nombreValidado,nombreUsuario);

    return accept;
}

int loguearAdminsitradorDb(FILE *entrenadores, char nombreValidado[10]){
    int accept = 0;

    system("cls");

    Sleep(200);
    printf("\nLogearas un Administrador \n");
    accept = loguearAdministrador(entrenadores, nombreValidado);

    if(accept == 0){ printf("\nHubo un error en el login. Intentelo de nuevo \n"); }

    return accept;
}



// Modulo de Recepcion 900 en adelante

int generarNumSoc() {
    srand(time(NULL)); 
    return rand() % 99999 + 10000; 
}

void registrarSocio(FILE *archSocios, int &nroSocio, char nombreUser[10]) {
    socios socio;
    char apynombre[60];
    char domicilio[30];
    int dni;
    float altura;
    float peso;
    int dia, mes, anio;

    system("cls");
    printf("Ingrese el nombre: ");
    _flushall();
    gets(apynombre);
    printf("\nIngrese el domicilio: ");
    _flushall();
    gets(domicilio);
    printf("\nIngrese el DNI: ");
    scanf("%d", &dni);

    nroSocio = generarNumSoc();

    printf("\nIngrese la Altura (mts): ");
    scanf("%f", &altura);
    printf("\nIngrese el peso (kg): ");
    scanf("%f", &peso);

    printf("\nIngrese el dia que ingreso el socio: ");
    scanf("%d", &dia);
    printf("\nIngrese el mes que ingreso el socio: ");
    scanf("%d", &mes);
    printf("\nIngrese el anio que ingreso el socio: ");
    scanf("%d", &anio);

    socio.fech.dia = dia;
    socio.fech.mes = mes;
    socio.fech.anio = anio;
    socio.altura = altura;
    socio.peso = peso;
    socio.dni = dni;
    socio.nroSoc = nroSocio;
    strcpy(socio.apynom,apynombre);
    strcpy(socio.domicilio,domicilio);

    fwrite(&socio, sizeof(socios), 1, archSocios);

    printf("\nSocio registrado correctamente por el administrador %s ...\n", nombreUser);
    // aqui se puede hacer una correcion:
    
    /*
    	Hacemos una comparacion dependiendo del size del arch dependiendo en que momento esta,
    	si es que el sizeActual es mayor que el sizeAnterior entonces el archivo se modifico y ademas
    	se creo un nuevo socio, por lo tanto se genero.
    	
    	Aqui esta posible exception no esta considerada.
    */
}

// listarSocios -> 3
void listarSocios(FILE *archSocios){
    int contador = 0;
    socios socio;

    system("cls");
	rewind(archSocios);
    fread(&socio, sizeof(socios), 1, archSocios);

    while(!feof(archSocios)){
        printf("\nSocio [%d] \n", contador);
        printf("Apellido y Nombre: %s \n", socio.apynom);
        printf("Nro Socio: %d \n", socio.nroSoc);
        printf("DNI: %d \n", socio.dni);
        printf("Altura: %f \n", socio.altura);
        printf("Peso: %f \n", socio.peso);
        printf("Domicilio: %s \n", socio.domicilio);
        printf("\n--------------------");

        fread(&socio, sizeof(socios), 1, archSocios);
    }
    
    printf("\n\n");
	system("pause");
}

// listarSocios -> 4

void listarFechaPagos(FILE *archSocios){
    int contador = 0;
    socios socio;

    system("cls");
    rewind(archSocios);

    int size = ftell(archSocios);
    fseek(archSocios,0,SEEK_END);

    if(archSocios == 0){
        printf("\n\nNo pudimos listar el archivo de socios...\n\n");
        
    }else{

        rewind(archSocios);

        fread(&socio, sizeof(socios), 1, archSocios);

        printf("\nListado de Fecha de Pagos... \n");

        while(!feof(archSocios)){

            printf("\nSocio %d \n", contador);
            
            printf("Dia: %d \n", socio.fech.dia);
            printf("Mes: %d \n", socio.fech.mes);
            printf("Anio: %d \n", socio.fech.anio);
            printf("\n--------------------");

            fread(&socio, sizeof(socios), 1, archSocios);
        }
    }

}

/*

    Modulo Gimnasio
  
*/

// listado de socios actividad posicion 1068
/*
void listadoSociosActividad(FILE *archSocios){
    int contador = 0;
    socios socio;

    system("cls");
	rewind(archSocios);
	
	fseek(archSocios, 0, SEEK_END);
	int tamanio = ftell(archSocios);
	
	if(tamanio == 0){
		system("cls");
		printf("No hay socios que listar, el archivo esta vacio...\n\n");
		system("pause");
	}else{
    	fread(&socio, sizeof(socios), 1, archSocios);

    	while(!feof(archSocios)){
        	printf("\nSocio %d \n", contador);
        	printf("Apellido y Nombre: %d \n", socio.apynom);
        	printf("Nro Socio: %d \n", socio.nroSoc);
        	printf("DNI: %d \n", socio.dni);
        	printf("Altura: %d \n", socio.altura);
        	printf("Peso: %d \n", socio.peso);
        	printf("Domicilio: %d \n", socio.domicilio);
        	printf("\n\n");
        	printf("Actividades: ");
        	printf("\n--------------------");
        	if(socio.actividad.Zumba == 1){
            	printf("\nEl socio hace Zumba. \n");
        	}
        	if(socio.actividad.Spining == 1){
            	printf("\nEl socio hace Spining. \n");
        	}
        	if(socio.actividad.Pilate == 1){
            	printf("\nEl socio hace Pilates. \n");
        	}

        	fread(&socio, sizeof(socios), 1, archSocios);
    	}	
	}
	
    printf("\n\n");
}
*/

int contarPalabras(char cadena[4000]){
    int i, contadorPalabras = 0;
    int longitud = strlen(cadena);
    
    for(i=0; i<longitud; i++)
    {
        if(cadena[i] == ' ' || cadena[i] == '\0')
        {
            contadorPalabras++;
        }
    }
    
    return (contadorPalabras + 1);
}

int buscarSocio(FILE *archSocios, int numeroSocio){
	socios socio;
	int bandera = 0;
	
	rewind(archSocios);
	
	fread(&socio, sizeof(socios), 1, archSocios);
	
	while(!feof(archSocios) && bandera == 0){
		if(numeroSocio == socio.nroSoc){
			bandera = 1;
		}
		
		fread(&socio, sizeof(socios), 1, archSocios);
	}
	
	return bandera;
}

void registrarRutina(FILE *archSocios){
    socios socio;
    char rutina[4000];
    int numeroSocio;
    int cantidadPalabras = 0;
    
    rewind(archSocios);
    fseek(archSocios, 0, SEEK_END);
    
    int size = ftell(archSocios);
    
    if(size == 0){
    	printf("\nNo podemos registrar una rutina, no existen socios. \n\n");
    	system("pause");
	}
	else{
		printf("\nIngrese el numero de Socio: ");
		scanf("%d", &numeroSocio);
		
		rewind(archSocios);
    
    	int encontroSocio = buscarSocio(archSocios, numeroSocio);
    
		if(encontroSocio == 1){

            // aqui contamos la cantidad de caracteres...
            
            do {
                printf("\nIngrese la rutina (No mas de 380 palabras): ");
                _flushall();
                gets(rutina);

                cantidadPalabras = contarPalabras(rutina);
                
            }while(cantidadPalabras > 380);
            
            strcpy(socio.rutina,rutina);
            printf("\n\nRegistro correctamente la rutina\n\n");	

		}else{
            printf("\nNo se pudo encontrar el socio en el registro... \n\n");
        }
	}

    system("pause");
    
}

//  ### registrarActividades

int generarCodigoActividad() {
  srand(time(NULL));
  int codigo = rand() % 1000000000 + 100000000;
  return codigo;
}


int encontrarEntrenador(FILE *entrenadores, int legajo)
{
    // busco el archivo con coincidencias - 1 lo encontre 0 no lo encontre
    int bandera = 0;
    struct adminUser entrenador;

    fclose(entrenadores);
    entrenadores = fopen("Entrenadores.dat", "a+b"); // abrir archivo

    rewind(entrenadores);
    fseek(entrenadores, 0, SEEK_END);

    int size = ftell(entrenadores);

    if (size == 0)
    {
        printf("\nError, no existen entrenadores para ingresar. Crea uno... \n\n");
        system("pause");

        system("cls");
    }
    else
    {

        rewind(entrenadores);

        fread(&entrenador, sizeof(entrenador), 1, entrenadores);

        while (!feof(entrenadores) && bandera == 0)
        {
            if (legajo == entrenador.legajoEntrenador)
            {
                if (entrenador.typeAccount == 2)
                {
                    printf("\n\n\t\tEncontramos el entrenador...\n\n");
                    bandera = 1;
                }
            }
            fread(&entrenador, sizeof(entrenador), 1, entrenadores);
        }
    }

    printf("\n");
    system("pause");
    return bandera;
}

int acepto(FILE *archActividades, actividades rA, int turno){
    int accept = 0;
    if((turno == rA.turno.turnoManiana ||  turno == rA.turno.turnoTarde || turno == rA.turno.turnoNoche) == 1){
        accept = 1;
    }

    return accept;
}

int comprobarActividades(FILE *archActividades, int codigo, int turno, int dia, actividades registroAct){
    int accept = 0;
    int bandera = 0;
    
    rewind(archActividades);

    fclose(archActividades);
    archActividades = fopen("Actividades.dat","a+b");

    // una vez abierto comprobamos todo...

    rewind(archActividades);

    fread(&registroAct, sizeof(registroAct), 1, archActividades);

    while(!feof(archActividades) && bandera == 0){

        if(codigo == registroAct.legajoEntrenador){
            switch(dia){
                case 1:
                    accept = acepto(archActividades, registroAct, turno);
                break;
                case 2:
                    accept = acepto(archActividades, registroAct, turno);
                break;
                case 3:
                    accept = acepto(archActividades, registroAct, turno);
                break;
                case 4:
                    accept = acepto(archActividades, registroAct, turno);
                break;
                case 5:
                    accept = acepto(archActividades, registroAct, turno);
                break;
                case 6:
                    accept = acepto(archActividades, registroAct, turno);
                break;
                default:
                    printf("\nHubo un error se ingreos un día equivocado y el programa se corrompera :D");
            }
        }

        fread(&registroAct, sizeof(registroAct), 1, archActividades);   

    }   // fin del bucle while

    // si accept aqui esta en 1 significa que encontro una actividad en el mismo turno, en casmbio si no, no la encontro.
    return accept;
}

void registrarActEnArch(FILE *archActividades, actividades registroAct){

    rewind(archActividades);

    fclose(archActividades);
    archActividades = fopen("Actividades.dat","a+b");

    rewind(archActividades);
    fseek(archActividades,0,SEEK_END);

    fwrite(&registroAct,sizeof(registroAct),1,archActividades);

}

void registrarActividad(FILE *archActividades, FILE *entrenadores, FILE *archSocios, char nombreValidado[10]){
    char nombreActividad[25];
    int legajoEntrenador = 0;
    int turno = 0;
    int existeEntrenador = 0;
    int codigo = 0;
    int comprobacion = 0;
    int dia = 0;
    system("cls");
    struct actividades registroAct;

    rewind(archActividades);
    fseek(archActividades,0,SEEK_END);
    
    rewind(archSocios);
    fseek(archSocios,0,SEEK_END);
    
    int size = ftell(archSocios);
    
    if(size == 0){
    	printf("\nNo podemos registrar una rutina, no existen socios. \n\n");
    	system("pause");
	}else{
        _flushall();
        printf("Ingrese el nombre de la actividad: ");
        gets(nombreActividad);

        printf("\nIngrese el legajo del entrenador: ");
        scanf("%d",&legajoEntrenador);

        printf("\nIngrese el dia de la actividad (1-6): ");
        scanf("%d", &dia);
        
        printf("\nIngrese el turno de la actividad (1-2-3): ");
        scanf("%d", &turno);

        existeEntrenador = encontrarEntrenador(entrenadores, legajoEntrenador);

        if(existeEntrenador == 1){
            codigo = generarCodigoActividad();
            printf("\nComprobaremos si no existe otra actividad en el mismo tiempo... \n\n");

            comprobacion = comprobarActividades(archActividades, codigo, turno, dia, registroAct);

            if(comprobacion == 1){
                registroAct.codigoActividad = codigo;
                registroAct.legajoEntrenador = legajoEntrenador;
                strcpy(registroAct.nombreActividad,nombreActividad);

                switch(dia){
                    case 1:
                       registroAct.dias.lunes;
                    break;
                    case 2:
                        registroAct.dias.martes;
                    break;
                    case 3:
                        registroAct.dias.miercoles;
                    break;
                    case 4:
                        registroAct.dias.jueves;
                    break;
                    case 5:
                        registroAct.dias.viernes;
                    break;
                    case 6:
                        registroAct.dias.sabado;
                    break;
                    default:
                        printf("\nHubo un error se ingreos un día equivocado y el programa se corrompera :D");
                    break;
                }
                switch(turno){
                    case 1:
                        registroAct.turno.turnoManiana = 1;
                    break;
                    case 2:
                        registroAct.turno.turnoTarde = 1;
                    break;
                    case 3:
                        registroAct.turno.turnoTarde = 1;
                    break;
                    default:
                        printf("\nHubo un error se ingreos un día equivocado y el programa se corrompera :D");
                    break;
                }

                registrarActEnArch(archActividades,registroAct);
            }
        }else{
            printf("\n\nNo existe el entrenador, por lo tanto no se pudo generar la actividad.\n\n");
            system("pause");
        }
    }
}

// # pago-entrenador

int contarCantidades(FILE *archActividades, int legajoEntrenador){
    struct actividades reg;
    int contador = 0;

    if(reg.legajoEntrenador == legajoEntrenador){
        if(reg.dias.lunes == 1){
            if(reg.turno.turnoManiana == 1){ contador++; }
            if(reg.turno.turnoTarde == 1){ contador++; }
            if(reg.turno.turnoNoche == 1){ contador++; }
        }
        if(reg.dias.martes == 1){
            if(reg.turno.turnoManiana == 1){ contador++; }
            if(reg.turno.turnoTarde == 1){ contador++; }
            if(reg.turno.turnoNoche == 1){ contador++; }
        }
        if(reg.dias.miercoles == 1){
            if(reg.turno.turnoManiana == 1){ contador++; }
            if(reg.turno.turnoTarde == 1){ contador++; }
            if(reg.turno.turnoNoche == 1){ contador++; }
        }
        if(reg.dias.jueves == 1){
            if(reg.turno.turnoManiana == 1){ contador++; }
            if(reg.turno.turnoTarde == 1){ contador++; }
            if(reg.turno.turnoNoche == 1){ contador++; }
        }
        if(reg.dias.viernes == 1){
            if(reg.turno.turnoManiana == 1){ contador++; }
            if(reg.turno.turnoTarde == 1){ contador++; }
            if(reg.turno.turnoNoche == 1){ contador++; }
        }
        if(reg.dias.sabado == 1){
            if(reg.turno.turnoManiana == 1){ contador++; }
            if(reg.turno.turnoTarde == 1){ contador++; }
            if(reg.turno.turnoNoche == 1){ contador++; }
        }
    }

    return contador;
}

void calcularPagoEntrenador(FILE *archActividades, int legajoEntrenador){
    printf("\n\nInformación acerca del Entrenador (Legajo): %d ", legajoEntrenador);

    int sueldo = contarCantidades(archActividades, int legajoEntrenador);
    printf("\nSueldo: $%d franDollars", sueldo*20);
}

// socios --> actividades --> ? (legajoEntrenador = legajo) : dias --> turnos (counter) : entrenadorNoLegajo
// se puede hacer de esa forma...


void calcularMayorCargaHoraria(FILE *entrenadores, FILE *archActividades){
    struct adminUser entrenador;
    struct adminUser maximoEntrenador;
    struct actividades registroContador;
    int legajo = 0;
    int cantidades = 0;
    int maximo = 0;
    int legajoMaximo = 0;
    int bandera = 0;


    rewind(entrenadores);
    rewind(archActividades);

    fseek(entrenadores, 0, SEEK_END);
    fseek(archActividades, 0, SEEK_END);

    int sizeEntrenadores = ftell(entrenadores);
    int sizeArchActividades = ftell(archActividades);

    if(sizeEntrenadores == 0 || sizearchActividades == 0){
        printf("\n\nOcurrio un error, hay algun archivo vacio.");
    }
    else{

        rewind(entrenadores);
        rewind(archActividades);

        fread(&entrenador, sizeof(entrenador), 1, entrenadores);

        while(!feof(entrenadores)){
            legajo = entrenador.legajoEntrenador;

            cantidades = contarCantidades(archActividades, legajo);

            if(cantidades > maximo){
                maximo = cantidades;
                legajoMaximo = legajo;
            }

            fread(&entrenador, sizeof(entrenador), 1, entrenadores);
        }

        rewind(entrenadores);
        rewind(archActividades);

        // como aca ya tengo el legajoMaximo y el maximo total los imprimo por pantalla

        fread(&entrenador, sizeof(entrenador), 1, entrenadores);

        while(!feof(entrenadores) && bandera == 0){
            if(legajo == legajoMaximo){
                bandera = 1;
                maximoEntrenador = entrenador;
            }

            fread(&entrenador, sizeof(entrenador), 1, entrenadores);
        }

        printf("\n\n------- # Entrenador con Maxima Carga Horaria # -------");

        printf("\nNombre Usuario: %s", maximoEntrenador.nombreUsuario);
        printf("\nApellido y nombre: ");
        _flushall();
        puts(maximoEntrenador.nombreUsuario);
        printf("\nLegajo del Entrenador: %d", maximoEntrenador.legajoEntrenador);

        printf("\n\n------- # Entrenador con Maxima Carga Horaria # ------- \n");

        system("pause");
    }

}