/*
 * FuncionesUtiles.cpp
 *
 *  Created on: 15/11/2013
 *      Author: null3d
 */

#include "FuncionesUtiles.h"


/**
 * Obtiene un subvector de números a partir de un vector dado
 * @param entrada
 * @param primero
 * @param ultimo
 * @return
 */
vector<double> subVectorDouble(vector<double> entrada, unsigned primero, unsigned ultimo){
	vector<double> retorno;
	for (unsigned i=primero; i<ultimo; i++) {
		retorno.push_back(entrada[i]);
		}
	return retorno;
	}
vector <unsigned> subVectorUnsigned(vector<unsigned> entrada, unsigned primero, unsigned ultimo) {
	vector<unsigned> retorno;
	for (unsigned i=primero; i<ultimo; i++) {
		retorno.push_back(entrada[i]);
		}
	return retorno;

}
vector<double> createZeroVector(unsigned size){
	vector<double> retorno;
	for (unsigned i; i < size; i++){
		retorno.push_back(0);
	}
	return retorno;

}

std::vector<string> split(string s, char delim) {
    std::stringstream ss(s);
    string item;
    vector<string> elems;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}
vector<unsigned> toUnsigned (vector<string> data){
	vector <unsigned> retorno;
	unsigned tmp;
	for (unsigned i=0; i<data.size(); ++i) {
		std::istringstream reader(data[i]);
		reader>>tmp;
		retorno.push_back(tmp);
		}
	return retorno;
	}
vector<double> toDouble (vector<string> data){
	vector <double> retorno;
	double tmp;
	for (unsigned i=0; i<data.size(); ++i) {
		std::istringstream reader(data[i]);
		reader>>tmp;
		retorno.push_back(tmp);
		}
	return retorno;
	}
unsigned sumUnsignedVector(vector<unsigned> datos) {
	unsigned suma=0;
	for (unsigned i=0; i<datos.size();i++) {
		suma+=datos[i];
		}
	return suma;

	}
double sumDoubleVector(vector<double> datos) {
	double suma=0;
	for (unsigned i=0; i<datos.size();i++) {
		suma+=datos[i];
		}
	return suma;
	}
void printUnsignedVector(vector<unsigned> datos){
	for (unsigned i=0; i<datos.size();i++) {
		cout << datos[i] << " ";
	}
	cout << endl;
}
void printDoubleVector(vector<double> datos){
	for (unsigned i=0; i<datos.size();i++) {
		cout << datos[i] << " ";
	}
	cout << endl;
}
void printAristasVector(vector<Arista> aristas){
	for (unsigned i=0; i<aristas.size(); i++){
		cout << aristas[i].w << " ";
	};
}
