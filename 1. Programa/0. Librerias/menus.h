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