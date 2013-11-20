/*
 * Arista.h
 *
 *  Created on: 15/11/2013
 *      Author: null3d
 */

#ifndef ARISTA_H_
#define ARISTA_H_

/**
 * Clase Arista, también conocida como conexion, se encarga de conectar dos nodos, solo tiene 1 variable (w) que corresponde al peso de la arista.
 */
struct Arista{
	public:
	/**
	 *Asigna la variable valor a la variable w de la conexion
	 * @param valor
	 * Peso nuevo de la arista
	 */
		void setW(double valor) {w=valor;};
	/**
	 *Constructor de arista
	 * @param w
	 * Peso de la arista
	 */
		Arista(double w);
	/**
	 * Variable que almacena el peso
	 */
		double w;
	/**
	 * Retorna el peso de la arista
	 *
	 */
		double getW() {return w;};

	};

#endif /* ARISTA_H_ */
