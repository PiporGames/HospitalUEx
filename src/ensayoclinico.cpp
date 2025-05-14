/*
 *
 * Este archivo pertenece al proyecto 'proyecto3',
 * creado por José Manuel De Torres Domínguez.
 *
 * JMDTD 2023©
 *
 */

#include "ensayoclinico.h"
#include "timer.h"
#include <fstream>

void EnsayoClinico::insertarOrdenadoR(kpac vector[MAX], BSTree <kpac>* arbol, int min, int max) {
	int centro = (max + min) / 2;
	if (centro != min) {
		int izq = (min + centro) / 2;
		int der = (max + centro) / 2;
		arbol->insertar(vector[izq]);
		arbol->insertar(vector[der]);
		insertarOrdenadoR(vector, arbol, min, centro); //IZQ
		insertarOrdenadoR(vector, arbol, centro, max); //DER
	}
}

void EnsayoClinico::insertarOrdenado(kpac vector[MAX], BSTree <kpac>* arbol, int n) {
	arbol->insertar(vector[n / 2]);
	insertarOrdenadoR(vector, arbol, 0, n);
}

EnsayoClinico::EnsayoClinico(){
	//Establecer miembros
	nombre = "JOSÉ MANUEL DE TORRES DOMÍNGUEZ";
	arboldni = new BSTree<kpac>();
	listapnt = new ListaDPI<Paciente*>();
	listaerr = new ListaDPI<string>();

	//Cargar pacientes en el vector
	bool exit = false;
	int elementCnt = 0;
	kpac vector[MAX];

	ifstream ifs;
	string nombre;
	string apellidos;
	string DNI;
	string edad;
	string genero_raw;
	Paciente * p = nullptr;

	ifs.open("pacientes_ordenados.csv");

	if (ifs.fail()) {
			cerr << "ERROR EnsayoClinico(): Archivo (pacientes_ordenados.csv) no encontrado." << endl;
		} else {
		while (!ifs.eof() && !exit) {
			getline(ifs, DNI, ';');
			if (!ifs.eof() && !exit) {
				getline(ifs, nombre, ';');
				getline(ifs, apellidos, ';');
				getline(ifs, genero_raw, ';');
				getline(ifs, edad, '\n');
				p = new Paciente(nombre, apellidos, DNI, stoi(edad), p->intToSexo(stoi(genero_raw)));
				kpac kpac(DNI, p);

				vector[elementCnt] = kpac;

				elementCnt++;
			}
		}
		ifs.close();
		if (!exit){
			cout << "Cargados correctamente " << elementCnt << " elementos en memoria."<< endl;
		}
	}

	//Organizar arbol
	insertarOrdenado(vector, arboldni, elementCnt);
}

//Pese a que es posible hacer una implementación generalizada en "BSTree.h", con el motivo de ahorrar tiempo, se ha optado por
//una implementación especializada para resolver la busqueda de 'kp's en el arbol, que unicamente se utilizará una vez, en vez
//de su implementación generalizada en la librería.
bool EnsayoClinico::buscarKpac(BSTree<kpac> * tr, string DNI, kpac &key){
	bool enc = false;
	if (!tr->estaVacio()) {
		BSTree<kpac> *aux;
		kpac dato = tr->getDato();
		string DNIpac = dato.getValue()->getDNI();
		if (DNI < DNIpac) {
			aux = tr->getIzq();
			if (aux != nullptr) {
				enc = buscarKpac(aux, DNI, key);
			}
		} else if (DNI > DNIpac) {
			aux = tr->getDer();
			if (aux != nullptr) {
				enc = buscarKpac(aux, DNI, key);
			}
		} else {
			enc = true;
			key = dato;
		}
	}
	return enc;
};

//Introducir pacientes en Lista de puntuaciones (de forma ordenada)
//Para ello, recorremos el arbol entero y vamos comprobando la lista enlazada colocando a los pacientes según su puntuación.
void EnsayoClinico::ordenarPuntos(BSTree<kpac>* tr, ListaDPI<Paciente*>* l, int n) {
	bool enc = false;

	if ((!tr->estaVacio())&&(n > 0)) {
		if (tr->getIzq() != NULL) ordenarPuntos(tr->getIzq(), l,n);
		
		Paciente* pac = tr->getDato().getValue();
		l->moverPrimero();
		if (l->estaVacia()) {
			l->insertar(pac);
		}
		else {
			while ((!enc)&&(!l->alFinal())) {
				if (l->consultar()->getPuntuacion() > pac->getPuntuacion()) {
					l->avanzar();
				}
				else {
					n--;
					l->insertar(pac);
					enc = true;
				}
			}
			if (!enc) {
				n--;
				l->insertar(pac);
			}
		}

		if (tr->getDer() != NULL) ordenarPuntos(tr->getDer(), l,n);
	}
}

void EnsayoClinico::anotar(){
	//Cargar ensayo
	bool exit = false;
	bool enc = false;
	int elementCnt = 0;
	int errCnt = 0;

	ifstream ifs;
	string DNI;
	string puntuacion;

	ifs.open("ensayo.csv");

	if (ifs.fail()) {
			cerr << "ERROR EnsayoClinico::anotar(): Archivo (ensayo.csv) no encontrado." << endl;
		} else {
		while (!ifs.eof() && !exit) {
			getline(ifs, DNI, ';');
			if (!ifs.eof() && !exit) {
				getline(ifs, puntuacion, '\n');
				//datos del kpac obtenidos

				kpac kpac1;
				//buscamos en el arbol el kpac asociado al DNI
				if (!buscarKpac(arboldni,DNI,kpac1)) {

					errCnt++;

					// (intentar) insertar DNI en la listaerr
					// para ello, hacemos bucle en ListaDPI buscando el DNI
					// si la busqueda falla, insertamos el DNI
					// si la busqueda acierta, no hacemos nada.
					listaerr->moverPrimero();
					while ((!listaerr->alFinal())&&(!enc)) {
						if (listaerr->consultar() == DNI) {
							enc = true;
						}
						else {
							listaerr->avanzar();
						}
					}
					if (!enc) {
						listaerr->insertar(DNI);
					}
					enc = false;
				} else {
					int pnt = stoi(puntuacion);
					kpac1.getValue()->setPuntuacion(kpac1.getValue()->getPuntuacion() + pnt);
				}
				elementCnt++;
			}
		}
		ifs.close();
		if (!exit){
			cout << "Cargados y actualizados correctamente " << elementCnt << " elementos en memoria. (" << errCnt << " errores)" << endl;
		}
	}
}

int EnsayoClinico::calcularProfundidad ( BSTree<kpac> * tr) {
	int izq = 0; int der = 0; int res = 0;
	if (!tr->estaVacio()) {
		if (tr->getIzq() != NULL) {
			izq = calcularProfundidad(tr->getIzq());
		}
		if (tr->getDer() != NULL) {
			der = calcularProfundidad(tr->getDer());
		}
		if (izq > der) {
			res = izq;
		}
		else {
			res = der;
		}
	}

	return (res+1);
}

void EnsayoClinico::mostrarMayores(int cuantos){

	if (!listapnt->estaVacia()) {
		listapnt->moverPrimero();
		while (!listapnt->estaVacia()) {
			listapnt->eliminar();
		}
	}

	ordenarPuntos(arboldni, listapnt, cuantos);

	listapnt->moverPrimero();
	while ((!listapnt->alFinal())&&(cuantos > 0)) {
		listapnt->consultar()->mostrar();
		listapnt->avanzar();
		cuantos--;
	}
}

void EnsayoClinico::mostrarPorApellidoR(BSTree<kpac> * tr, string ss){
	if (!tr->estaVacio()) {
		kpac dato = tr->getDato();

		bool contieneSS = (dato.getValue()->getApellidos().find(ss) != string::npos);
		if (contieneSS) {
			dato.getValue()->mostrar();
		}

		//MOSTRAR: IZQUIERDA, CENTRO, DERECHA
		if (tr->getIzq() != NULL) mostrarPorApellidoR(tr->getIzq(), ss);

		if (tr->getDer() != NULL) mostrarPorApellidoR(tr->getDer(), ss);
	}
};

void EnsayoClinico::mostrarPorApellido(string s_apellido){
	mostrarPorApellidoR(arboldni, s_apellido);
}

void EnsayoClinico::mostrarPorDNIR(BSTree<kpac>* tr, string ss) {
	if (!tr->estaVacio()) {
		kpac dato = tr->getDato();
		string DNI_ss = dato.getValue()->getDNI().substr(0, ss.size());

		if (DNI_ss == ss) {
			dato.getValue()->mostrar();
			if (tr->getIzq() != NULL) mostrarPorDNIR(tr->getIzq(), ss);
			if (tr->getDer() != NULL) mostrarPorDNIR(tr->getDer(), ss);
		} else {
			if (DNI_ss > ss) {
				if (tr->getIzq() != NULL) mostrarPorDNIR(tr->getIzq(), ss);
			} else {
				if (tr->getDer() != NULL) mostrarPorDNIR(tr->getDer(), ss);
			}
		}
	}
};

void EnsayoClinico::mostrarPorDNI(string s_dni){
	mostrarPorDNIR(arboldni, s_dni);
}

void EnsayoClinico::mostrarErrores() {
	listaerr->moverPrimero();
	while (!listaerr->alFinal()) {
		cout << endl << listaerr->consultar() << endl;
		listaerr->avanzar();
	}
}

int EnsayoClinico::numNiveles() {
	return calcularProfundidad(arboldni);
}

string EnsayoClinico::getNombre() {
	return nombre;
}

EnsayoClinico::~EnsayoClinico(){
	delete(arboldni);
	delete(listapnt);
	delete(listaerr);
}


/*
 *
 * Este archivo pertenece al proyecto 'proyecto3',
 * creado por José Manuel De Torres Domínguez.
 *
 * JMDTD 2023©
 *
 */



