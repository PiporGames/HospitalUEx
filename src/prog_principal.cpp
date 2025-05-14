/*
 *
 * Este archivo pertenece al proyecto 'proyecto3',
 * creado por José Manuel De Torres Domínguez.
 *
 * JMDTD 2023©
 *
 */

#include <iostream>
#include <string>

#include "timer.h"
#include "paciente.h"
#include "ensayoclinico.h"
#include "pr_ensayoclinico.h"
// Si necesitas incluir clases adicionales, hazlo aqui:


using namespace std;

// Programa principal: la ejecución es puramente secuencial (sin menú)
int main () {

	/*
	 * 			PRUEBAS
	 */
	//test_ec_todo();

   // El siguiente codigo debe funcionar SIN MODIFICACIONES
   EnsayoClinico *ec = nullptr;
   
   double t_start = Timer::getTime();  // Instante inicial
      
   ec = new EnsayoClinico(); 
   cout << "Ensayo de: " << ec->getNombre() << endl << endl; // Debe mostrar el nombre del alumno
   
   ec->anotar();
   
   int cuantosMay = 10;
   cout << "Mostrar 10 pacientes con mayor puntuación: " << endl;
   ec->mostrarMayores(cuantosMay);
   cout << endl;
   
   cout << "Errores en pacientes: " << endl;
   ec->mostrarErrores();

   double t_end = Timer::getTime();  // Instante final
   cout << endl << "Tiempo: " << t_end - t_start << endl << endl;

   // Algoritmos adicionales:
   // 1. Numero de niveles del árbol
   cout << "Niveles del arbol: " << ec->numNiveles() << endl << endl;
   
   // 2. Mostrar Pacientes cuyo apellido contenga por una subcadena
   cout << "Pacientes cuyo apellido contiene la cadena -art-:" << endl;
   ec->mostrarPorApellido("art");
   cout << endl;
   
   // 3. Mostrar Pacientes cuyo DNI comience por una subcadena
   cout << "Pacientes cuyo DNI empieza por la cadena -28-:" << endl;
   ec->mostrarPorDNI("28");
   cout << endl;

   delete ec;
   return 0;
}

/*
 *
 * Este archivo pertenece al proyecto 'proyecto3',
 * creado por José Manuel De Torres Domínguez.
 *
 * JMDTD 2023©
 *
 */
