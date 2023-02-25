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

    //FILE *usuarios;
    FILE *entrenadores;
    FILE *archSocios;
    FILE *archActividades;

    //usuarios = fopen("Usuarios.dat","a+b");
    entrenadores = fopen("Entrenadores.dat","a+b");
    archSocios = fopen("Socios.dat","a+b");
    archActividades = fopen("Actividades.dat","a+b");
    
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
    int nroSocio = 0;
    int tipoListar = 0;
    int legajoEntrenadorActive = 0;
    int legajoEntrenador = 0;
    int size = 0;
    int nuumeroSocio = 0;

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
                        break;
                    case 2:
                    	printf("\nIngrese el tipo que desea listar: ");
                    	printf("\n1. Administradores \t\t 2. Entrenadores ");
                    	printf("\nSu opcion: ");
                    	
                    	scanf("%d", &tipoListar);
                    	
                    	listarEntrenadores(entrenadores, tipoListar);
                    	
                    	system("pause");
                        break;
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
							
							system("cls");
                            opcSwitchJoinGym = menuJoinGym();

                            switch(opcSwitchJoinGym){
                                case 1:
                                    listadoSociosActividad(archSocios);
                                    
                                    printf("\n\n");
                                    system("pause");
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
                            break;
                            case 2:
                            	listarSocios(archSocios);
                            	printf("\n\nIngrese el numero de socio que desee registrar la actividad: ");
                            	scanf("%d", &nuumeroSocio);
                            	registrarActividadSocio(archSocios, archActividades, nuumeroSocio);
                            	
                            	printf("\n\n");
                            	system("cls");
                            	printf("\n\n");
                            	break;
                            case 3:
                                listarSocios(archSocios);
                            break;
                            case 4:
                                listarFechaPagos(archSocios);
                            break;
                            case 5:
                                printf("\n\nCerrando programa. \n\n");
                                banderaCerrado = 0;
                            break;
                            case 10:
                            	casoDiez();
                            default:
                                printf("\n\nIngreso una opcion incorrecta, por lo tanto cerraremos el programa.");
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
            // aca estamos actualmente...
            case 3:
                system("cls");

                do
                {
                    inicioSesion = loguearAdminsitradorDb(entrenadores, nombreValidado);
                    // aqui tengo que logear un administrador
                    system("cls");
                } while (inicioSesion == 0);
                
                opcSwitchAdministration = menuAdmin();

                switch(opcSwitchAdministration){
                    case 1:
                        system("cls");
                        
	                    registrarActividad(archActividades, entrenadores, archSocios, nombreValidado);

						printf("\n\n");
						system("pause");
                    break;
                    case 2:
                        system("cls");
                        printf("\n");
                        do{
                        	system("cls");
                            printf("Ingrese el legajo del entrenador: ");
                            scanf("%d", &legajoEntrenador);

                            legajoEntrenadorActive = encontrarEntrenador(entrenadores, legajoEntrenador);
                        }while(legajoEntrenadorActive == 0);
	
						printf("\n\n");
                        calcularPagoEntrenador(archActividades, legajoEntrenador);

                        printf("\n\n");
						
						system("pause");
                        system("cls");
                    break;
                    case 3:
                        calcularMayorCargaHoraria(entrenadores, archActividades);

                        printf("\n\n");

                        system("cls");
                    break;
                    case 4:
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
    //fclose(usuarios);
    fclose(entrenadores);
    fclose(archActividades);
    printf("\n");
    system("cls");
    

    

} // fin del main