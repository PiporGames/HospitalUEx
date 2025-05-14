/*
 *
 * Este archivo pertenece al proyecto 'proyecto3',
 * creado por José Manuel De Torres Domínguez.
 *
 *
 */

#ifndef _BSTREE_H
#define _BSTREE_H

const int MAX = 200;

template <class TipoDato>
class BSTree {

private:

	TipoDato          dato;		// Dato del árbol actual
	bool  			  vacio;	// Estado del árbol actual (vacío | no vacío)
	BSTree<TipoDato>  *izq;		// Subárbol izquierdo del árbol actual
	BSTree<TipoDato>  *der;		// Subárbol derecho del árbol actual

	//PRE = { dato correctamente inicializado. }
	//POST = { Método auxiliar recursivo que elimina dato del árbol reajustando
	//		los punteros convenientemente. }
	//COMP y TAMÑ en la desc. del método de llamada (BSTree<TipoDato>::eliminar).
	BSTree<TipoDato> *eliminarR ( TipoDato dato );

public:

	//PRE = {}
	//DESC: Constructor por defecto. Crea un árbol vacío con subárboles izq y der
	//		apuntando a nullptr.
	//COMP: O(1)
	BSTree  ( );

	//PRE = { dato correctamente inicializado. }
	//		izq apunta a nullptr o a un BSTree correctamente inicializado.
	//		der apunta a nullptr o a un BSTree correctamente inicializado.
	//DESC: Constructor parametrizado. Crea un árbol con dato d, colocando
	// 		izq como su subárbol izquierdo y der como su subárbol derecho
	//COMP: O(1)
	BSTree  ( BSTree<TipoDato> *izq, TipoDato d, BSTree<TipoDato> *der );

	//PRE = {}
	//POST = { Devuelve this->izq (puntero al subarbol izquierdo de this) }
	//COMP: O(1)
	BSTree    *getIzq  ( ) const;

	//PRE = {}
	//POST = { Devuelve this->der (puntero al subarbol derecho de this) }
	//COMP: O(1)
	BSTree    *getDer  ( ) const;

	//PRE = {}
	//POST = { Devuelve this->dato (dato almacenado en el árbol this) }
	//COMP: O(1)
	TipoDato  getDato  ( ) const;

	//PRE = {}
	//POST = { Devuelve this->vacio }
	//COMP: O(1)
	bool     estaVacio ( ) const;

	//PRE = { dato correctamente inicializado. }
	//DESC: Inserta dato en el árbol de forma que éste sigue siendo un BSTree.
	//		Si dato ya está en el árbol no hace nada.
	//COMP: O(log n)
	//TAMÑ: n = tamaño del arbol
	void     insertar  ( const TipoDato &dato );

	//PRE = { dato correctamente inicializado. }
	//DESC: Elimina dato del árbol de forma que éste sigue siendo un BSTree
	//		Si dato no está en el árbol no hace nada.
	//COMP: O(log n)
	//TAMÑ: n = tamaño del arbol
	void     eliminar  ( const TipoDato &dato );

	//PRE = { dato correctamente inicializado. }
	//POST = { Devuelve true si dato está en el árbol; false en caso contrario }
	//COMP: O(log n)
	//TAMÑ: n = tamaño del arbol
	bool     existe    ( const TipoDato &dato ) const;

	//PRE = {}
	//DESC: Libera la memoria asignada al árbol, incluida la asignada a sus
	//		subárboles (si los tiene).
	//COMP: O(log n)
	//TAMÑ: n = tamaño del arbol
	~BSTree  ( );

};

template <class TipoDato>
BSTree<TipoDato>::BSTree ( ) {
	this->vacio = true;
	this->izq   = nullptr;
	this->der   = nullptr;
}

template <class TipoDato>
BSTree<TipoDato>::BSTree ( BSTree<TipoDato> *izq, TipoDato dato, BSTree<TipoDato> *der ) {
	this->vacio = false;
	this->dato 	= dato;
	this->izq  	= izq;
	this->der  	= der;
}

template <class TipoDato>
BSTree<TipoDato>::~BSTree ( ) {
   BSTree<TipoDato> *aux;
   if ( !estaVacio ( ) ) {
      aux = this->getIzq ( );
      if ( aux != nullptr ) {
         delete aux;
      }
      aux = this->getDer ( );
      if ( aux != nullptr ) {
         delete aux;
      }
      this->vacio = true;
   }
}

template <class TipoDato>
TipoDato BSTree<TipoDato>::getDato ( ) const {
	return this->dato;
}

template <class TipoDato>
bool BSTree<TipoDato>::estaVacio() const {
	return this->vacio;
}

template <class TipoDato>
BSTree<TipoDato> *BSTree<TipoDato>::getIzq ( ) const {
	return this->izq;
}

template <class TipoDato>
BSTree<TipoDato> *BSTree<TipoDato>::getDer ( ) const {
	return this->der;
}

template <class TipoDato>
void BSTree<TipoDato>::insertar(const TipoDato& dato) {
	if (estaVacio()) {
		this->dato = dato;
		this->vacio = false;
	}
	else {
		if (dato != this->dato) {
			BSTree<TipoDato>* aux;
			if (dato < this->dato) {
				aux = getIzq();
				if (aux == nullptr) {
					izq = aux = new BSTree<TipoDato>();
				}
			}
			else {
				aux = getDer();
				if (aux == nullptr) {
					der = aux = new BSTree<TipoDato>();
				}
			}
			aux->insertar(dato);
		}
	}
}


template <class TipoDato>
void BSTree <TipoDato>::eliminar ( const TipoDato &dato ) {
	if ( !estaVacio ( ) ) {
		if ( dato < this->dato ) {
			if ( izq != nullptr ) {
				izq = izq->eliminarR ( dato );
			}
		}
		else if ( dato > this->dato ) {
			if ( der != nullptr ) {
				der = der->eliminarR ( dato );
			}
		}
		else {
			if ( ( izq == nullptr ) && ( der == nullptr ) ) {
				vacio = true;
			}
			else {
				eliminarR ( dato );
			}
		}
	}
}

template <class TipoDato>
BSTree<TipoDato> *BSTree<TipoDato>::eliminarR ( TipoDato dato ) {
	TipoDato datoAux;
	BSTree *aDevolver = this;
	BSTree *aEliminar;
	BSTree *candidato;
	BSTree *padre;

	if ( !estaVacio ( ) ) {
		if ( dato < this->dato ) {
			if ( izq != nullptr ) {
				izq = izq->eliminarR ( dato );
			}
		}
		else if ( dato > this->dato ) {
			if ( der != nullptr ) {
				der = der->eliminarR ( dato );
			}
		}
		else {
			aEliminar = this;

			// 1. El árbol a eliminar es una hoja (no tiene subárboles)
			if ( ( der == nullptr ) && ( izq == nullptr ) ) {
				delete aEliminar;
				aDevolver = nullptr;
			}
			else {
				// 2. El árbol tiene al menos un subárbol
				// 2.1. Sólo tiene subárbol izquierdo
				if ( der == nullptr ) {
					aEliminar = izq;
					datoAux = this->dato;
					this->dato = izq->getDato();
					izq->dato = datoAux;
					izq = izq->getIzq();
					der = aEliminar->getDer();
					aDevolver = this;
				}
				// 2.2. Sólo tiene subárbol derecho
				else if ( izq == nullptr ) {
					aEliminar = der;
					datoAux = this->dato;
					this->dato = der->getDato();
					der->dato = datoAux;
					der = der->getDer();
					izq = aEliminar->getIzq();
					aDevolver = this;
				}
				// 2.3. Tiene dos subárboles: izquierdo y derecho
				else {
					// Empezando en la raíz del subárbol izquierdo (hijos menores)...
					candidato = getIzq();
					padre = this;
					// ... vamos hasta el final de la rama derecha
					// => candidato queda apuntando al mayor de los hijos menores
					while ( candidato->getDer() != nullptr ) {
						padre = candidato;
						candidato = candidato->getDer();
					}
					datoAux = this->dato;
					this->dato = candidato->getDato();
					candidato->dato = datoAux;
					aEliminar = candidato;
					if ( padre == this ) {
						izq = candidato->getIzq();
					}
					else {
						padre->der = candidato->getIzq();
					}
				}

				// Eliminamos el elemento actual (no la totalidad del subárbol)
				aEliminar->izq  = nullptr;
				aEliminar->der = nullptr;
				delete aEliminar;
			}
		}
	}
	return aDevolver;
}


template <class TipoDato>
bool BSTree<TipoDato>::existe (const TipoDato &dato) const {
	bool enc = false;
	if (estaVacio()) {
		enc  = false;
	}
	else {
		BSTree<TipoDato> *aux;
		if (dato < this->dato) {
			aux = getIzq();
			if (aux != nullptr) {
				enc = aux->existe ( dato );
			}
		}
		else if ( dato > this->dato ) {
			aux = getDer();
			if (aux != nullptr) {
				enc = aux->existe ( dato );
			}
		}
		else {
			enc = true;
		}
	}
	return enc;
}


#endif /* _BSTREE_H_ */

/*
 *
 * Este archivo pertenece al proyecto 'proyecto3',
 * creado por José Manuel De Torres Domínguez.
 *
 *
 */
