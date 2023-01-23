#include "../0. Librerias/funcGeneral.h"

void iniciarSesion(){

    char nombreUsuario[10];

    system("cls");

    Sleep(1000);

    printf("----- Inicio de Sesion -----");

    printf("Ingrese su usuario: ");

    gets()
}  

void generarCuentaNormal() {
    system("cls");
    int validacionNombreUser = 0;
    int validacionContrasenia = 0;
    int longitud = 0;
    int bandContrasenia;

    char nombreUsuario[10]
    char contrasenia[32];
    Sleep(1000);

    printf("----- CUENTA NORMAL -----\n");

    printf("Ingrese su nombre de Usuario: ");

    _flushall();
    gets(nombreUsuario);

    validacionNombreUser = validarNombreUsuarioNormal(nombreUsuario);

    if(validacionNombreUser == 1){
        printf("\n\n¡Tu nombre de Usuario es VALIDO!\n");

        _flushall();

        printf("\nIngrese la contrasenia: ");
        gets(contrasenia);

        longitud = calcLong(contrasenia);

        if(longitud < 6){
            do{
                printf("\n\nLa longitud es muy corta, vuelve a ingresar la contrasenia \n\n");
                printf("\nIngrese la contrasenia: ");
                _flushall();
                gets(contrasenia);

                longitud = calcLong(contrasenia);
            
                if(longitud >= 6){ bandContrasenia = 1; }
            }while(bandContrasenia == 0 || longitud < 6);
        }

        validacionContrasenia = validarContraseniaUsuarioNormal(contrasenia, longitud);
        // validacionContrasenia obtencion de la validacion del register

    }

} // fin funcion

int validarNombreUsuarioNormal(char nombreUsuario[10]){
    int validacion = 0;
    int unicidad = 0;
    int minuscula = 0;
    int mayuscula = 0;
    int minimo = 0;
    
    unicidad = validarUnicidadNormal(nombreUsuario);
    minuscula = validarComienzoEnMinusculaNormal(nombreUsuario);
    mayuscula = validarMayusculaNormal(nombreUsuario);
    minimo = validarMinimoNormal(nombreUsuario);

    // Para que deje crear todos los accept tienen que ser 1

    if(unicidad == 1 && minuscula == 1 && mayuscula == 1 && minimo == 1)
    {  validacion = 1; }

    return validacion;
}

int validarUnicidadNormal(char nombreUsuario[10]){
    // aqui se debe validar si es el unico nombre de usuario en usuarios.dat
    // para esto aplicare una busqueda comparando strings

    int accept = 0;
    int bandera = 0;
    int comparacion = 1000;
    user comparingUser;

    rewind(usuarios);

    fwrite(&comparingUser, sizeof(comparingUser), 1, usuarios);
    while(!feof(usuarios) && bandera == 0){

        comparacion = strcmp(nombreUsuario, comparingUser.nombreUsuario);

        if(comparacion == 0){ bandera = 1; }

        fwrite(&comparingUser, sizeof(comparingUser), 1, usuarios);
    }

    if(comparacion == 0){ accept = 1; }

    return accept;
}

int validarComienzoEnMinusculaNormal(char nombreUsuario[10]){
    // aqui valido si comienza en miniscula

    int accept = 0;
    int comienzaMinuscula = 0;

    if(nombreUsuario[0] >= 'a' && nombreUsuario[0] <= 'z') { comienzaMinuscula = 1; }

    if(comienzaMinuscula == 1){ accept = 1; };
    
    if(accept = 0)
    { printf("\n\nEl error esta en que el usuario empieza con Mayuscula.\n\n"); }
    return accept;
}

int validarMayusculaNormal(char nombreUsuario[10]){
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
    { printf("\n\nEl error esta en que el usuario no tiene al menos 2 Mayusculas.\n\n"); }

    return accept; 
}

int validarMinimoNormal(char nombreUsuario[10]){
    // buscamos que el minimo sean 3 caracteres
    int accept = 0;
    int count;

    for(int i = 0; i < 10; i++)
    { if(nombreUsuario[i] != "\0") { count++; } }

    if(count >= 3) {
        accept = 1;
    }

    if(accept = 0)
    { printf("\n\nEl error esta en que el nombre de Usuario es muy corto..\n\n"); }

    return accept;
}

int validarContraseniaUsuarioNormal(char contrasenia[32], int longitudContra){
    int validacionTriple = 0;
    int caracterAlfanumerico = 0;
    int caractNumConsecut = 0;
    int consecutividadAlfabetica = 0;
    int longitudContra = 0;

    validacionTriple = validTriple(contrasenia, longitudContra);
    caracterAlfanumerico = caractAlfa(contrasenia, longitudContra);
    caractNumConsecut = caracterConsecNum(contrasenia, longitudContra); 
    consecutividadAlfabetica = consecutivAlfab(contrasenia, longitudContra);

}   

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

    if(accept = 0) { printf("\n\nEl error esta en que hace falta un numero/mayuscula/miniscula \n\n "); }
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

    if(accept = 0) { printf("\n\nEl error es que se encontraron caracteres que no son alfanumericos. \n\n "); }
    return accept;
}

int calcLong(char contrasenia[32], int longitudContra){
    int contador = 0;

    for(int i = 0; i < 32; i++){
        if(contrasenia[i] != "/0"){ contador++;} 
        if(contrasenia[i] == "/0"){ i = 32; }
    }

    return contador;
}

int caracterConsecNum(char contrasenia[32], int longitudContra){
    // de 48 a 57 es numerico
    int consecutivos = 0;
    int accept = 0;
    
    for(int i = 0; i < longitudContra-2; i++){
        if(contrasenia[i] >= 48 && contrasenia[i] <= 57){
            if(contrasenia[i+1] >= 48 && contrasenia[i+1] <= 57){
                if(contrasenia[i+2] >= 48 && contrasenia[i+2] <= 57){
                    consecutivos = 1;
                    if(consecutivos == 1){ i = longitudContra-2; }
                }
            }
        }
    }

    if(consecutivos == 0){ accept = 1; }

    if(consecutivos == 1)
    { printf("\n\nExisten al menos 3 caracteres numericos consecutivos, no se pudo crear la contrasenia ");   }
    
    return accept; 
}

int consecutivAlfab(char contrasenia[32], int longitudContra){
    // letras consecutivas alfabeticamente.
    int seguidos = 0;
    int accept = 0;
    int codigoAscii = 0;

    for(int i = 0; i < longitudContra; i++){
        
        if((contrasenia[i] >= 65 && contrasenia[i] <= 90) && (contrasenia[i] >= 97 && contrasenia[i] <= 122)){
            codigoAscii = contrasenia[i];

            // ABCEDARIO = {u,v,w,x,y,z}
            /*
                No hay dos caracteres que le siga ascendentemente a z (long -1)
            */

            if(contrasenia[i] >= 65 && contrasenia[i] <= 79){
                if(contrasenia[i+1] == codigoAscii++){ seguidos++; }
            } 

            if(contrasenia[i+1] >= 97 && contrasenia[i] <= 121){
                if(contrasenia[i+1] == codigoAscii++){ seguidos++;}
            }   
        
            if(seguidos >= 1){ i = longitudContra; }
        }    
    }

    if(seguidos >= 1)
    { printf("\n\nNo pudimos crear la contrasenia ya que tienes mas de dos letras seguidas ascendentemente. \n"); }

    if(seguidos == 0)
    { accept = 1; }

    return accept;
}
