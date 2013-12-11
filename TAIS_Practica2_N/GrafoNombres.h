/********************************************************************************
*																				*
*		Practica 2 TAIS - ORACLE OF BACON										*
*		Autor:			Juan Luis Perez Valbuena	                 			*
*																				*
*********************************************************************************/

#pragma once

#include <iostream>
#include "Tabla.h"
#include "Grafo.h"
#include "SplitString.h"
#include <fstream>


typedef unsigned int uint;

class GrafoNombres
{

private:

	Tabla<string, uint> tn; // string -> index
	string* nombres; // index -> string
	Grafo* _G; // grafo con vértices numerados


public:
	GrafoNombres(string filename, string delimiter)
	{
		string linea;
		string *pelicula;
		string p;
		int tam_grafo=0,num_actores,  indice=0, indice_aux=0 , indice_peli=0;

		std::ifstream file(filename);
		while(std::getline(file,linea))
		{
			pelicula = split(linea,delimiter,num_actores);
			for(int i=0; i < num_actores ; i++)
			{
				if(!tn.esta(pelicula[i]))
				{
					tn.inserta(pelicula[i],indice);
					indice ++;
				}
			}
			delete []pelicula;

		}

		_G = new Grafo(indice);
		nombres= new string[indice]();

		file.close();
		file.open(filename);

		while(std::getline(file,linea))
		{
			pelicula = split(linea,delimiter,num_actores);
			indice_peli=tn.consulta(pelicula[0]);
			nombres[indice_peli] = pelicula[0];

			for(int i=1; i < num_actores ; i++)
			{
				indice_aux=tn.consulta(pelicula[i]);
				nombres[indice_aux] = pelicula[i];
				_G->ponArista(indice_aux,indice_peli);
			}
			delete []pelicula;
		}

		std::cout <<  "Se cargaron " << indice << " actores/peliculas" << std::endl ;
		file.close();

	}
	~GrafoNombres()
	{
		delete _G;
		delete []nombres;

	}
	bool contiene(string s) const; // existe un vértice de nombre s?
	int indice(string s) const ;// devuelve el número asociado al vértice s
	const string& nombre(int v) const; // devuelve el nombre asociado al número v
	Grafo& G() const; // devuelve el grafo de números
};


