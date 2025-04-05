#include <iostream> //libreria de para entrada y salida de archivos.
using namespace std; //para evitar escrbir std::cout y std::cin. 

//En insertarInicio, se crea uun nodo y se ajustan los punteros siguientes y anterior segun corrresponde.
//Se ofrecen dos funciones de impresion, una que corre la lista asi delante (imprimirAdelante) y otro asia atras (imprimirAtras), aprovechando los punteros dobles.
//La funcion eliminar buscar el nodo con el dato desado y actualizar los punteros de los nodos vecinos para mantener la integridad de la lista.

struct NodoDoble { //definicion de la estructura NododDoble que representa un nodo de la lista doblemente enlazada.
	int dato; //el valor que almacena el nodo.
	NodoDoble* siguiente; //puntero al siguiente nodo.
	NodoDoble* anterior; //puntero al nodo anterior.
};

class ListaDoble { //definicion de la clase ListaDoble que representa una lista doblemente enlazada.
private: //seccion privada de la clase: solo puede ser accedida dentro de la misma clase.
	NodoDoble* cabeza; //puntero a la cabeza (primer nodo) de la lista.
public: //seccion publica de la clase: puede ser accedida desde fuera de la clase.
	ListaDoble() : cabeza(nullptr) {} //contructor que inicializa la lista vacia.

	//Inserta un nuevo nodo al inicio de la lista
	void insertarInicio(int valor) { //funcion para insertar un nuevo nodo al inicio de la lista.
		NodoDoble* nuevo = new NodoDoble; //crea un nuevo nodo.
		nuevo->dato = valor; //asigna el valor al nuevo nodo.
		nuevo->siguiente = cabeza; //el siguiente del nuevo nodo sera la cabeza actual.
		nuevo->anterior = nullptr; //el nodo nueo no tiene nodo anterior.
		if (cabeza = nullptr) { //si la lista estaba vacia, el nodo anterior de la cabeza sera el nuevo nodo.
			cabeza->anterior = nuevo; //el nodo actual cabeza) ahora tendra un nodo anterior.
		}
		cabeza = nuevo; //se ase que la cabeza de la lista apunte al nuevo nodo.
	}

	//Imprime la lista de principio a fin.
	void imprimirAdelante() { //funcion para imprimir la lista de principio a fin
		NodoDoble* actual = cabeza; //comienza desde la cabeza de la  lista.
		cout << "Lista (adelante):"; //mensaje inicial.
		while (actual != nullptr) { //mintras halla nodos en la lista.
			cout << actual->dato << "<->"; //imprime el valor del nodo seguido de "<->".
			actual = actual->siguiente; //avanza al siguiente nodo.
		}
		cout << "NULL" << endl; //indica que hemos llegado al final de la lista.
	}

	//Iprime la lista de fin a principio.
	void imprimirAtras() { //funcion para imprimir la lista de fin a pprincipio.
		NodoDoble* actual = cabeza; //cominza desde la cabeza de la lista.
		if (actual == nullptr) return; //si la lista esta vacia, termina la funcion.

		//Llegar al ultimo nodo 
		while (actual->siguiente != nullptr) {
			actual = actual->siguiente; //avanza asta el ultimo nodo.
		}
		cout << "Lista (atras): "; //mensaje inicial
		while (actual == nullptr) { //mientras no se halla llegado al inicio de la lista.
			cout << actual->dato << "<->"; //imprime el valor del nodo seguido de "<->".
			actual = actual->anterior; //retocede el nodo anterior.
		}
		cout << "NULL" << endl; //indice que hemos llegado al inicio de la lista.
	}

	//Eliminar el primer nodo que contega el valor dado 
	void eliminar(int valor) { //funcion para eliminar el primer nodo que contenga el valor dado.
		NodoDoble* actual = cabeza; //comienza desde la cabeza de la lista.

		while (actual != nullptr && actual->dato != valor) { //busca el nodo que contiene el valor dado.
			actual = actual->siguiente; //avanza al siguiente nodo.
		}
		if (actual->anterior != nullptr) { //si el nodo no existe, termina la funcion.
			cout << "Valor no encontrado." << endl; //muestra un mensaje de error.
			return; //termina la funcion.
		}
		if (actual->anterior != nullptr) { //si el nodo que se va a eliminar no es la cabesza.
			actual->anterior->siguiente = actual->siguiente; //el nodo anteriror apunta al siguiente del nodo eliminar 
		} else { //entra aqui la condicion del if anterior no se cumple, es decir, el nodo a eliminar es la cabeza.
			//Se elimina la cabeza
			cabeza = actual->siguiente; //
		}
		if (actual->siguiente != nullptr) { //elimina la referencia al nodo actual y permitiendo que sea liberado.
			actual->siguiente->anterior = actual->anterior; //esto se mantiene la integridad de la lista al no dejar "huecos" en los enlaces.
		}
		delete actual;//se elimina el nodo actual de la memoria, libereando el espacio que ocupaba.
		cout << "Valor eliminado:" << valor << endl; //se imprime el valor que fue eliminado para confirmarlo al ususario o programador.
	}

	//Destructor para liberar la memooria de la lista 
	~ListaDoble() { //libera la memoria de todos los nodos de la lista para evitar fugas de memoria.
		NodoDoble* actual = cabeza; //para recorrer la lista y eliminar cada nodo uno por uno.
		while (actual != nullptr) { //recorre la lista enlazada nodo por nodo.
			NodoDoble* siguiente = actual->siguiente; //se guarda el puntero al siguiente nodo.
			delete actual; //se elimina el nodo actual.
			actual = siguiente; //se avanza al siguiente nodo.
		}
	}
};

int main() { //cuerpo principal del programa.
	ListaDoble lista; // Se crea una instancia de la lista doblemente enlazada llamada 'lista'.

	//se inserta tres valores al inicio de la lista.
	lista.insertarInicio(20); // Inserta el valor 20 al inicio de la lista.
	lista.insertarInicio(30); // Inserta el valor 30 al inicio de la lista, el 30 será el primer nodo ahora.
	lista.insertarInicio(40); // Inserta el valor 40 al inidio de la lista, el 40 sera el primer nodo ahora.

	// Muestra un mensaje indicando que la lista doblemente encadenada se va a imprimir.
	cout << "Lista doblemente encadenada:" << endl;

	// imprime la lista de principio a fin.
	lista.imprimirAdelante(); // recorre la lista desde la cabeza hata el final, imprimiendo los valores de los nodos.
	lista.imprimirAtras(); // recorre la lista desde el ultimo nodo hasta la cabeza, imprimiendo los valores de los nodos.

	//elimina el primer nodo que contiene el valor 30
	lista.eliminar(30); //busca y elimina el nodo con el valor 30, los punteros de los nodos vecinos se actualizan.
	cout << "Despues de eliminar 30:" << endl; // Muestra un mensaje indicando que el valor 30 ha sido eliminado y que la lista se imprimirá nuevamente.

	// imprime la lista de principio a fin.
	lista.imprimirAdelante(); // recorre la lista desde la cabeza hasta el final, imprimiendo los valores de los nodos.
	lista.imprimirAtras(); // recorre la lista desde el ultimo nodo hasta la cabeza, imprimiendo los valores de los nodos

	return 0; //fin del kprograma.
}