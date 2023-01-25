#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include "../0. Librerias/menus.h"
#include "../0. Librerias/register.h"
#include "../0. Librerias/login.h"

int main(void){
    /*
        Punteros & Archivos
    */

    FILE *usuarios;
    FILE *entrenadores;

    usuarios = fopen("../1. Archivos/Usuarios.dat","a+b");
    entrenadores = fopen("../1. Archivos/Entrenadores.dat","a+b");
    
    /* 
        Sección de Varaibles & Constantes
    */
    int opc = 0;
    int banderaCerrado = 1;
    int opcSwitchGym = 0;
    int opcSwitchReception = 0;
    int opcSwitchAdministration = 0;
    int opcIngreso = 0;
    int typeOfUser = 0;

    char nombreValidado[10];
    char contraseniaValidada[32];

    /*
        Seccción de Código
    */
    do{
        system("cls");

        opc = menuPrincipal();

        switch(opc){
            case 0:
                opcIngreso = ingresar();
                
                switch(opcIngreso){
                    case 1:
            
                        typeOfUser = typeUser();
                        system("cls");
                        Sleep(100);

                        switch(typeOfUser){
                            case 1:
                                printf("\n\nEl tipo de usuario que eligio es NORMAL \n");
                                printf("Crearemos una cuenta del tipo normal. \n");

                                generarCuentaNormal(usuarios);
                                break;
                            case 2:
                                printf("\n\nEl tipo de usuario que eligio es ENTRENADOR \n");  
                                printf("Crearemos una cuenta del tipo entrenador. \n");

            
                                generarCuentaEntrenador(entrenadores);
                                break;    
                            default:
                                printf("Eligio un tipo de usuario incorrecto.");
                                break;                        
                        }
                    case 2:

                    case 3:
                    // salir al menú principal
                    break;
                }
            break;
            case 1:
                system("cls");
                opcSwitchGym = menuGym();

                switch(opcSwitchGym){
                    break;
                    case 1:
                        // Listado de Socios - Desarrollo de actividad
                        /*
                            Aca depende mucho como quieran programarlo, si es que realmente
                            lo quieren hacer un vector o qsy, por ahí la pueden mandar...
                            + facil 1 swtich con 1 listado de socios y 2 actividad y listo
                        */
                    break;
                    case 2:
                        // registrarRutina_GYM();
                    break;
                    case 3:
                        printf("\n\nOk. Cerraremos el Programa.");
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
                    case 10:
                        printf("\n\nVolviendo atras...");
                        printf("\n\n");
                        Sleep(1000);

                        system("cls");
                    break; 
                    default: 
                        printf("\n\nIngreso una opcion incorrecta, por lo tanto cerraremos el programa.");
                        banderaCerrado = 0;
                    break;
                }
            break;
            case 2:
                system("cls");
                opcSwitchReception = menuRecepcion();
                
                switch(opcSwitchReception){
                    // de mi parte prefiero tirar funciones void para hacer estas cosas 
                    // dentro de las funciones void hacer todo xd
                    // sugiero los nombres de las func y ademas bueno q deben hacer queda implicito
                    break;
                    case 1:
                        // registrarSocios_Reception()
                    break;
                    case 2:
                        // registrarActividadesSociso_Reception();
                    break;
                    case 3:
                        // listadoDeSocios_Reception();
                    break;
                    case 4:
                        // listadoFechasPagos_Reception();
                    break;
                    case 5:
                        printf("\n\nOk. Cerraremos el Programa.");
                        banderaCerrado = 0;    
                    case 10:
                        printf("\n\nVolviendo atras...");
                        printf("\n\n");
                        Sleep(1000);

                        system("cls");
                    break; 
                    break;
                    default:
                        printf("\n\nIngreso una opcion incorrecta, por lo tanto cerraremos el programa.");
                        banderaCerrado = 0;
                    break;
                }
            break;
            case 3:
                system("cls");
                opcSwitchAdministration = menuAdmin();

                switch(opcSwitchAdministration){
                    break;
                    case 1:
                        // registrarUsuario_Administration();
                    break;
                    case 2:
                        // registrarActividades_Administration();
                    break;
                    case 3:
                        // calcularPagoEntrenador_Administration();
                    break;
                    case 4:
                        // entrenadorMaxCargaHs_Administration();
                    break;
                    case 5:
                        printf("\n\nOk. Cerraremos el Programa.");
                        banderaCerrado = 0;    
                    break;
                    case 10:
                        printf("\n\nVolviendo atras...");
                        printf("\n\n");
                        Sleep(1000);

                        system("cls");
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