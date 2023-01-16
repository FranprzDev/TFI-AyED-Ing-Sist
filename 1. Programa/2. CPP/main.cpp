#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string.h>
#include "../0. Librerias/mylibrery.h"

int menuPrincipal();
int menuGym();
int menuReception();
int menuAdminsitration();


main(){

    /* 
        Sección de Varaibles & Constantes
    */
    int opc = 0;
    int banderaCerrado = 1;
    int opcSwitchGym = 0;
    int opcSwitchReception = 0;
    int opcSwitchAdministration = 0;

    /*
        Seccción de Código
    */

    do{
        system("cls");

        opc = menuPrincipal()

        switch(opc){
            case 1:
                system("cls");
                opcSwitchGym = menuGym();

                switch(opcSwitchGym){
                    case 1:
                        // iniciarSesion_GYM();
                    break;
                    case 2:
                        // Listado de Socios - Desarrollo de actividad
                        /*
                            Aca depende mucho como quieran programarlo, si es que realmente
                            lo quieren hacer un vector o qsy, por ahí la pueden mandar...
                            + facil 1 swtich con 1 listado de socios y 2 actividad y listo
                        */
                    break;
                    case 3:
                        // registrarRutina_GYM();
                    break;
                    case 4:
                        printf("\n\nOk. Cerraremos el Programa.");
                        banderaCerrado = 0;
                        /* 
                            aca estos cierres de aplicacion lo podemos trabajar de 2 formas:
                            depende como lo quieran trabajar usteeds lo hacemos ...

                            Puedo crear una funcion cerrar() { exit(1) } pero tenemos que fijarnos
                            bien que onda con cuales son los archivos que tenemos para cerrarlos bien, porque
                            si no vamos a tener problemas después.

                            La otra es trabajar cerrandole la bandera común . pero eso indica que trabajaremos
                            con 1 archivo abierto 1 sola vez durante todo el programa y así será (sin toqueteos raros)

                            Aquí se utiliza la idea de no toquetear de forma rara.
                        */ 
                    break;
                    default: 
                        printf("\n\nIngreso una opcion incorrecta, por lo tanto cerraremos el programa.");
                        banderaCerrado = 0;
                    break;
                }
            break;
            case 2:
                system("cls");
                opcSwitchReception = menuReception();
                
                switch(opcSwitchReception){
                    // de mi parte prefiero tirar funciones void para hacer estas cosas 
                    // dentro de las funciones void hacer todo xd
                    // sugiero los nombres de las func y ademas bueno q deben hacer queda implicito
                    case 1:
                        // iniciarSesion_Reception();
                    break;
                    case 2:
                        // registrarSocios_Reception()
                    break;
                    case 3:
                        // registrarActividadesSociso_Reception();
                    break;
                    case 4:
                        // listadoDeSocios_Reception();
                    break;
                    case 5:
                        // listadoFechasPagos_Reception();
                    break;
                    case 6:
                        printf("\n\nOk. Cerraremos el Programa.");
                        banderaCerrado = 0;    
                    break;
                    default:
                        printf("\n\nIngreso una opcion incorrecta, por lo tanto cerraremos el programa.");
                        banderaCerrado = 0;
                    break;
                }
            break;
            case 3:
                system("cls");
                opcSwitchAdministration = menuAdminsitration();

                switch(opcSwitchAdministration){
                    case 1:
                        // iniciarSesion_Administration();
                    break;
                    case 2:
                        // registrarUsuario_Administration();
                    break;
                    case 3:
                        // registrarActividades_Administration();
                    break;
                    case 4:
                        // calcularPagoEntrenador_Administration();
                    break;
                    case 5:
                        // entrenadorMaxCargaHs_Administration();
                    break;
                    case 6:
                        printf("\n\nOk. Cerraremos el Programa.");
                        banderaCerrado = 0;    
                    break;
                    default:
                        printf("\n\nIngreso una opcion incorrecta, por lo tanto cerraremos el programa.");
                        banderaCerrado = 0;
                    break;
                }
            break;
            case 4:
                printf("\n\nOk. Cerraremos el Programa.");
                banderaCerrado = 0;
            break;
            defualt:
                printf("\n\nIngreso una opcion incorrecta, por lo tanto cerraremos el programa.");
                banderaCerrado = 0;
            break;
        }
    }while(banderaCerrado == 1);

    printf("\n");

} // fin del main


    /*
        Todas estas funciones después las mandamos a la librería 
    */

int menuPrincipal(){
    int opc = 0;
    printf("--- Menu Principal ---\n");

    printf("Bienvenido al Sistema 8teenGym");

    printf("\nDecide a que módulo del sistema queires ingresar: ");

    printf("\n1. Módulo GYM");
    printf("\n2. Módulo Recepción");
    printf("\n3. Módulo Adminsitración");
    printf("\n4. Cerrar el programa");

    printf("\nIngrese su opcion: ");
    scanf("%d", &opc);

    return opc;
}

void menuGym(){
    int opc = 0;
    printf("--- SubMenu GYM ---\n");
    
    printf("1. Iniciar sesion \n");
    printf("2. Visualizar listado de Socios y la actividad que desarrollan\n");
    printf("3. Registrar rutinas de Gimnasia.\n");
    printf("4. Cerrar la aplicación\n");

    printf("\nIngrese su opcion: ");
    scanf("%d", &opc);

    return opc; 
}

int menuReception(){
    int opc = 0;
    printf("--- SubMenu Recepcion ---\n");
    
    printf("1. Iniciar sesion \n");
    printf("2. Registrar Socios\n");
    printf("3. Registrar actividades de Socios\n");
    printf("4. Listado de Socios\n");
    printf("5. Listado de fechas de pagos\n");
    printf("6. Cerrar Aplicación\n");

    printf("\nIngrese su opcion: ");
    scanf("%d", &opc);

    return opc; 
}

void menuAdminsitration(){
    int opc = 0;
    printf("--- SubMenu Administracion ---\n");
    
    printf("1. Iniciar sesion \n");
    printf("2. Registrar usuario de Recepción\n");
    printf("3. Registrar actividades del Gym\n");
    printf("4. Calcular pago del entrenador\n");
    printf("5. Entrenador con mayor carga horaria\n");
    printf("6. Cerrar Aplicacion\n");

    printf("\nIngrese su opcion: ");
    scanf("%d", &opc);

    return opc; 
}