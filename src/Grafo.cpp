/*
 * Grafo.cpp
 *
 *  Created on: 16/11/2013
 *      Author: null3d
 */
#include "Grafo.h"

void Grafo::obtenerResultados(vector<double> &resultValues) const{
        resultValues.clear();
        Capa ultima_capa=m_capas[m_capas.size()-1];
       // cout << "El tamaño de la ultima capa es:" << ultima_capa.size();
    for (unsigned n = 0; n <= ultima_capa.size() - 1; n++) {
    	//cout<<"Explorando capa: "<< m_capas.back().size() - 1 << "nodo " <<n<<endl;
    	//cout<< "Explorando ultima capa, nodo: "<<n<<endl;
        resultValues.push_back(ultima_capa[n].getValorSalida());
    }
}

vector<double> Grafo::getResultados(){
	vector<double>  retorno;
	 for (unsigned n = 0; n < m_capas.back().size() - 1; n++) {
        retorno.push_back(m_capas.back()[n].getValorSalida());
	}
   return retorno;

}


void Grafo::alimentar(const vector<double> &valoresEntrada){
	assert(valoresEntrada.size() == m_capas[0].size()); // 30:30 -1 indica el bias, assert termina el programa si una condición no se cumple
	// Asigna los valores de entrada a los nodos de entrada
	//cout<<"El valor de las entradas del grafo es: " ;
	for (unsigned i=0; i < valoresEntrada.size(); ++i) {
		m_capas[0][i].setValorSalida(valoresEntrada[i]);// 0 es la capa de entrada
		//cout<<valoresEntrada[i]<< " ";
		}
	//cout<<endl;

	// Realiza la propagacion de resultado,
	for (unsigned numero_capa=1; numero_capa < m_capas.size(); ++numero_capa) {
		//cout<<"Alimentando capa: "<<numero_capa<<endl;
		Capa &capaPrevia = m_capas[numero_capa -1 ]; // el & se usa para que sea mas rápido
		for (unsigned n=0; n< m_capas[numero_capa].size(); ++n) {
			m_capas[numero_capa][n].alimentar(capaPrevia);
			}

	}
}

unsigned Grafo::entrenar (vector<double> entradas, const vector<double> &valoresEsperados){
	// Calcular el valor de error
	// Usando al cuadrado (asumiendo mas de una conexion)
	vector <double> valoresResultado;
	obtenerResultados(valoresResultado);
	unsigned intentos=0;
	unsigned totaliteraciones=0;
	//Reviso si conciden los valores o si ya se hicieron 200 intentos
	while (intentos<100){
		alimentar(entradas);
		cout<<"*********************************************************"<<endl;
		cout<<"Iteración: "<<intentos<<endl;
		cout<<"*********************************************************"<<endl;
		Capa &capaSalida = 	m_capas.back();
		// Calculo error
		double error = 0;
		unsigned numero_de_salidas=valoresEsperados.size();
		switch (numero_de_salidas) {
			case 1: // Si solo hya una salida esta es la formula del error
				error=valoresEsperados[0]-capaSalida[0].getValorSalida();
				break;
			default: // Si hay mas de dos salidas esta es la formula
				for (unsigned i=0; i<valoresEsperados.size(); i++) {
					error+=pow((valoresEsperados[i]-capaSalida[i].getValorSalida()),2);
				}
				error=0.5*sqrt(error);
		}obtenerResultados(valoresResultado);
		cout << "Las salidas esperadas son: " ;
		printDoubleVector(valoresEsperados);
		cout<< "Las salidas resultantes son: ";
		printDoubleVector(valoresResultado);
		cout<<"El error es: "<<error <<endl;
		obtenerResultados(valoresResultado);
		if (intentos!=0){
		totaliteraciones++;
		}
		intentos++;
		if (error!=0) {
			for (unsigned  numero_capa= m_capas.size()-1; numero_capa>0; numero_capa--) {
				Capa &capa = m_capas[numero_capa];
				Capa &capa_anterior=m_capas[numero_capa-1];
				for (unsigned n=0; n<capa.size(); n++){
					cout<<"Peso anterior: "<< capa[n].getB() <<endl;
					capa[n].setB(-capa[n].getB()+error);
					cout<< "Peso actualizado :"<<capa[n].getB()<<endl;
				}
			}
			for (unsigned numero_capa=0; numero_capa<m_capas.size()-1; numero_capa++){
				Capa &capa=m_capas[numero_capa];
				for (unsigned n=0; n<capa.size(); n++){
					//cout<<"Antiguas salidas: ";
					//printAristasVector(capa[n].getPesosSalida());
					Arista tmp_arista=Arista(0);
					cout << "Pesos aristas anteriores: " ;
					printAristasVector(capa[n].getPesosSalida());

					for (unsigned s_n=0; s_n<capa[n].getPesosSalida().size(); s_n++) {
						cout<<"Cambiando pesos aristas capa "<<n<<endl;
						if (capa[n].getPesosSalida()[s_n].w == 0) {
							tmp_arista=Arista(0);
							capa[n].setPesoSalida(s_n, tmp_arista);
						}
						double nuevoPesoSalida=capa[n].getPesosSalida()[s_n].w + (capa[n].getValorSalida()*error);
						tmp_arista=Arista(nuevoPesoSalida);
						capa[n].setPesoSalida(s_n, tmp_arista);
					}

					cout << "Pesos aristas nuevos: ";
					printAristasVector(capa[n].getPesosSalida());
					//cout <<endl;
				}
			}

		}

		obtenerResultados(valoresResultado);
		if (valoresEsperados==valoresResultado){
			cout<<"Solución encontrada"<<endl;
			unsigned intentos=0;
			break;
		}
	}
	return totaliteraciones;

}
//Constructor Grafo
Grafo::Grafo (DatosGrafo datos){

	vector <unsigned> topologia=datos.getTopologia();
	vector <double> pesosNodos=datos.getPesosVertices();
	vector <Columna> pesosAristas=datos.getDescripcion();
	unsigned numero_capas=topologia.size();
	double peso=0;
	unsigned contador_nodo_general=0;
	for (unsigned numero_capa = 0; numero_capa < numero_capas; numero_capa++) {
		//cout<<"Creando capa "<<numero_capa <<endl;
		m_capas.push_back(Capa());
		unsigned numeroSalidas = numero_capa == topologia.size() -1 ? 0 : topologia [numero_capa + 1]; // Numero de salidas (aristas de salida) a las que estará conectado cada nodo
		unsigned indice_siguiente_capa=sumUnsignedVector(subVectorUnsigned(topologia, 0, numero_capa+1));
		//cout<<"Modificado indice siguiente capa "<<indice_siguiente_capa<<endl;
		unsigned fin_siguiente_capa=indice_siguiente_capa+topologia[numero_capa+1];
		for (unsigned numero_nodo=0; numero_nodo < topologia[numero_capa]; numero_nodo++) {
				vector <double>pesos_conexiones_capas;
			if (numero_capa==0){
				pesos_conexiones_capas=subVectorDouble(pesosAristas[contador_nodo_general], indice_siguiente_capa, fin_siguiente_capa);
				m_capas.back().push_back(Nodo(numeroSalidas, numero_nodo, 0, pesos_conexiones_capas)); // En el caso que sea la capa inicial (entrada) se dejan los varloes en 0
				}
			else if (numero_capa==topologia.size() -1) {
				vector<double> basura;
				peso=pesosNodos[contador_nodo_general-topologia[0]];
				m_capas.back().push_back(Nodo(0, numero_nodo, peso, basura));
			}
			else {
				pesos_conexiones_capas=subVectorDouble(pesosAristas[contador_nodo_general], indice_siguiente_capa, fin_siguiente_capa);
				peso=pesosNodos[contador_nodo_general-topologia[0]];
				m_capas.back().push_back(Nodo(numeroSalidas, numero_nodo, peso, pesos_conexiones_capas)); // Retorna la referencia del último elemento en  el vector
			}
			//cout<< "Se agrego un nodo "<< numero_nodo << " con " << numeroSalidas << " de salidas, peso: "<<peso<<" en la capa: " << numero_capa << "que tiene un tamaño de " << m_capas.back().size()<<endl; //" y con valores de salida de aristas: " <<endl;
			//printDoubleVector(pesos_conexiones_capas);
			//printDoubleVector(pesosAristas[contador_nodo_general]);
			contador_nodo_general++;


		}

	}
}



