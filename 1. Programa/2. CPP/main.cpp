#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

/*

#include "../0. Librerias/register.h"
#include "../0. Librerias/menus.h"
#include "../0. Librerias/login.h"
#include "../0. Librerias/moduloGym.h"
#include "../0. Librerias/moduloRecepcion.h"
#include "../0. Librerias/struct.h"

 C tira un error cuando se implementan distintas librerias.

*/

#include "libreria.h"

int main(void){
    /*
        Punteros & Archivos
    */

    FILE *usuarios;
    FILE *entrenadores;

    usuarios = fopen("../1. Archivos/Usuarios.dat","a+b");
    entrenadores = fopen("../1. Archivos/Entrenadores.dat","a+b");
    
    /* 
        SecciÃƒÆ’Ã‚Â³n de Varaibles & Constantes
    */
    int opc = 0;
    int banderaCerrado = 1;
    int opcSwitchGym = 0;
    int opcSwitchReception = 0;
    int opcSwitchAdministration = 0;
    int opcIngreso = 0;
    int typeOfUser = 0;
    int inicioSesion = 0;
    int opcSwitchJoinGym = 0;

    char nombreValidado[10];

    /*
        SeccciÃƒÆ’Ã‚Â³n de CÃƒÆ’Ã‚Â³digo
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
                                printf("\n\nEl tipo de usuario que eligio es ADMINISTRADOR \n");
                                printf("Crearemos una cuenta del tipo normal. \n");

                                generarCuentaAdministrador(entrenadores);
                                break;
                            case 2:
                                printf("\n\nEl tipo de usuario que eligio es ENTRENADOR \n");  
                                printf("Crearemos una cuenta del tipo entrenador. \n");

                                generarCuentaEntrenador(entrenadores);

                                // IMPORTANTE RECALCAR: SE GUARDAN EN ENTRENADORES.DAT
                                // SON USUARIOS CON TYPE.
                                break;    
                            default:
                                printf("Eligio un tipo de usuario incorrecto.");
                                break;                        
                        }
                    case 10:
                        casoDiez();
                    break;
                }
            break;
            case 1:
                system("cls");
                opcSwitchGym = menuGym();

                switch(opcSwitchGym){
                    case 1:
                            do{
                                inicioSesion = loguearAdminDb(entrenadores, nombreValidado);
                                system("cls");
                            }while(inicioSesion == 0);

                            opcSwitchJoinGym = menuJoinGym();

                            switch(opcSwitchJoinGym){
                                case 1:

                                break;
                                case 2:

                                break;
                                case 3:
                                    printf("\n\nOk. Cerraremos el Programa.");
                                break;
                                case 10:
                                    casoDiez();
                                break;
                                default:
                                    printf(" \n\nPusiste una opcion que no corresponde, cerrando \n\n");
                                break;
                            }
                    break;
                    case 2:
                        printf("\n\nOk. Cerraremos el Programa.");
                    break;
                    case 10:
                        casoDiez();
                    break; 
                    default: 
                        printf("\n\nIngreso una opcion incorrecta, por lo tanto cerraremos el programa.");
                        banderaCerrado = 0;
                    break;
                }
            break;
            case 2:
                system("cls");


                opcSwitchReception = submenuRecepcion();
                
                switch(opcSwitchReception){
                    case 1:
                        do{
                            inicioSesion = loguearAdminDb(entrenadores, nombreValidado);
                            system("cls");
                        }while(inicioSesion == 0);

                        
                    break;
                    case 2:
                        printf("\n\nOk. Cerraremos el Programa.");
                        banderaCerrado = 0;    
                    case 10:
                        casoDiez();
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
                        casoDiez();
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