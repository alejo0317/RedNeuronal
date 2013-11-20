/*
 * DatosEntrenamiento.h
 *
 *  Created on: 16/11/2013
 *      Author: null3d
 */
#include "fstream"
#include <vector>
#include "FuncionesUtiles.h"
#ifndef DATOSENTRENAMIENTO_H_
#define DATOSENTRENAMIENTO_H_

using namespace std;
/*
 * Clase usada para cargar los datos del archivo de entrenamiento
 */
class DatosEntrenamiento{
	public:
	/**
	 * Constructor de la clase, asigna las entradas y salidas esperadas
	 * @param archivoentrenamiento
	 * Nombre del archivoque contiene los datos de entrenamiento
	 * @param variables_entrada
	 * Número de variables de entrada
	 * @param variables_salida
	 * Numero de variables de salida
	 */
		DatosEntrenamiento(string archivoentrenamiento, unsigned variables_entrada, unsigned variables_salida);
		/**
		 *
		 * @return
		 * Retorna un vector de vectores con los valores de las entradas
		 */
		vector< vector<double> > getEntradas(){return entradas;}
		/**
		 *
		 * @return
		 * Un vector de vectores con los valores de las salidas esperadas
		 */
		vector< vector<double> > getSalidas(){return salidas;}
	private:
		vector< vector<double> > entradas;
		vector< vector<double> > salidas;
};


#endif /* DATOSENTRENAMIENTO_H_ */
