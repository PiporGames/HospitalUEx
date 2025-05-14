/*
 *
 * Este archivo pertenece al proyecto 'proyecto3',
 * creado por José Manuel De Torres Domínguez.
 *
 * JMDTD 2023©
 *
 */

#ifndef PR_ENSAYOCLINICO_H_
#define PR_ENSAYOCLINICO_H_

#include "ensayoclinico.h"

/*
 *
 * Conjunto de todas las pruebas de evaluación para EnsayoClinico.
 *
 */
void test_ec_todo();

/*----- Variable ------ Antes ----- Ahora ------
 *
 *		TEST 1
 *
 * 		nombre			***			"JOSÉ MANUEL DE TORRES DOMÍNGUEZ"
 * 		arboldni		***			new (BSTree<kpac>)
 * 		listapnt		***			new (ListaDPI<Paciente*>);
 * 		listaerr		***			new (ListaDPI<string>);
 *
 *		Para concluir que la E.D. se ha cargado correctamente, el mensaje de control mostrado por pantalla debe ser igual al número de elementos en el archivo.
 *		(Suponiendo que no existen errores en el archivo)
 *
 */
void test_ec_constructores();

/*
*
* 	Conjunto de pruebas de evaluación de los métodos de 'ensayoclinico.h'
*
* 	Pruebas semi-automáticas. Requiere supervisión.
* 	Prueba automática con registro incorporado:
* 		Todos los pasos serán detallados por pantalla. Los errores, en caso de haberlos, se mostrarán por pantalla.
*
* 	Este conjunto de pruebas evalua:
* 		- Constructores
* 		- getNombre()
* 		- anotar()
* 		- numNiveles()
* 		- mostrarMayores()
* 		- mostrarPorApellido()
* 		- mostrarPorDNI()
*
 */
void test_ec_basico();


#endif /* PR_ENSAYOCLINICO_H_ */

/*
 *
 * Este archivo pertenece al proyecto 'proyecto3',
 * creado por José Manuel De Torres Domínguez.
 *
 * JMDTD 2023©
 *
 */
