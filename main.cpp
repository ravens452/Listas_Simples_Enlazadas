#include <iostream>
#include "Node.h"
#include "LinkedList.h"
using namespace std;


int main(){
cout<<"hola: "<<endl;
    LinkedList lista1;
    int numero;
    cout<<"Ingrese los numeros a guardar de forma ordenada (finalizar con 0) "<<endl;cin>>numero;
    while (numero!=0){
        lista1.insertarOrdenado(numero);
        cin>>numero;
    }
    lista1.print();
//------------------------------------------------------------------------------------
//    lista1.insert(4);
//    lista1.insert(3);
//    lista1.insert(5);
//    lista1.insert(6);
//    lista1.print();
//    lista1.remove(4);
//    lista1.print();
//------------------------------------------------------------------------------------------------

}

