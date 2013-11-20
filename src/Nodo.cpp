/*
 * Nodo.cpp
 *
 *  Created on: 15/11/2013
 *      Author: null3d
 */
#include "Nodo.h"


Nodo::Nodo(unsigned numeroSalidas , unsigned miindice, double peso, vector<double> pesosAristas){
	b=peso;
	for (unsigned c=0; c<numeroSalidas; ++c) {
		m_PesosSalida.push_back(Arista(pesosAristas[c])); // Inicializa las aristas que salen de la neurona
		//m_PesosSalida.back().w = randomW(); eliminado el randomw
		}
	this->m_miindice = miindice;
	m_valorSalida=0;
	};

double Nodo::getValorSalida() const{
	return this->m_valorSalida;
}

void Nodo::alimentar(const Capa &capaPrevia) {
	double suma=0.0;


	// Easy way: Crear conexiones entre todas y luego poner un condicional que verifica si realmente hay una conexión ahí

	// Suma las salidas de la capa anterior
	// Revisa todos los nodos y sus correspondientes salidas de la capa previa

	for (unsigned n=0; n<capaPrevia.size(); ++n){
		suma+= capaPrevia[n].getValorSalida() * capaPrevia[n].m_PesosSalida[m_miindice].w ; // Salida f=Sumatoria (i_i * w_i)
		}

	suma-=this->b; // No estoy seguro de esto
	m_valorSalida =  (suma>= 0) ? 1 : 0;
	cout<<"Valor salida nodo: "<< this->m_valorSalida << " , valor suma: "<< suma << " valor nodo:  " <<  this->b <<endl;
	}

void Nodo::setValorSalida(double valor) {
	m_valorSalida=valor;
	}

