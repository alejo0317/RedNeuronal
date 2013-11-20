/*
 * FuncionesUtiles.h
 *
 *  Created on: 15/11/2013
 *      Author: null3d
 */
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "Arista.h"
#ifndef FUNCIONESUTILES_H_
#define FUNCIONESUTILES_H_
/**
 * @brief
 * Varias funciones que facilitan el trabajo para todo el programa
 */
using namespace std;
#pragma once
/**
 * Imprime los valores (pesos de conexiones) de una lista de aristas
 * @param aristas
 * Vector de aristas
 */
void printAristasVector(vector<Arista> aristas);
/**
 * Obtiene un subvector de double a partir de un vector de entrada
 * @param entrada
 * @param primero
 * @param ultimo
 * @return
 */
vector<double> subVectorDouble(vector<double> entrada, unsigned primero, unsigned ultimo);
/**
 * Obtiene un subvector de unsigned a partir de un vector de entrada
 * @param entrada
 * @param primero
 * @param ultimo
 * @return
 */
vector <unsigned> subVectorUnsigned(vector<unsigned> entrada, unsigned primero, unsigned ultimo);
/**
 * Crea un vector de 0s.
 * @param size
 * Tamaño del vector
 * @return
 */
vector<double> createZeroVector(unsigned size)	;
/**
 * Parte una cadena a partir de un delimitador
 * @param s
 * Cadena de texto
 * @param delim
 * Caracter delimitador
 * @return
 * Vector con cadenas de texto
 */
std::vector<string> split(string s, char delim);
/**
 * Convierte un vector de cadenas de texto a un vector de enteros sin signo
 * @param data
 * Vector de cadenas de texto
 * @return
 * Vector de números sin signo
 */
vector<unsigned> toUnsigned (vector<string> data);
/**
 * Convierte un vector de strings a un vector de doubles
 * @param data
 * Vector de strings
 * @return
 * Vector de doubles
 */
vector<double> toDouble (vector<string> data);
/**
 * Suma los números de un vector de números sin signo
 * @param datos
 * Vector de numeros sin signo
 */
unsigned sumUnsignedVector(vector<unsigned> datos);
double sumDoubleVector(vector<double> datos);
void printUnsignedVector(vector<unsigned> datos);
void printDoubleVector(vector<double> datos);
unsigned sumdata(vector<unsigned> datos);
#endif /* FUNCIONESUTILES_H_ */
