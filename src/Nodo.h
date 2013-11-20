#include <vector>
#include "Arista.h"
//#include "Capa.h"
#include "FuncionesUtiles.h"

class Nodo;

typedef vector<Nodo> Capa; // Sure??

using namespace std;

class Nodo{
	public:
	/**
	 * Constructor clase nodo
	 * @param numeroSalidas
	 * Numero de salidas del nodo, (tamano de la siguiente capa)
	 * @param miindice
	 * Identificador del nodo
	 * @param peso
	 * Peso o umbral del nodo
	 * @param pesosAristas
	 * Peso de cada arista que sale del nodo
	 */
		Nodo(unsigned numeroSalidas , unsigned miindice, double peso, vector<double> pesosAristas);
	/**
	 * Un set para el valor de salida
	 * @param valor
	 * valor a asignar
	 */
		void setValorSalida(double valor);
	/**
	 * Obtener el valor de salida del nodo
	 * @return
	 */
		double  getValorSalida() const;
	/**
	 * Alimenta el nodo a partir de la capa previa
	 * @param capaPrevia
	 */
		void alimentar(const Capa &capaPrevia);
	/**
	 * Asigna el valor del umbral
	 * @param b
	 */
		void setB(double b){this->b=b;}; // Setear valor de B
	/**
	 * Obtiene el valor del umbral
	 * @return
	 */
		double getB() {return b;}
	/**
	 * Obtiene un vector de Aristas con sus salidas.
	 * @return
	 */
		vector<Arista> getPesosSalida(){return this->m_PesosSalida;}
	/**
	 * Asigna el peso de salida.
	 * @param indice
	 * @param arista
	 */

		void setPesoSalida(unsigned indice, Arista arista){this->m_PesosSalida[indice]=arista;};
	private:
		double m_valorSalida;
		vector<Arista> m_PesosSalida; // Creoo que es los valores de las aristas Connection weights
		double b;
		unsigned m_miindice;
	};
