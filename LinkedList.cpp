#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct LinkedList{
    int dato;
    LinkedList *siguiente;
}*primero, *ultimo;

//metodo para insertar un nodo
void insertarnodo(int dato);
//metodo para desplegar la lista
void desplegarlista();
//metodo para eliminar un nodo
void eliminarnodo();
//metodo para buscar un nodo
void buscarnodo();

