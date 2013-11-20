/*
 * Grafo.h
 *
 *  Created on: 16/11/2013
 *      Author: null3d
 */
#include <vector>
#include "Capa.h"
#include <cassert>
#include "FuncionesUtiles.h"
#include "DatosGrafo.h"


#ifndef GRAFO_H_
#define GRAFO_H_

/**
 * Clase grafo que define toda la estructura de la RED.
 */
class Grafo
{
	public:
		/**
		 * El constructor de la clase Grafo recibe como parámetros un objeto de tipo
		 * DatosGrafo que contiene la información necesaria para crear el grafo
		 */
		Grafo (DatosGrafo datos);
		/**
		 * Esta función se encarga de introducir los datos de entrada al grafo, también hace la propagación de los nuevos valores.
		 * @param valoresEntrada
		 * Vector con números double de entrada al grafo
		 *
		 */
		void alimentar(const vector<double> &valoresEntrada) ;
		/**
		 * Funcion que se encarga del entrenamiento
		 * Recibe las entradas del grafo y se encarga de modificar el grafo hasta que se adapte a esos valores
		 * @param entradas
		 * Entradas del archivo de entrenamieto
		 * @param valoresEsperados
		 * Salidas esperadas
		 * @return
		 * Numero de ediciones que fueron necesarias en la red para esa entrada

		 */
		unsigned entrenar(vector<double> entradas,const vector<double> &valoresEsperados) ;
		/**
		 * Obtiene los valores de salida de la red
		 * @param valoresResultado
		 * Una direccion donde almacenar los valores de salida
		 */
		void obtenerResultados( vector<double> &valoresResultado) const ;
		/**
		 *Función que obtiene los resultados pero los almacena en un vector de doubles.
		 * @return
		 * Vector con los resultados (doubles)
		 */
		vector <double> getResultados();
		/**
		 * Sobrecarga del constructor del grafo
		 */
		Grafo();

	private:
		/**
		 * Vector que contiene todas las capas del grafo
		 */
		vector<Capa> m_capas; // m_capas[numero_capa][numero nodo]
		/**
		 * Variable que almacena el error actual del grafo
		 */
		double error;


};


#endif /* GRAFO_H_ */
