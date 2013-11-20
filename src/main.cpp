/*
 * main.cpp
 *
 *  Created on: 16/11/2013
 *      Author: null3d
 */

#include <string>
#include "DatosGrafo.h"
#include "DatosEntrenamiento.h"
#include "Grafo.h"
#include "FuncionesUtiles.h"
#include <fstream>

/*! \mainpage Implementación red neuronal mediante grafos
 *
 * \section  Descripcion general
 * <h4>Esta herramienta permite la creación y entrenamiento de redes neuronales, actualmente existen
 * varias herramientas para hacer este tipo de redes (por ejemplo, matlab) pero esta en específica
 * crea y entrena la red mediante Grafos. </h4>
 *
 *
 *
 * \section  Licencia
 * <a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/3.0/deed.es"><img alt="Licencia Creative Commons" style="border-width:0" src="http://i.creativecommons.org/l/by-nc-sa/3.0/88x31.png" /></a><br /><span xmlns:dct="http://purl.org/dc/terms/" property="dct:title">Implementación red neuronal mediante grafos</span> por <span xmlns:cc="http://creativecommons.org/ns#" property="cc:attributionName">Cristian Rojas</span> se encuentra bajo una <a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/3.0/deed.es">Licencia Creative Commons Atribución-NoComercial-CompartirIgual 3.0 Unported</a>.<br />Basada en una obra en <a xmlns:dct="http://purl.org/dc/terms/" href="https://github.com/alejo0317/RedNeuronal" rel="dct:source">https://github.com/alejo0317/RedNeuronal</a>.
 * \section intro_sec
 * <h4>
 * Cristian Alejandro Rojas Quintero </h4>
 * <h4> carojasq@correo.udistrital.edu.co </h4>
 * <h4> Ingeniería de sistemas - Universidad Distrital FJC </h4>
 * <h4> 2013 - II </h4>
 */

using namespace std;

/**
 * Función que lee los datos del usuario y los almacena en un archivo temporal.
 */
void cargarDesdeUsuario(){
	ofstream entrenamiento("tmpentrenamiento.txt");
	ofstream red("tmpred.txt");
	string topologia_data;
	string pesos_nodos;
	string files;
	string conexiones;
	string caso;
	vector <unsigned> topologia;
	unsigned casos;
	char caracter_espacio=' ';
	cout<<"Introduzca la topologia del la red"<<endl;
	cin.ignore();
	getline(cin, topologia_data);
	cout << "la topologia ingresada es:"<< topologia_data<<endl;
	red << topologia_data<<endl;
	cout <<endl;
	cout<<"Introduzca los umbrales de los nodos intermedios, separados por espacios"<<endl;
	getline(cin, pesos_nodos);
	red<<pesos_nodos<<endl;
	topologia=toUnsigned(split(topologia_data, caracter_espacio));
    unsigned vertices = sumUnsignedVector(topologia);
    for (unsigned i=1; i<=vertices; i++){
    	cout << "Introduzca conexiones de el nodo "<<i<<endl;
    	getline(cin, conexiones);
    	red<<conexiones<<endl;
    }
    cout<<"Introduzca el numero de casos a probar: ";
    cin>>casos;
    cin.ignore();
    for (unsigned i=1; i<=casos; i++){
    	cout << "Introduzca los datos del caso "<<i<<endl;
    	getline(cin, caso);
    	entrenamiento<<caso<<endl;
    }
    entrenamiento.close();
    red.close();
	cout<<"Datos cargados!"<<endl;
}

/**
 * Fun
 * @param file_grafo
 * Nombre del archivo con descripcion del grafo
 * @param file_entrenamiento
 * Nombre del archivo con valores de entrada y salida esperados
 */
void procesar(string file_grafo, string file_entrenamiento){
	cout << "**************************CREANDO RED************************"<<endl;
	cout<<"Cargando red desde: "<<file_grafo<< ", cargando entrenamiento desde: "<<file_entrenamiento<<endl;
	vector< vector<double> > entradas;
	vector< vector<double> > salidas;
	vector<double> valoresResultado;
	vector <unsigned> topologia;
	DatosGrafo datosgrafo=DatosGrafo(file_grafo);
	topologia= datosgrafo.getTopologia();
	Grafo miGrafo=Grafo(datosgrafo);
	cout<<"Grafo creado exitosamente"<<endl;
	DatosEntrenamiento datosentrenamiento=DatosEntrenamiento(file_entrenamiento, topologia[0], topologia.back());
	datosgrafo.printAll();
	entradas=datosentrenamiento.getEntradas();
	salidas=datosentrenamiento.getSalidas();
	unsigned totalediciones=1;
	unsigned recorridos=0;
	bool recorrer=true;

	// Verifica el ciclo hasta que la red este entrenada con todo el archivo, verifica mediante el número de ediciones que se hizo del grafo
	while (totalediciones!=0 && recorrer){
		recorridos++;
		cout<<"Se está ejecutando el "<<recorridos<<" recorrido del archivo"<<endl;
		totalediciones=0;
		for (unsigned i=0; i<entradas.size(); i++) {
			cout << "**************************ENTRENANDO RED************************"<<endl;
			cout<<"CASO DE PRUEBA: "<<i+1<< "   Alimentando grafo con entradas: " ; printDoubleVector(entradas[i]);
			totalediciones+=miGrafo.entrenar(entradas[i], salidas[i]);
			cout << endl;
			cout<<"En total se tuvo que editar "<<totalediciones<< " veces el grafo"<<endl;
		}
		cout<<"***RECORRIDO #" << recorridos <<" TOMÓ "<< totalediciones << " EDICIONES ************" << endl;
		if (recorridos>100 or totalediciones==0){
			break;
		}
	}
	if (recorridos>100){
		cout<<"Fue imposible entrenar la red con las entradas y salidas dadas"<<endl;
	} else {
		cout<<"La red fue entrenada exitosamente!. Se realizaron en total "<<recorridos<<" recorridos al set de datos de entrenamiento"<<endl;
	}

}
int main(){
	//string file_grafo="TestData/dataNetSmall.txt";
	//string file_entrenamiento="TestData/EntrenamientoSmall.txt";
	bool continuar=true;
	char opcion=' ';
	string file_grafo="TestData/dataNetVerySmall.txt";
	string file_entrenamiento="TestData/OR.txt";
	while (continuar){
		cout<<"******MENU PRINCIPAL*************"<<endl;
		cout<<"Bienvenido a un simulacion de una red nuroal por medio de grafos"<<endl;
		cout<<"A) Cargar datos desde archivos"<<endl;
		cout<<"B) Cargar datos desde linea de comandos"<<endl;
		cout<<"C) Empezar entrenamiento"<<endl;
		cout<<"D) Usar datos por defecto"<<endl;
		cout<<"S) Salir"<<endl;
		cout<<"Ingrese opción deseada:";
		cin>>opcion;
		cout<<endl;
		switch(opcion){
		case 'A':{
			cout<<"Introduzca nombre de archivo que contiene la descripcion de la red:";
			cin>>file_grafo;
			cout<<endl;
			cout<<"Introduzca nombre de archivo de entrenamiento:";
			cin>>file_entrenamiento;
			cout<<endl;
			break; }
		case 'B': {
			cargarDesdeUsuario();
			file_entrenamiento="tmpentrenamiento.txt";
			file_grafo="tmpred.txt";
			break; }
		case 'C': {
			procesar(file_grafo, file_entrenamiento);
			break; }
		case 'D': {
			string file_grafo="TestData/dataNetVerySmall.txt";
			string file_entrenamiento="TestData/OR.txt";
			break;
		}
		case 'S':
			continuar=false;
			break;
		default:
			break;

		}

	}
}
