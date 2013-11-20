/*
 * DatosGrafo.cpp
 *
 *  Created on: 15/11/2013
 *      Author: null3d
 */

#include "DatosGrafo.h"


void DatosGrafo::printAll(){
	cout<<"El grafo se creó con los siguientes parámetros iniciales"<<endl;
	cout<<"Topologia: ";
	for (unsigned i=0; i<topologia.size(); i++){
		cout<< topologia[i]<<" ";
		}
	cout<<endl;
	cout<<"Pesos vertices";
	for (unsigned i=0; i<pesosVertices.size(); i++){
		cout<< pesosVertices[i]<<" ";
		}
	cout<<endl<<"Matriz de pesos"<<endl;
	for (unsigned y=0; y<descripcion.size(); y++){
		cout << endl;
		for (unsigned x=0; x<descripcion.back().size(); x++){
			cout << descripcion[y][x] << "\t";
		}
	}
	cout<<endl;
	}
DatosGrafo::DatosGrafo(string file_grafo){
  unsigned x, y; // Sumar topologia y obtener el valor de la matriz, para armar el grafo.
  ifstream in(file_grafo.c_str());
  // Carga datos de topologia y pesos de los nodos
  string topologia_data;
  string pesos_data;
  if (!in) {
    cout << "Cannot open file.\n";
    return;
  }
  getline(in, topologia_data);
  getline(in, pesos_data);
  char caracter_espacio=' ';
  topologia=toUnsigned(split(topologia_data, caracter_espacio));
  pesosVertices=toDouble (split(pesos_data, caracter_espacio));
  unsigned vertices = sumUnsignedVector(topologia);
  for (y = 0; y < vertices; y++) {
 	    descripcion.push_back(Columna());
    for (x = 0; x <vertices; x++) {
		double tmp;
		in >> tmp;
		descripcion.back().push_back(tmp);
    }
  }
  in.close();
	}
