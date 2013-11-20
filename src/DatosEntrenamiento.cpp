/*
 * DatosEntrenamiento.cpp
 *
 *  Created on: 16/11/2013
 *      Author: null3d
 */


#include "DatosEntrenamiento.h"

DatosEntrenamiento::DatosEntrenamiento(string archivoentrenamiento, unsigned variables_entrada, unsigned variables_salida){
	ifstream in(archivoentrenamiento.c_str());
	string linea;
	vector <double> temporal;
	char caracter_espacio=' ';
	while (getline (in, linea)) {
		temporal=toDouble (split(linea, caracter_espacio));
		entradas.push_back(subVectorDouble(temporal, 0, variables_entrada));
	//	printDoubleVector(entradas.back());
	//	cout<<endl;
		salidas.push_back(subVectorDouble(temporal,variables_entrada, variables_entrada+variables_salida));
	}
};
