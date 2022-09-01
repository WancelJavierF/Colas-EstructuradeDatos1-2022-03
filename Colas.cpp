#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct Queque// estructura para representar la cola
{
    int dato; // es la variable la cual se va a almacenar cada dato ingresado en la cola
    Queque *siguiente; // es el puntero que apunta al siguiente elemento de la cola
}*primero, *ultimo; // se declaran los punteros que apuntan al primer y ultimo elemento de la cola

//metodo para insertar un nodo 
void insertarNodo(int dato);

//metodo para surpimir cola
void suprimirCola(Queque *&primero, Queque *&ultimo, int &dato);

//metodo para eliminar un nodo
//void eliminarNodo();

//metodo para eliminar un nodo
void eliminarNodo(Queque *&primero, Queque *&ultimo, int &dato);

//insertar una prioridad en la cola
void insertarPrioridad(Queque *& cola, int prioridad, int dato);

//Validacion de entrada para verificar si es un digito o no
string validacionEntrada(string dato);


int main(int argc, char const *argv[])
{
    string valor, key; //valor para la entrada y la llave para la opcion
    bool estado = false; //estado para verificar si se realizo la operacion correctamente o no

    int opcion, dato; // opcion para el menu de entrada y el dato para la acciones que se van a realizar
    do{
        cout<<"\n1. Insertar nodo"<<endl;
        cout<<"2. Desplegar cola"<<endl;
        cout<<"3. Eliminar nodo"<<endl;
        cout<<"4. Salir"<<endl;
        while(!estado){
            cout<<"\nIngrese una opcion: ";
            getline(cin, valor); //se obtiene la entrada del usuario para la opcion
            key = validacionEntrada(valor); //se valida la entrada del usuario para la opcion
            stringstream(key) >> opcion; //se convierte la entrada del usuario a un entero
            if(opcion > 0 && opcion < 5) //se valida la entrada del usuario para la opcion
            {
                estado = true; // se cambia el estado a true para indicar que la entrada es correcta
            }else// si la entrada no es correcta se vuelve a pedir la opcion
            {
                cout<<"\nOpcion no valida"<<endl;
            }
        }
        estado = false;//se cambia el estado a false para volver a pedir la opcion
        switch(opcion){
            case 1:
                cout<<"\nIngrese un dato: ";
                getline(cin, valor); //se obtiene el dato a insertar en la cola
                key = validacionEntrada(valor); //se obtiene el dato validado para verificar si es un digito o no
                stringstream(key) >> dato; //se convierte el dato a entero para insertarlo en la cola
                insertarNodo(dato); //se inserta el dato en la cola
                break;
            case 2:
                //desplegarCola();
                //Si la cola no esta vacia se despliega la cola
                if (primero != NULL)
                {
                    while (primero != NULL) // se despliega la cola hasta que quede vacia
                    {
                        suprimirCola(primero, ultimo, dato); // se suprime el primer nodo de la cola y se imprime
                        cout << "\n" << dato << endl;
                             
                    }
                }
                else
                {
                    cout << "\nCola vacia" << endl;
                }
                break;
            case 3:
                // condicional para que solo se pueda eliminar un nodo si la cola no esta vacia
                if (primero != NULL)
                {
                    eliminarNodo(primero, ultimo, dato); // se elimina el primer nodo de la cola y se imprime
                }
                else
                {
                    cout << "\nCola vacia" << endl;
                }
                // eliminarNodo();
                break;
            case 4:
                cout<<"\nSaliendo..."<<endl;
                break;
            default:
                cout<<"\nOpcion no valida"<<endl;
                break;
        }
        
    }while(opcion!=4);
    return 0;
}

//metodo de insrtar nuevo nodo
void insertarNodo(int dato){
    Queque *nuevo = new Queque;//crear nuevo nodo
    nuevo->dato = dato;//asignar dato al nuevo nodo creado
    nuevo->siguiente = NULL;//asignar el siguiente del nuevo nodo creado como NULL para que no apunte a otro nodo
    if  (primero == NULL){ //si el primero es nulo
        primero = nuevo; //el primero es el nuevo
        ultimo = primero; //el ultimo es el primero
        nuevo->siguiente = NULL; //el siguiente es nulo para que no apunte a otro nodo
    }else{
        ultimo->siguiente = nuevo; //el siguiente del ultimo es el nuevo
        ultimo = nuevo; //el ultimo es el nuevo
        nuevo->siguiente = NULL; //el siguiente del nuevo es nulo
    }
    //mensaje para el usuario cuando el nodo sea ingresado
    cout << "El nodo fue ingresado correctamente" << endl;
}


//metodo para desplegar la cola
/*void desplegarCola(){
    Queque *aux = new Queque;

    aux = primero; //el auxiliar es el primero
    // condicional para saber si la cola esta vacia
    if (primero != NULL)// si la cola no esta vacia
    {
        while (aux != NULL){ //mientras el auxiliar no sea nulo
            cout << endl << " " << aux->dato; //despliega el dato
            aux = aux->siguiente; //el auxiliar es el siguiente
        }
    }else{
        cout << "La cola esta vacia" << endl; //mensaje para el usuario cuando la cola esta vacia
    }
}
*/

//metodo para eliminar un nodo
/*void eliminarNodo(){
    Queque *aux = new Queque;//crea un nuevo nodo auxiliar el cual nos sirvira como referencia del actual
    aux = primero; //el auxiliar es el primero
    Queque *aux2 = new Queque;// crea un nuevo nodo auxiliar el cual nos sirvira como referencia para decir que este es el anterior al actual
    aux2 = NULL; //el auxiliar 2 es nulo
    bool encontrado = false; //variable para saber si el nodo fue encontrado
    int nodoBuscado = 0; //variable para saber el nodo a buscar
    //variables para validar la entrada de datos que sea un digito
    string valor, key;
    bool estado = false;

    cout << "Ingrese el nodo a eliminar: ";
    getline(cin, valor); //obtiene la entrada del usuario para el nodo a buscar
    key = validacionEntrada(valor); //se valida la entrada del usuario para el nodo a buscar
    stringstream(key) >> nodoBuscado; //se convierte la entrada del usuario a un entero

    //condicional para saber si la cola esta vacia
    if (primero != NULL)// si la cola no esta vacia
    {
        while (aux != NULL && encontrado != true)//mientras el auxiliar no sea nulo y el nodo no fue encontrado
        {
            if (aux->dato == nodoBuscado)//si el dato del auxiliar es igual al nodo buscado
            {
                cout << "El nodo con el dato (" << nodoBuscado << ") encontrado" << endl; //mensaje para el usuario cuando el nodo fue encontrado
                if (aux == primero)//si el auxiliar es el primero
                {
                    primero = primero->siguiente; // el primero es el siguiente
                }else if (aux == ultimo)//si el auxiliar es el ultimo
                {
                    aux2->siguiente = NULL; // el siguiente del auxiliar 2 es nulo
                    ultimo = aux2; //el ultimo es el auxiliar 2
                }else{
                    aux2->siguiente = aux->siguiente; //el siguiente del auxiliar 2 es el siguiente del auxiliar
                }
                cout << "El nodo fue eliminado correctamente" << endl; //mensaje para el usuario cuando el nodo fue eliminado
                encontrado = true; //el nodo fue encontrado
            }
            aux2 = aux; //el auxiliar 2 es el auxiliar
            aux = aux->siguiente; //el auxiliar es el siguiente del auxiliar
        }
        if (encontrado == false)//si el nodo no fue encontrado
        {
            cout << "El nodo no fue encontrado" << endl; //mensaje para el usuario cuando el nodo no fue encontrado
        }
    }else{
        cout << "La cola esta vacia" << endl; //mensaje para el usuario cuando la cola esta vacia
    }

}
*/


//metodo para validar si es un digito o no
string validacionEntrada(string dato){
    bool check = false;//variable para saber si es un digito o no
    int i = 0;//variable para recorrer el string
    while((dato[i] != '\0') && (check != true))//mientras el dato no sea nulo y la variable check no sea verdadera
    {
        if(isdigit(dato[i]) == false)//si el dato no es un digito 
        {
            dato = "";//el dato es nulo
            check = true;//la variable check es verdadera
        }
        i++;//se incrementa el contador
    }
    return dato;//se retorna el dato
}

//metodo para insertar prioridad
void inserertarprioridad(Queque *& cola, int prioridad, int dato){

    int ipc = 0; //variable para saber la prioridad del nodo
    Queque *aux, *nuevo, *anterior = new Queque; // crea un nuevo nodo auxiliar el cual nos sirvira como referencia para decir que este es el anterior al actual
    bool ip = true; //variable para saber si la prioridad es correcta
    aux = cola; //el auxiliar es el primero
    anterior = aux; //el anterior es el auxiliar
    while ( aux != NULL && ipc < prioridad)//mientras el auxiliar no sea nulo y la prioridad sea correcta
    {
        anterior = aux; //el anterior es el auxiliar
        aux = aux->siguiente; //el auxiliar es el siguiente del auxiliar
        ipc++; //se incrementa la prioridad
    }
    if (prioridad == ipc)
    {
        nuevo->dato = dato; //el dato del nuevo nodo es el dato ingresado por el usuario
        nuevo->siguiente = aux; //el siguiente del nuevo nodo es el auxiliar
        if (prioridad != 0)//si la prioridad no es 0
        {
            anterior->siguiente = nuevo; //el siguiente del anterior es el nuevo nodo
        }
    }
    else ip = false; //la prioridad no es correcta
}

//metodo para suprimir la cola
void suprimirCola(Queque *&primero, Queque *&ultimo, int &dato){
    dato = primero->dato; //el dato es el dato del primero
    Queque *aux = new Queque; //crea un nuevo nodo auxiliar el cual nos sirvira como referencia del actual
    aux = primero; //el auxiliar es el primero
    
    if (primero == ultimo)//si el primero es el ultimo
    {
        primero = NULL; //el primero es nulo
        ultimo = NULL; //el ultimo es nulo 
    }else{
        primero = primero->siguiente; //el primero es el siguiente del auxiliar
    }
    delete aux; //el auxiliar es nulo y se elimina el nodo
}

//metodo para eliminar un nodo de la cola
void eliminarNodo(Queque *&primero, Queque *&ultimo, int &dato){
    dato = primero->dato; //el dato es el dato del primero
    Queque *aux = new Queque; //crea un nuevo nodo auxiliar el cual nos sirvira como referencia del actual
    aux = primero; //el auxiliar es el primero
    
    if (primero == ultimo)//si el primero es el ultimo
    {
        primero = NULL; //el primero es nulo
        ultimo = NULL; //el ultimo es nulo 
    }else{
        primero = primero->siguiente; //el primero es el siguiente del auxiliar
    }
    delete aux; //el auxiliar es nulo y se elimina el nodo
}

//metodo para desplegar cola
//void desplegarCola();