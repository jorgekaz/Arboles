//    printf(" ================\n");
//    printf("  ARBOL DIBUJADO \n");
//    printf(" ================\n");
//    nodoArbol* arbol = inicArbol();
//    cargarArbol(&arbol);
//    dibujarArbol(arbol);
//
//    printf(" ===============\n");
//    printf("  ARBOL CARGADO \n");
//    printf(" ===============\n");
//    printf(" PREORDER: ");
//    preorder(arbol);
//    printf("\n");
//    printf(" INORDER: ");
//    inorder(arbol);
//    printf("\n");
//    printf(" POSTORDER: ");
//    postorder(arbol);
//    printf("\n");
//    printf("\n");
//    int hojas = 8;
//    hojas = hojas/4;
//    printf(" LA CANTIDAD DE HOJAS ES DE: %i ", hojas);
//
//    int buscador;
//    printf("\n QUE NODO DESEA BUSCAR: ");
//    fflush(stdin);
//    scanf("%i",&buscador);
//    if(buscarInternet(arbol,buscador)!=NULL) {
//        printf(" EL NODO ESTA EN EL ARBOL\n");
//    } else {
//        printf(" EL NODO NO ESTA EN EL ARBOL\n");
//    }