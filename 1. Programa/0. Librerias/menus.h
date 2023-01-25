#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int menuPrincipal(){
    int opc = 0;
    printf("--- Menu Principal ---\n");

    printf("Bienvenido al Sistema 8teenGym");

    printf("\nDecide a que modulo del sistema quiere ingresar: ");
    printf("\n(Para acceder a los modulos antes tienes que haberte registrado)");

    printf("\n\n0. Registrarse/Iniciar Sesion.");
    printf("\n1. Modulo GYM (ENTRENADORES)");
    printf("\n2. Modulo Recepcion (RECEPCIONISTAS)"); 
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
    
    printf("1. Registrar usuario de RecepciÃ³n\n");
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
            printf("\n\nÂ¡Tu Contrasenia es VALIDA!\n");
            printf("\n\nÂ¡Generaremos tu Usuario de tipo NORMAL!\n");
            printf("\nEspere...");
            Sleep(2000);
            break;
        case 2:
            printf("\n\nÂ¡Tu Contrasenia es VALIDA!\n");
            printf("\n\nÂ¡Generaremos tu Usuario de tipo ENTRENADOR!\n");
            printf("\nEspere...");
            Sleep(2000);
            break;
        default:
            printf("\nImposible acceder aqui...");
            break;
    }
}