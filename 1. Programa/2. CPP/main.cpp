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
    FILE *archSocios;

    usuarios = fopen("Usuarios.dat","a+b");
    entrenadores = fopen("Entrenadores.dat","a+b");
    archSocios = fopen("Socios.dat","a+b");
    
    /* 
        Seccion de vars y const
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
    int opcionReception = 0;
    int opcArchSoc = 0;
    int nroSocio;

    char nombreValidado[10];

    /*
        Secccion de codigo
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
                                inicioSesion = loguearEntrenadorEnDB(entrenadores, nombreValidado); // loguearEntrenadorEnDb
                                if(inicioSesion == 0){
                                	printf("\n\nHubo un error, vuelve a ingresar los datos...");
                                	printf("\n");
                                	system("pause");
								}
                            }while(inicioSesion == 0);

                            opcSwitchJoinGym = menuJoinGym();

                            switch(opcSwitchJoinGym){
                                case 1:
                                    listadoSociosActividad(archSocios);
                                break;
                                case 2:
                                    registrarRutina(archSocios);
                                break;
                                case 3:
                                    printf("\n\nOk. Cerraremos el Programa.");
                                    banderaCerrado = 0;
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
            case 2:
                system("cls");

                opcSwitchReception = submenuRecepcion();
                
                switch(opcSwitchReception){
                    case 1:
                        do{
                            inicioSesion = loguearAdminsitradorDb(entrenadores, nombreValidado);
                            // aqui tengo que logear un administrador
                            system("cls");
                        }while(inicioSesion == 0);
                
                        opcionReception = menuRecepcion();

                        switch(opcionReception){
                            case 1:
                                registrarSocio(archSocios, nroSocio, nombreValidado);

                                system("cls");
                                printf("\n1. Registrar una actividad en el socio");
                                printf("\n2. Salir \n");
                                printf("\n\nIngrese una opcion: ");

                                scanf("%d", &opcArchSoc);

                                switch(opcArchSoc){
                                    case 1:
                                        registrarActividadSocio(archSocios, nroSocio);

                                        printf("\nSe registro la actividad del socio... \n");
                                    break;
                                    case 2:
                                        printf("\n\nCerrando programa. \n\n");
                                        //banderaCerrado = 0;
                                    break;
                                    default:
                                        printf("\n\nIngreso una opcion incorrecta, por lo tanto cerraremos el programa.");
                                        //banderaCerrado = 0;
                                }
                            break;
                            case 2:
                                listarSocios(archSocios);
                            break;
                            case 3:
                                listarFechaPagos(archSocios);
                            break;
                            case 4:
                                printf("\n\nCerrando programa. \n\n");
                                //banderaCerrado = 0;
                            break;
                            default:
                                printf("\n\nIngreso una opcion incorrecta, por lo tanto cerraremos el programa.");
                                //banderaCerrado = 0;
                            break;
                        }

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
                    case 1:
                        // calcularPagoEntrenador_Administration();
                    break;
                    case 2:
                        // entrenadorMaxCargaHs_Administration();
                    break;
                    case 3:
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

    fclose(archSocios);
    fclose(usuarios);
    fclose(entrenadores);
    printf("\n");
    system("cls");
    

    

} // fin del main