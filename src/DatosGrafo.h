/*
 * DatosGrafo.h
 *
 *  Created on: 15/11/2013
 *      Author: null3d
 */
#include <vector>
#include <iostream> // Para Cout
#include <cstdlib>
#include <cassert> // FUNCION C ASSE
#include <string>
#include "iostream" // PARA MANEJO DE ARCHIVOS
#include "fstream"
#include "cmath"
#include <sstream>
#include "Columna.h"
#include "FuncionesUtiles.h"
#include "FuncionesUtiles.h"

#ifndef DATOSGRAFO_H_
#define DATOSGRAFO_H_
//CARGA DATOS DE GRAFO DESDE ARCHIVO
/**
 * Esta clase almacena los datos de la estructura del grafo.
 */
class DatosGrafo{

	public:
	/**
	 *
	 * @return
	 * Vector con la topologia de la red
	 */
		vector<unsigned> getTopologia(){return topologia;}
	/**
	 * Crea objeto con información de la estructura del grago
	 * @param file_grafo
	 * Nombre del archivo que contiene la estructura del grafo
	 */
		DatosGrafo(string file_grafo);
	/**
	 *
	 * @return
	 *  Retorna los pesos de todas las aristas del grafo que fueron leídas desde el archivo de entrada
	 */
		vector< Columna > getDescripcion() {return descripcion;}
	/**
	 * Imprime la información de la estructura del grafo
	 */
		void printAll();
	/**
	 *
	 * @return
	 * Obtiene el peso o umbral de los nodos o vertices
	 */
		vector <double> getPesosVertices() {return pesosVertices;}
	private:
		vector<unsigned> topologia;
		vector< Columna> descripcion;
		vector <double> pesosVertices;

	};

#endif /* DATOSGRAFO_H_ */

