#include <iostream> //libreria para entrada y salida de archivos 
using namespace std; //para evitar poner std:: cout y std::cin.	

//La funcion insertarInicio crea un nuevo modo y lo coloca al comienzo de la lista. 
//La funcion eliminar recorre la lista hasta encotrar el nodo con el dato espesificado y lo elimina, actualizando los punteros.
//El destructor libera la memoria asignada a cada nodo para evitar fugas de memoria.

struct Nodo { //definicion de una estructura llamada "Nodo"
	int dato; //variable para almacenar el valor del Nodo 
	Nodo* siguiente; //puntero al siguiente nodo en la lista
};

class ListaSimple { //definicion de una estructura llamada ListaSimple, que maneja una lista enlazada simple.
private: //seccion privada de la clase: solo puede ser accedido dentro de la misma clase.
	Nodo* cabeza; //puntero que apunta al primer nodo de la lista.
public: //seccion publica de la clase: puede ser accedido desde fuera de la clase.
	ListaSimple() : cabeza(nullptr) {} //constructor que inicializa la lista vacia

	//inserta un nuevo nodo al inicio de la lista
	void insertarInicio(int valor) {
		Nodo* nuevo = new Nodo; //se crea un nuevo nodo en memoria dinamica.
		nuevo->dato = valor; //se asigna el valor recibido al nodo.
		nuevo->siguiente = cabeza; //el nuevo nodo  apunta al antiguo primer nodo .
		cabeza = nuevo; //se actualiza la cabeza de la liesta al nuevo nodo.
	}

	//imprime todos los valores de la lista enlazada.
	void imprimir() {
		Nodo* actual = cabeza; //se usa un puntero axiliar para recorrer la lista.
		while (actual != nullptr) { //se recorre la lista hata que el puntero sea nulo.
			cout << actual->dato << "->"; //se imprime el valor del nodo.
			actual = actual->siguiente; //se indica al final de la lista. 
		}
		cout << "NULL" << endl; //se indica el final de la lista.
	}

	//Elimina el primer nodo que contenga el valor dado 
	void eliminar(int valor) {
		Nodo* actual = cabeza; //se inicia la busqueda desde la cabeza de la lista.
		Nodo* anterior = nullptr; //puntero para rastrear el nodo anterior al actual.
		while (actual != nullptr && actual->dato != valor) { //se busca el nodo que contiene el valor espesificado.
			anterior = actual; //se guarda el nodo actual en el puntero anterior.
			actual = actual->siguiente; //se mueve "actual" al siguiente nodo en la lista.
		}
		if (actual == nullptr) { //Si no se encontró el valor en la lista.
			cout << "Valor no encontrado." << endl;//muestra un mensaje si el valor buscado no esta en la lista.
			return;//sale de la funcion inmediatamente sin continuar con mas instricciones.
		}
		if (anterior == nullptr) { //Si el nodo a eliminar es la cabeza de la lista.
			cabeza = actual->siguiente; //se actualiza la cabeza al siguiente nodo.
		}else { //entra aqui si la condicion del "if" anterior no se cumple.
			anterior->siguiente = actual->siguiente; //se emite el nodo actual.
		}
		delete actual; //se libera la memoria del nodo eliminado.
		cout << "Valor eliminado: " << valor << endl; //muestra en pantalla el valor que ha sido eliminado de la lista.
	}

	~ListaSimple() { //Destructor para liberar la memoria de la lista
		Nodo* actual = cabeza; //se empieza desde la cabeza. 
		while (actual != nullptr) { //se recorre toda la lista. 
			Nodo* siguiente = actual->siguiente; //se almacena el siguiente nodo.
			delete actual; //se libera la memoria del nodo actual.
			actual = siguiente; //se avanza al siguiente nodo.

		}
	}
};

int main() { //funion principal donde se prueba la funcionalidad de la lista enlazada.
	ListaSimple lista; //se crea una instancia de la lista.
	lista.insertarInicio(5); //insertar el valor 5 al inicio de la lista.
	lista.insertarInicio(10); //insertar el valor 10 al inicio de la lista.
	lista.insertarInicio(15);  //insertar el valor 15 al inicio de la lista.
	cout << "Lista despues de inserciones: " << endl; //muestra un mensaje indicando que se va a imprimir el estado de la lista.
	lista.imprimir(); //imprime todo los elementos de la lista en orden.

	lista.eliminar(10); //elimina el nodo que contiene el valor 10 de la lista.
	cout << "Lista despues de eliminar 10: " << endl; //muestra un mensaje indicando que se va a imprimir el estado de la lista despues de eliminar el valor 10.
	lista.imprimir(); //se imprime la lista despues de eliminar el nodo.

	return 0; //fin del programa. 
}