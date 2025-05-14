
#include "pr_ensayoclinico.h"

void test_ec_todo(){
	cout << "**********************************************************************" << endl;
	cout << "Inicio de pruebas de EnsayoClinico" << endl;
	cout << "**********************************************************************" << endl;
	test_ec_constructores();
	test_ec_basico();
	cout << "**********************************************************************" << endl;
	cout << "Fin de pruebas de EnsayoClinico" << endl;
	cout << "**********************************************************************" << endl;
}

void test_ec_constructores(){
	cout << "INICIO DE PRUEBA - test_ec_constructores()" << endl;

	EnsayoClinico * ec = new (EnsayoClinico);

	delete(ec);

	cout << "FIN DE PRUEBA - test_ec_constructores()" << endl;
}

void test_ec_basico(){
	cout << "INICIO DE PRUEBA - test_ec_basico()" << endl;

	EnsayoClinico * ec = new (EnsayoClinico);

	if (ec->getNombre() != "JOSÉ MANUEL DE TORRES DOMÍNGUEZ") {
		cerr << "Error getnombre(): El nombre personalizado no es correcto" << endl;
	}

	cout << "Ejecutando mostrarErrores() (no debería mostrar nada)..." << endl;
	ec->mostrarErrores();
	cout << endl;

	cout << "Ejecutando anotar()..." << endl;
	ec->anotar();
	cout << endl;

	cout << "Ejecutando mostrarErrores()..." << endl;
	ec->mostrarErrores();
	cout << endl;

	cout << "Profundidad del arbol... " << ec->numNiveles() << " niveles" << endl;
	cout << endl;

	cout << "Mostrando las 20 mejores puntuaciones..." << endl;
	ec->mostrarMayores(20);
	cout << endl;

	cout << "Mostrando las 100 mejores puntuaciones..." << endl;
	ec->mostrarMayores(100);
	cout << endl;

	cout << "Mostrando las 0 mejores puntuaciones..." << endl;
	ec->mostrarMayores(0);
	cout << endl;

	cout << "Buscando y mostrando por pantalla al creador de este proyecto (por apellido)..." << endl;
	cout << "Buscando por: Torres Domínguez" << endl;
	ec->mostrarPorApellido("Torres Domínguez");

	cout << "Buscando y mostrando por pantalla al creador de este proyecto (por DNI)..." << endl;
	cout << "Buscando por: 774" << endl;
	ec->mostrarPorDNI("774");

	cout << "FIN DE PRUEBA - test_ec_basico()" << endl;
}


