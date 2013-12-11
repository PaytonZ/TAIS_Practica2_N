/********************************************************************************
*																				*
*		Practica 2 TAIS - ORACLE OF BACON										*
*		Autor:			Juan Luis Perez Valbuena	                 			*
*																				*
*********************************************************************************/

#include "GrafoNombres.h"


// existe un v�rtice de nombre s?
bool GrafoNombres::contiene(string s) const
{
	return tn.esta(s);
}
// devuelve el n�mero asociado al v�rtice s
int GrafoNombres::indice(string s) const
{
	return tn.consulta(s);
}
// devuelve el nombre asociado al n�mero v
const string& GrafoNombres::nombre(int v) const
{
	return nombres[v];
}
// devuelve el grafo de n�meros
Grafo& GrafoNombres::G() const
{
	return *_G;
}