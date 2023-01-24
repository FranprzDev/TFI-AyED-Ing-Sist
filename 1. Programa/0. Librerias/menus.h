#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int menuPrincipal(){
    int opc = 0;
    printf("--- Menu Principal ---\n");

    printf("Bienvenido al Sistema 8teenGym");

    printf("\nDecide a que modulo del sistema queires ingresar: ");
    printf("\n(Para acceder a los modulos antes tienes que haber iniciado sesion)");

    printf("\n\n0. Iniciar Sesion.");
    printf("\n1. Modulo GYM");
    printf("\n2. Modulo Recepcion"); 
    printf("\n3. Modulo Adminsitracion");
    printf("\n4. Cerrar el programa");

    printf("\nIngrese su opcion: ");
    scanf("%d", &opc);

    return opc;
}

int menuGym(){
    int opc = 0;
    printf("--- SubMenu GYM ---\n");
    
    printf("1. Visualizar listado de Socios y la actividad que desarrollan\n");
    printf("2. Registrar rutinas de Gimnasia.\n");
    printf("3. Cerrar la aplicacion\n");
    printf("10. VOLVER ATRAS\n");

    printf("\nIngrese su opcion: ");
    scanf("%d", &opc);

    return opc; 
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
    
    printf("1. Registrar usuario de Recepción\n");
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

    Sleep(1000);

    printf("Elige una opcion: \n");
    printf("\n1. Registrar un Usuario");
    printf("\n2. Iniciar Sesion");
    printf("\n10. Volver atras ");
    
    printf("\nSu opcion es: ");
    scanf("%d", &inittial);

    return inittial;
}

int typeUser(){
    int type = 0;
    system("cls");

    Sleep(1000);

    printf("Elige una opcion: \n");
    printf("\n1. Usuario NORMAL");
    printf("\n2. Usuario ENTRENADOR");

    printf("\nSu opcion es: ");
    scanf("%d", &type);

    return type;
}

void contraseniaValida(int opc){
    switch(opc){
        case 1:
            printf("\n\n¡Tu Contrasenia es VALIDA!\n");
            printf("\n\n¡Generaremos tu Usuario de tipo NORMAL!\n");
            printf("\nEspere...");
            Sleep(2000);
            break;
        case 2:
            printf("\n\n¡Tu Contrasenia es VALIDA!\n");
            printf("\n\n¡Generaremos tu Usuario de tipo ENTRENADOR!\n");
            printf("\nEspere...");
            Sleep(2000);
            break;
        default:
            printf("\nImposible acceder aqui...");
            break;
    }
}

void menuDeRegister(int opc){
    switch(opc){
        case 1:
                system("cls");
                Sleep(1000);
                printf("----- CUENTA NORMAL -----\n");
                printf("Ingrese su nombre de Usuario: ");
            break;
        case 2:
                system("cls");
                Sleep(1000);
                printf("----- CUENTA ENTRENADOR -----\n");
                printf("Ingrese su nombre de Usuario: ");
            break;
        case 3:
                system("cls");
                printf("Ingrese su nombre de Usuario: ");
            break;
        case 4:
                printf("\n\n¡Tu nombre de Usuario es VALIDO!\n");
                printf("\nIngrese la contrasenia: ");
            break;
        case 5:
                printf("\n\nLa longitud es muy corta, vuelve a ingresar la contrasenia \n\n");
                printf("\nIngrese la contrasenia: ");
            break;
        case 6:
                system("cls");
                printf("\nIngrese la contrasenia: ");
            break;
        default:
            printf("\nImposible acceder aqui...");
            break;
    }
}

void erroresRegister(int opc){
    switch(opc){
        case 1:
            printf("\n\nEl error esta en que el usuario empieza con minuscula.\n\n");
            break;
        case 2:
            printf("\n\nEl error esta en que el usuario no tiene al menos 2 Mayusculas.\n\n");
            break;
        case 3:
            printf("\n\nEl error esta en que el nombre de Usuario es muy corto..\n\n");
            break;
        case 4:
            printf("\n\nEl error esta en que hace falta un numero/mayuscula/miniscula \n\n ");
            break;
        case 5:
            printf("\n\nEl error es que se encontraron caracteres que no son alfanumericos. \n\n ");
            break;
        case 6:
            printf("\n\nExisten al menos 3 caracteres numericos consecutivos. ");
            break;
    }
}

void generacionCuentas(int opc){
    switch(opc){
        case 1:
            system("cls");
            Sleep(1000);
            printf("\n\nSe genero correctamente la cuenta del tipo USUARIO");
        break;
        case 2:
            system("cls");
            Sleep(1000);
            printf("\n\nSe genero correctamente la cuenta del tipo ENTRENADOR");
        break;
    }
}