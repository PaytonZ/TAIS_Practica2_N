/********************************************************************************
*																				*
*		Practica 2 TAIS - ORACLE OF BACON										*
*		Autor:			Juan Luis Perez Valbuena	                 			*
*																				*
*********************************************************************************/

#include "GrafoNombres.h"


// existe un vértice de nombre s?
bool GrafoNombres::contiene(string s) const
{
	return tn.esta(s);
}
// devuelve el número asociado al vértice s
int GrafoNombres::indice(string s) const
{
	return tn.consulta(s);
}
// devuelve el nombre asociado al número v
const string& GrafoNombres::nombre(int v) const
{
	return nombres[v];
}
// devuelve el grafo de números
Grafo& GrafoNombres::G() const
{
	return *_G;
}