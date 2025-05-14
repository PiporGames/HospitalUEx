/*
 *
 * Este archivo pertenece al proyecto 'proyecto2',
 * creado por José Manuel De Torres Domínguez.
 *
 *
 */
//============================================================================
// Name        : ListaDPI.h
// Author      : Profesores de EDI
// Version     : 1.0
// Description : Template Lista Doblemente enlazada con Punto de Interés
//============================================================================

#ifndef LISTADPI_H_
#define LISTADPI_H_

#include <iostream>
using namespace std;

template <class TipoDato> class ListaDPI {

private:
	/**
	* Clase genérica Nodo (sólo accesible para el template ListaDPI).
	* Modela los nodos que se almacenan en la ListaDPI. Cada Nodo
	* contiene un dato de tipo TipoDato y sendos punteros a sus
	* nodos anterior y siguiente en la lista.
	*/
	class Nodo {
	public:
		TipoDato  dato;
		Nodo     *sig;
		Nodo	 *ant;
		Nodo (TipoDato dato) {
			this->dato = dato;
			this->sig  = nullptr;
			this->ant  = nullptr;
		}
	};

	typedef Nodo *PtrNodo;

	PtrNodo primero;		// Puntero al primer nodo de la lista
	PtrNodo ultimo;			// Puntero al último nodo de la lista
	PtrNodo pi;				// Puntero al punto de interés (PI)

public:
	// PRE: ---
	// DES: Constructor por defecto. Crea una ListaDPI vacía.
	// COM: O(1)
	ListaDPI ( );

	// PRE: ---
	// DES: Devuelve TRUE si la lista está vacía; FALSE en caso contrario.
	// COM: O(1)
	bool estaVacia ( ) const;

	// PRE: this->estaVacia () = false; this->alFinal () = false
	// DES: Devuelve el dato del nodo apuntado por el PI de la lista.
	// COM: O(1)
	TipoDato consultar ( ) const;

	// PRE: this->estaVacia () = false; this->alFinal () = false
	// DES: Devuelve en d el dato del nodo apuntado por el PI de la lista.
	// COM: O(1)
	void consultar ( TipoDato &d ) const;

	// PRE: d correctamente inicializado.
	// DES: Crea un nuevo nodo con dato d y lo inserta en la posición anterior
	//		al nodo apuntado por el PI de la lista. Tras la operación, el PI
	//		apunta al nuevo nodo.
	// COM: O(1)
	void insertar	( const TipoDato &d );

	// PRE: ---
	// DES: Elimina el nodo apuntado por el PI de la lista. Tras la operación,
	//		el PI apunta al nodo siguiente al eliminado.
	//		Si la lista está vacía no hace nada.
	// COM: O(1)
	void eliminar ( );

	// PRE: ---
	// DES: Mueve el PI de la lista al siguiente nodo. Si la lista está vacía
	//		o el PI apunta está al final de la lista (PI == nullptr), no hace nada.
	// COM: O(1)
	void avanzar ( );

	// PRE: ---
	// DES: Mueve el PI de la lista al nodo anterior de la lista. Si la lista
	//		está vacía o el PI apunta al primero de la lista, no hace nada.
	// COM: O(1)
	void retroceder ( );

	// PRE: ---
	// DES: Mueve el PI de la lista a su primer nodo.
	// COM: O(1)
	void moverPrimero ( );

	// PRE: ---
	// DES: Mueve el PI de la lista a su último nodo.
	// COM: O(1)
	void moverUltimo ( );

	// PRE: ---
	// DES: Devuelve TRUE si el PI de la lista está apuntando a su
	//		primer nodo (primero). FALSE en caso contrario.
	// COM: O(1)
	bool enPrimero ( );

	// PRE: ---
	// DES: Devuelve TRUE si el PI de la lista está apuntando a su
	//		último nodo (ultimo). FALSE en caso contrario.
	// COM: O(1)
	bool enUltimo ( );

	// PRE: ---
	// DES: Devuelve TRUE si el PI de la lista está apuntando a nullptr
	//		(después de su último nodo). FALSE en caso contrario.
	// COM: O(1)
	bool alFinal ( );

	// PRE: ---
	// DES: Destructor. Vacía la lista eliminando todos sus elementos.
	// COM: O(1)
	~ListaDPI ( );
};

template <class TipoDato>
ListaDPI<TipoDato>::ListaDPI ( ) {
	primero = nullptr;
	ultimo = nullptr;
	pi  = nullptr;
}

template <class TipoDato>
bool ListaDPI<TipoDato>::estaVacia ( ) const {
	return primero == nullptr;
}
template <class TipoDato>
TipoDato ListaDPI<TipoDato>::consultar ( ) const {
	return pi->dato;
}

template <class TipoDato>
void ListaDPI<TipoDato>::consultar ( TipoDato &d ) const {
	d = pi->dato;
}

template <class TipoDato>
void ListaDPI<TipoDato>::insertar ( const TipoDato &d ) {
	PtrNodo aux = new Nodo ( d );

	if ( pi == nullptr ) {
		if ( estaVacia ( ) ) { 	// Inserción en una lista vacía
			aux->sig = pi;
			primero = aux;
			ultimo = aux;
		}
		else { 					// pi está a null al final de la lista
			aux->ant = ultimo;		// Inserción al final de la lista
			ultimo->sig = aux;
			ultimo = aux;
		}
	}
	else {
		if (pi->ant == nullptr) { // Inserción al principio de la lista
			primero = aux;
			aux->sig = pi;
			aux->ant = nullptr;
			pi->ant = aux;
		}
		else {  				 // Inserción en posicion intermedia
			aux->ant = pi->ant;
			aux->sig = pi;
			pi->ant->sig = aux;
			pi->ant = aux;
		}
	}
}

template <class TipoDato>
void ListaDPI<TipoDato>::eliminar ( ) {
	PtrNodo aux;

	if ( !estaVacia ( ) && !alFinal ( ) ) {

		aux = pi;

		if ( pi == primero ) // Eliminar primer nodo
			primero = primero->sig;

		if ( pi == ultimo )    // Eliminar último nodo
			ultimo = ultimo->ant;

		pi = pi->sig; 		// PI apunta al nodo siguiente al eliminado

		if ( aux->ant != nullptr )
			aux->ant->sig = pi;

		if ( aux->sig != nullptr )
			pi->ant = aux->ant;

		delete aux;			// Liberamos la memoria asociada al nodo eliminado
	}
}

template <class TipoDato>
void ListaDPI<TipoDato>::avanzar ( ) {
	if ( pi != nullptr ) {		// Lista no vacía y PI no está al final (alFinal () = false)
		pi = pi->sig;
	}
}

template <class TipoDato>
void ListaDPI<TipoDato>::retroceder ( ) {
	if ( pi != primero ) {		// Si estamos en el primer nodo no hace nada
		if ( pi != nullptr ) {	// Si estamos en un nodo intermedio o en el último...
			pi = pi->ant;		// ... retrocede.
		} else {				// Si pi apunta a nullptr (alFinal () = true),
			pi = ultimo;		// retrocedemos al último.
		}
	}
}

template <class TipoDato>
void ListaDPI<TipoDato>::moverPrimero ( ) {
	pi = primero;
}

template <class TipoDato>
void ListaDPI<TipoDato>::moverUltimo ( ) {
	pi = ultimo;
}

template <class TipoDato>
bool ListaDPI<TipoDato>::enPrimero ( ) {
	return pi == primero;
}

template <class TipoDato>
bool ListaDPI<TipoDato>::enUltimo ( ) {
	return pi == ultimo;
}

template <class TipoDato>
bool ListaDPI<TipoDato>::alFinal ( ) {
	return pi == nullptr;
}

template <class TipoDato>
ListaDPI<TipoDato>::~ListaDPI ( ) {
	moverPrimero ( );
	while ( !estaVacia() ) {
		eliminar ( );
	}
	primero = nullptr;
	ultimo = nullptr;
	pi  = nullptr;
}

#endif /* LISTADPI_H_ */

/*
 *
 * Este archivo pertenece al proyecto 'proyecto2',
 * creado por José Manuel De Torres Domínguez.
 *
 *
 */
