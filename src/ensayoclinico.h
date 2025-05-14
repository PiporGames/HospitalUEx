/*
 *
 * Este archivo pertenece al proyecto 'proyecto3',
 * creado por José Manuel De Torres Domínguez.
 *
 * JMDTD 2023©
 *
 */
/*
 * ensayoclinico.h
 *
 *  Autor: Juan A. Rico (jarico@unex.es)
 *  Fecha: 15 abril 2023
 */

#ifndef ENSAYO_CLINICO_H_
#define ENSAYO_CLINICO_H_

#include <iostream>
#include <string>

#include "paciente.h"
#include "BSTree.h"
#include "KeyValue.h"
#include "ListaDPI.h"
// Si necesitas alguna ED o clase adicional, puedes incluirla aqui

using namespace std;


/*
 *  Para reducir considerablemente la longitud del código, se utilizará las siguientes abreviaturas:
 */
typedef KeyValue<string, Paciente*> kpac;



class EnsayoClinico {

private:
   string  nombre; // Inicializa con tu NOMBRE Y APELLIDOS en el constructor
   BSTree<kpac> * arboldni; // Arbol de DNIs
   ListaDPI<Paciente*> * listapnt; // Lista de puntuaciones
   ListaDPI<string> * listaerr; // Lista de errores (strings de DNI)

   // Métodos privados

   //PRE = { Puntero a BSTree<kp> inicializado }
   //POST = { Devuelve 'true' si se he encontrado el 'kpac' dado un DNI y actualiza el parámetro de entrada-salida 'key' con el kpac encontrado
   //		  Si no se encuentra el DNI en el arbol, 'key' no cambiará y se devolverá 'false' }
   //COMP: O(log n)
   //TAMÑ: n = ocupación del arbol
   bool buscarKpac(BSTree<kpac>* tr, string DNI, kpac &key);

   //PRE = { Puntero a BSTree<kpac> correctamente inicializado, Puntero a ListaDPI<Pacientes*> correctamente inicializado y vacio }
   //DESC: Extrae los Pacientes del BSTree<kpac> dado y los ordena en una ListaDPI<Pacientes*> dada.
   //COMP: O(n)
   //TAMÑ: n = tamaño del arbol
   void ordenarPuntos(BSTree<kpac>* tr, ListaDPI<Paciente*>* l, int n);

   //PRE = { vector[MAX] de kpac, Puntero a BSTree<kpac> correctamente inicializado, int n (tamaño total) }
   //DESC: Inserta un elemento en el BSTree de forma optimizada, obteniendo el valor de un vector dado.
   //		Mantiene la estructura del BSTree lo más estable posible.
   //		Supone que el inicio del vector es el 0 y su fin 'n'.
   //		El vector no debe contener zonas vacias o nulas.
   //COMP: O(log n)
   //TAMÑ: n = tamaño del arbol
   void	 insertarOrdenado(kpac vector[MAX], BSTree <kpac>* arbol, int n);

   //PRE = { Puntero a BSTree<kpac> correctamente inicializado }
   //POST = { Devuelve un 'int' equivalente a la profundidad total del arbol }
   //COMP: O(log n)
   //TAMÑ: n = tamaño del arbol
   int	 calcularProfundidad(BSTree<kpac>* tr);

   //PRE = { vector[MAX] de kpac, Puntero a BSTree<kpac> correctamente inicializado, int min < max }
   //POST, COMP y TAMÑ en la desc. del método de llamada (BSTree<TipoDato>::insertarOrdenado).
   void insertarOrdenadoR(kpac vector[MAX], BSTree <kpac>* arbol, int min, int max);

   //PRE = { Puntero a BSTree<kp> inicializado }
   //POST, COMP y TAMÑ en la desc. del método de llamada (BSTree<TipoDato>::mostrarPorApellido).
   void mostrarPorApellidoR(BSTree<kpac>* tr, string ss);

   //PRE = { Puntero a BSTree<kpac> correctamente inicializado }
   //POST, COMP y TAMÑ en la desc. del método de llamada (BSTree<TipoDato>::mostrarPorDNI).
   void mostrarPorDNIR(BSTree<kpac>* tr, string ss);

public:
   
   // Constructores

   //PRE = {}
   //DESC: Crea un EnsayoClinico por defecto.
   //COMP: O(n)
   //TAMÑ: n = lineas del archivo
   EnsayoClinico();

   // Métodos

   //PRE = {}
   //POST = { Devuelve 'string' nombre (del alumno) }
   //COMP: O(1)
   string getNombre();
   
   //PRE = { Archivo ensayo.csv en el directorio de ejecución }
   //DESC: Lee el archivo ensayo.csv y añade la puntuación de los pacientes.
   //COMP: O(n)
   //TAMÑ: n = lineas del archivo
   void anotar();
   
   //PRE = {}
   //POST = { Devuelve un 'int' equivalente al número de niveles }
   //COMP: O(Recursivo)
   int numNiveles();
   
   //PRE = {}
   //DESC: Muestra por pantalla los DNI de los pacientes de ensayo.csv que no existen
   //COMP: O(n)
   //TAMÑ: n = ocupación de listaerr
   void mostrarErrores();
   
   //PRE = { cuantos < ocupación de listapnt }
   //DESC: Muestra por pantalla "cuantos" pacientes con mayor puntuación.
   //COMP: O(n)
   //TAMÑ: n = (int) cuantos
   void mostrarMayores(int cuantos);
   
   //PRE = {}
   //DESC: Muestra por pantalla pacientes cuyo apellido contiene subcadena "s_apellido".
   //COMP: O(Recursivo)
   void mostrarPorApellido(string s_apellido);
   
   //PRE = {}
   //DESC: Muestra por pantalla pacientes cuyo DNI empieza por subcadena "s_dni".
   //COMP: O(Recursivo)
   void mostrarPorDNI(string s_dni);

   // Destructores

   //PRE = {}
   //DESC: Destruye la clase EnsayoClinico.
   //COMP: O(n)
   //TAMÑ: n = tamaño del arbol
   ~EnsayoClinico();

};

#endif /* ENSAYO_CLINICO_H_ */

/*
 *
 * Este archivo pertenece al proyecto 'proyecto3',
 * creado por José Manuel De Torres Domínguez.
 *
 * JMDTD 2023©
 *
 */
