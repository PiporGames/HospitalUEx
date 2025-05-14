/*
 *
 * Este archivo pertenece al proyecto 'proyecto3',
 * creado por José Manuel De Torres Domínguez.
 *
 * JMDTD 2023©
 *
 */

#ifndef PACIENTE_H_
#define PACIENTE_H_

#include <iostream>
#include <string>
using namespace std;

enum class sexo {
	HOMBRE = 0,
	MUJER = 1,
	NO_DEFINIDO = 2
};

class Paciente {

private:
	string nombre;
	string apellidos;
	string DNI;
	int edad;
	sexo genero;
	int puntuacion;

public:

	//Constructores

	//PRE = {}
	//DESC: Crea un paciente por defecto.
	//COMP: O(1)
	Paciente();
	//PRE = { string nombre, string apellidos, string DNI, int edad > 0, sexo genero (0 o 1) }
	//DESC: Crea un paciente ajustandolo con los parametros dados.
	//COMP: O(1)
	Paciente(string nombre, string apellidos, string DNI, int edad, sexo genero);
	//PRE = { Paciente &pac correctamente inicializado }
	//DESC: Crea un paciente por defecto.
	//COMP: O(1)
	Paciente(const Paciente &pac);

	//Métodos

	//PRE = {}
	//POST = { Devuleve 'string' nombre. }
	//COMP: O(1)
	string getNombre() const;
	//PRE = {}
	//POST = { Devuleve 'string' apellidos. }
	//COMP: O(1)
	string getApellidos() const;
	//PRE = {}
	//POST = { Devuleve 'string' DNI. }
	//COMP: O(1)
	string getDNI() const;
	//PRE = {}
	//POST = { Devuleve 'int' edad. }
	//COMP: O(1)
	int getEdad() const;
	//PRE = {}
	//POST = { Devuleve 'sexo' genero. }
	//COMP: O(1)
	sexo getGenero() const;
	//PRE = {}
	//POST = { Devuleve 'int' puntuacion. }
	//COMP: O(1)
	int getPuntuacion() const;
	//PRE = { string nombre }
	//DESC: Ajusta un nuevo nombre al paciente.
	//COMP: O(1)
	void setNombre(string nombre);
	//PRE = { string apellidos }
	//DESC: Ajusta un nuevo apellido al paciente.
	//COMP: O(1)
	void setApellidos(string apellidos);
	//PRE = { string DNI }
	//DESC: Ajusta un nuevo DNI al paciente.
	//COMP: O(1)
	void setDNI(string DNI);
	//PRE = { int edad }
	//DESC: Ajusta una nueva edad al paciente.
	//COMP: O(1)
	void setEdad(int edad);
	//PRE = { sexo genero }
	//DESC: Ajusta un nuevo genero al paciente.
	//COMP: O(1)
	void setGenero(sexo genero);
	//PRE = { int puntuacion }
	//DESC: Ajusta una nueva puntuación al Paciente.
	//COMP: O(1)
	void setPuntuacion(int puntuacion);

	//PRE = {}
	//DESC: Muestra la información del paciente por pantalla.
	//COMP: O(1)
	void mostrar();
	//PRE = { enumeración sexo inicializada }
	//POST = { Devuelve un 'string' equivalente a su enumeración }
	//COMP: O(1)
	string sexoToString(sexo sex);
	//PRE = { pos dentro de los margenes de la enumeración sexo }
	//POST = { Devuelve una enumeración sexo equivalente a su valor en referencia a la posición dada por 'pos' }
	//COMP: O(1)
	sexo intToSexo(int pos);

	//Destructores

	//PRE = {}
	//DESC: Destructor del paciente.
	//COMP: O(1)
	~Paciente();


};



#endif /* PACIENTE_H_ */

/*
 *
 * Este archivo pertenece al proyecto 'proyecto3',
 * creado por José Manuel De Torres Domínguez.
 *
 * JMDTD 2023©
 *
 */
