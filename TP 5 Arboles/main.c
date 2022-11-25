#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dato;
    struct nodoArbol* izq;
    struct nodoArbol* der;
} nodoArbol;

nodoArbol* inicArbol();
nodoArbol* crearNodoArbol(int dato);
void cargarArbol(nodoArbol** arbol);
void preorder(nodoArbol* arbol);
void inorder(nodoArbol* arbol);
void postorder(nodoArbol* arbol);
//int dibujarRamas(nodoArbol* arbol, int esIzq, int inicia, int nivel, char s[20][255]);
//int dibujarArbol(nodoArbol* arbol);
int mostrarArbol(nodoArbol* arbolFuncion);
void mostrarUnArbol(nodoArbol* arbolFuncion, int ni);
nodoArbol* buscarNodo(nodoArbol* arbol, int dato);
nodoArbol* noditoBuscadito(nodoArbol* arbol, int dato);
nodoArbol* buscarInternet(nodoArbol* arbol, int dato);
nodoArbol* insertar(nodoArbol* arbol, int dato);

int main() {
    printf(" ================\n");
    printf("  ARBOL DIBUJADO \n");
    printf(" ================\n");
    nodoArbol* arbol = inicArbol();
    cargarArbol(&arbol);
    mostrarUnArbol(arbol,10);
//    dibujarArbol(arbol);

    printf(" ===============\n");
    printf("  ARBOL CARGADO \n");
    printf(" ===============\n");
    printf(" PREORDER: ");
    preorder(arbol);
    printf("\n");
    printf(" INORDER: ");
    inorder(arbol);
    printf("\n");
    printf(" POSTORDER: ");
    postorder(arbol);
    printf("\n");
    printf("\n");
////    int hojas = 8;
////    hojas = hojas/4;
////    printf(" LA CANTIDAD DE HOJAS ES DE: %i ", hojas);
////
////    int buscador;
////    printf("\n QUE NODO DESEA BUSCAR: ");
////    fflush(stdin);
////    scanf("%i",&buscador);
////    if(buscarInternet(arbol,buscador)!=NULL) {
////        printf(" EL NODO ESTA EN EL ARBOL\n");
////    } else {
////        printf(" EL NODO NO ESTA EN EL ARBOL\n");
////    }

    printf(" ================\n");
    printf("  ARBOL ORDENADO \n");
    printf(" ================\n");
    int a[8]={3,7,2,10,1,12,15,6};
    nodoArbol* arbolOrdenado = inicArbol();
    for(int i=0; i<8; i++){
        arbolOrdenado=insertar(arbolOrdenado,a[i]);
    }
    mostrarUnArbol(arbolOrdenado,10);
    //dibujarArbol(arbolOrdenado);
//    preorder(arbolOrdenado);
//    int buscador;
//    printf("\n QUE NODO DESEA BUSCAR: ");
//    fflush(stdin);
//    scanf("%i",&buscador);
//    if(buscarInternet(arbolOrdenado,buscador)!=NULL) {
//        printf(" EL NODO ESTA EN EL ARBOL\n");
//    } else {
//        printf(" EL NODO NO ESTA EN EL ARBOL\n");
//    }
    return 0;
}

nodoArbol* inicArbol() {
    return NULL;
}

nodoArbol* crearNodoArbol(int dato) {
    nodoArbol* hijo = (nodoArbol*)malloc(sizeof(nodoArbol));
    hijo->dato = dato;
    hijo->der = NULL;
    hijo->izq = NULL;
    return hijo;
}

void cargarArbol(nodoArbol** arbol) {
    *arbol = crearNodoArbol(3);
    nodoArbol* hijo = *arbol;
    hijo->izq = crearNodoArbol(7);
    hijo = hijo->izq;
    hijo->izq = crearNodoArbol(2);
    hijo = *arbol;
    hijo->der = crearNodoArbol(10);
    hijo = hijo->der;
    hijo->izq = crearNodoArbol(1);
    hijo->der = crearNodoArbol(12);
    hijo = hijo->der;
    hijo->izq = crearNodoArbol(15);
    hijo->der = crearNodoArbol(6);
}

void preorder(nodoArbol* arbol) {
    if(arbol!=NULL) {
        printf(" %d ", arbol->dato);
        preorder(arbol->izq);
        preorder(arbol->der);
    }
}

void inorder(nodoArbol* arbol) {
    if(arbol!=NULL) {
        inorder(arbol->izq);
        printf(" %d ",arbol->dato);
        inorder(arbol->der);
    }
}

void postorder(nodoArbol* arbol) {
    if(arbol!=NULL) {
        postorder(arbol->izq);
        postorder(arbol->der);
        printf(" %d ", arbol->dato);
    }
}

int mostrarArbol(nodoArbol* arbolFuncion){
    if(arbolFuncion != NULL){
        int izq = mostrarArbol(arbolFuncion->izq)+1;
        int der = mostrarArbol(arbolFuncion->der)+1;
        if(izq>der){
            return izq;
        }else{
            return der;
        }
    }
}

void mostrarUnArbol(nodoArbol* arbolFuncion, int ni){
    if(arbolFuncion != NULL){
        if(ni == 0){
            printf("%d\n", arbolFuncion->dato);
        }
        mostrarUnArbol(arbolFuncion->izq, ni-1);
        mostrarUnArbol(arbolFuncion->der, ni-1);
    }
}




////int dibujarRamas(nodoArbol * arbol, int esIzq, int inicia, int nivel, char s[20][255])
////{
////    char b[10];
////    int ancho = 4; //es el ancho del nodo que dibujo
////    int i;
////
////    if (!arbol) return 0;
////
////    sprintf(b, "(%d)", arbol->dato); // agrego valor de nodo a la matriz
////
////    int izq  = dibujarRamas(arbol->izq,  1, inicia, nivel + 1, s);
////    int der = dibujarRamas(arbol->der, 0, inicia + izq + ancho, nivel + 1, s);
////
////    //dibujo nodo
////    for (i = 0; i < ancho; i++)
////        s[2 * nivel][inicia + izq + i] = b[i];
////
////    //dibujo lineas .----+----.
////    if (nivel && esIzq)
////    {
////
////        for (i = 0; i < ancho + der; i++)
////            s[2 * nivel - 1][inicia + izq + ancho/2 + i] = '-';
////
////        s[2 * nivel - 1][inicia + izq + ancho/2] = '.';
////        s[2 * nivel - 1][inicia + izq + ancho + der + ancho/2] = '+';
////
////    }
////    else if (nivel && !esIzq)
////    {
////
////        for (i = 0; i < izq + ancho; i++)
////            s[2 * nivel - 1][inicia - ancho/2 + i] = '-';
////
////        s[2 * nivel - 1][inicia + izq + ancho/2] = '.';
////        s[2 * nivel - 1][inicia - ancho/2 - 1] = '+';
////    }
////
////    return izq + ancho + der;
////}
////
////int dibujarArbol(nodoArbol * arbol)
////{
////    char s[20][255];
////    int i;
////    for (i = 0; i < 20; i++)
////        sprintf(s[i], "%80s", " ");
////
////    dibujarRamas(arbol, 0, 0, 0, s);
////
////    //Imprimo matris
////    for (i = 0; i < 10; i++)
////        printf("%s\n", s[i]);
////}

nodoArbol* buscarNodo(nodoArbol* arbol, int dato) {
    nodoArbol* buscado = inicArbol();
    if(arbol != NULL) {
        if(dato == arbol->dato) {
            buscado = arbol;
        } else {
            if(dato > arbol->dato) {
                buscado = buscarNodo(arbol->der, dato);
            } else {
                buscado = buscarNodo(arbol->izq, dato);
                printf("\n\n ENTRO\n\n");
            }
        }
    }
    printf("\n\n BUSCADO: %i\n\n", buscado->dato);
    return buscado;
}

nodoArbol* noditoBuscadito(nodoArbol* arbol, int dato) {
    nodoArbol* buscado = inicArbol();
    if(arbol!=NULL) {
        if(dato==arbol->dato) {
            buscado=arbol;
        } else if(dato > arbol->dato) {
            buscado = noditoBuscadito(arbol->der, dato);
            buscado = noditoBuscadito(arbol->izq, dato);
        } else {
            buscado = noditoBuscadito(arbol->der, dato);
            buscado = noditoBuscadito(arbol->izq, dato);
        }
    }
    return buscado;
}

nodoArbol* buscarInternet(nodoArbol* arbol, int dato){
    nodoArbol* buscado = inicArbol();
    if(arbol == NULL){
        return NULL;
    }else{
        if(dato == arbol->dato){
            buscado = arbol;
        }else{
            if(dato < arbol->dato){
                buscado = buscarInternet(arbol->izq, dato);
            }else{
                buscado =  buscarInternet(arbol->der, dato);
            }
        }
    }
    return buscado;
}

nodoArbol* insertar(nodoArbol* arbol, int dato){
    if(arbol!=NULL){
        if(dato > arbol->dato){
            arbol->der = insertar(arbol->der, dato);
        }else{
            arbol->izq = insertar(arbol->izq, dato);
        }
    }else{
        arbol = crearNodoArbol(dato);
    }

    return arbol;
}

