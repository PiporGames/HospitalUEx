/*
 *
 * Este archivo pertenece al proyecto 'proyecto3',
 * creado por José Manuel De Torres Domínguez.
 *
 * JMDTD 2023©
 *
 */

#include "paciente.h"

Paciente::Paciente() {
	nombre = "";
	apellidos = "";
	DNI = "";
	edad = 0;
	genero = sexo::NO_DEFINIDO;
	puntuacion = 0;
}

Paciente::Paciente(string nombre, string apellidos, string DNI, int edad, sexo genero) {
	this->nombre = nombre;
	this->apellidos = apellidos;
	this->DNI = DNI;
	this->edad = edad;
	this->genero = genero;
	this->puntuacion = -1;
}

Paciente::Paciente(const Paciente &pac){
	this->nombre = pac.nombre;
	this->apellidos = pac.apellidos;
	this->DNI = pac.DNI;
	this->edad = pac.edad;
	this->genero = pac.genero;
	this->puntuacion = pac.puntuacion;
}

string Paciente::getNombre() const {
	return nombre;
}
string Paciente::getApellidos() const {
	return apellidos;
}
string Paciente::getDNI() const {
	return DNI;
}
int Paciente::getEdad() const {
	return edad;
}
sexo Paciente::getGenero() const {
	return genero;
}
int Paciente::getPuntuacion() const {
	return puntuacion;
}

void Paciente::setNombre(string nombre){
	this->nombre = nombre;
}
void Paciente::setApellidos(string apellidos){
	this->apellidos = apellidos;
}
void Paciente::setDNI(string DNI){
	this->DNI = DNI;
}
void Paciente::setEdad(int edad){
	this->edad = edad;
}
void Paciente::setGenero(sexo genero){
	this->genero = genero;
}
void Paciente::setPuntuacion(int puntuacion) {
	this->puntuacion = puntuacion;
}

Paciente::~Paciente() {
}

void Paciente::mostrar(){
	cout << DNI << " # " << nombre << " " << apellidos << " # " << edad << " # " << sexoToString(genero) << " # " << puntuacion << endl;
}

string Paciente::sexoToString(sexo sex){
	string res;
	switch (genero)
	{
	case sexo::HOMBRE:
		res = "HOMBRE";
		break;
	case sexo::MUJER:
		res = "MUJER";
		break;
	case sexo::NO_DEFINIDO:
		res = "NO DEFINIDO";
		break;
	default:
		break;
	}

	return res;
}

sexo Paciente::intToSexo(int pos){
	sexo res = sexo::NO_DEFINIDO;
	switch (pos)
	{
	case 0:
		res = sexo::HOMBRE;
		break;
	case 1:
		res = sexo::MUJER;
		break;
	default:
		res = sexo::NO_DEFINIDO;
		break;
	}

	return res;
}

/*
 *
 * Este archivo pertenece al proyecto 'proyecto3',
 * creado por José Manuel De Torres Domínguez.
 *
 * JMDTD 2023©
 *
 */
