#include "AVL.h"
#include "NodoAVL.h"

AVL::AVL(){ // Crea un árbol vacío
//constructor
    raiz = NULL;
}

AVL::AVL(NodoAVL *r){
    raiz = r; // La raiz es el primer nodo que se pasa como parámetro
}

AVL::AVL(string nombre, NodoAVL *hIz, NodoAVL *hDer){  //constructor que crea árbolBin con dato y dos subárboles
    raiz = new NodoAVL(nombre, hIz, hDer); //llamamos al constructor del Nodo y raiz es un puntero al Nodo creado
}

AVL::~AVL(){
    //dtor
}

//ver en orden desde la raíz
void AVL::verInOrden(){
    verInOrden(raiz);
}

//ver en orden dependiendo del nodo
void AVL::verInOrden(NodoAVL *arb){  
    if(arb){   //Recorre y muestra el árbol de forma recursiva llamando la hijo izquierdo, luego el nodo (raíz) y luego el hijo derecho
        verInOrden(arb->hi);
        cout << arb->nombre << endl;
        verInOrden(arb->hd);
    }
}

void AVL::insertar(string nombre){
    insertar(nombre, raiz);
}   

void AVL::insertar(string nombre, NodoAVL *nodo){
    if ((nodo->nombre >nombre) ||(nodo->nombre == nombre)){

        cout << "es mayor " << nodo->nombre << " que " << nombre << endl;
        if(nodo->hi == NULL){
            NodoAVL *nuevo = new NodoAVL(nombre);
            nodo->hi = nuevo;
        }else{      //Si ya tiene un nodo izquierdo, se llama recursivamente para ir bajando
            insertar(nombre, nodo->hi); 
        }
}
    else //nombre > nodo->nombre
    {   
        cout << "es menor " << nodo->nombre << " que "<<nombre << endl;
        if(nodo->hd == NULL){
            NodoAVL *nuevo = new NodoAVL(nombre);
            nodo->hd = nuevo;
        }else{     //Si ya tiene un nodo derecho, se llama recursivamente para ir bajando
            insertar(nombre, nodo->hd); 
        }
    }
}

int main(){
    cout<<"Creo el árbol"<<endl;
    AVL abb("carlos");
    cout<<"árbol: "<<endl;
    abb.verInOrden();

    cout<<"introdizco Jose"<<endl;
    AVL abb("jose");
    AVL abb("javier");
    cout<<"árbol: "<<endl;
    abb.verInOrden();
    return 0;
}