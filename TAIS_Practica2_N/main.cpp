/********************************************************************************
*																				*
*		Practica 2 TAIS - ORACLE OF BACON										*
*		Autor:			Juan Luis Perez Valbuena	                 			*
*																				*
*********************************************************************************/



#include <iostream>
#include "Grafo.h"
#include "Tabla.h"
#include "GrafoNombres.h"


void GradoSeparacion(const string& origen);
void NumeroDeBacon(const string& actor);

using namespace std;

int main()

{
	string actor;
	std::cout << "Funcion Grado Separacion" << endl;

	std::cout << "Introduce actor origen:";
	getline(cin,actor);


	GradoSeparacion(actor);

	std::cout << "Funcion Numero de Bacon" << endl;

	std::cout << "Introduce actor origen:";
	getline(cin,actor);

	NumeroDeBacon(actor);



	std::cout << "Fin ej";

	string a ;

	std::cin >> a ;



	return 0;
}

void GradoSeparacion(const string& origen) {

	std::cout << "Cargando grafo de peliculas... " << std::endl;
	GrafoNombres pelis("movies.txt", "/");
	if(pelis.contiene(origen))
	{
		unsigned int vorigen = pelis.indice(origen);
		BreadthFirstPaths bfs(pelis.G(),vorigen);
		string actordestino;
		std::cout << "Escribe actor destino:" ;
		std::getline(std::cin,actordestino);
		while(actordestino !="")
		{
			if(pelis.contiene(actordestino))
			{
				int vdestino = pelis.indice(actordestino);

				if(bfs.hasPathTo(vdestino))
				{
					std::cout << pelis.nombre(vdestino) <<  " tiene un número de Bacon de "<<  bfs.distance(vdestino) / 2 << std::endl;
					Lista<uint> resultado = bfs.pathTo(vdestino);
					Lista<uint>::Iterador it = resultado.principio();
					bool actor=true;
					while(it != resultado.final())
					{
						uint v = it.elem();

						std::cout << pelis.nombre(v) << std::endl;
						if(it.elem() != vdestino) 
						{if (actor) {
							std::cout << "\twas in" << std::endl;
							actor=!actor;
						}
						else
						{
							std::cout << "\twith" << std::endl;
							actor=!actor;
						}
						}
						it.avanza();
					}
				}	else
				{
					std::cout << "No existe una conexion entre '" << origen << "' y '" << actordestino << "'" << std::endl; 
				}
			}
			else{
				std::cout << "El actor '" << actordestino << "' no se encuentra en nuestra base de datos" << std::endl;
			}
			std::cout << "Escribe actor destino:" ;
			std::getline(std::cin,actordestino);
		}
	}
	else 
	{
		std::cout << "El actor '" << origen << "' no se encuentra en nuestra base de datos" << std::endl;
	}

}

void NumeroDeBacon(const string& actor)
{
	std::cout << "Cargando grafo de peliculas... " << std::endl;
	GrafoNombres pelis("movies.txt", "/");
	if(pelis.contiene(actor))
	{
		int vorigen = pelis.indice(actor);
		BreadthFirstPaths bfs(pelis.G(),vorigen);

		int v[11];
		for(int k=0; k < 11; k++)
			v[k]=0;
		for(uint i=0; i < pelis.G().V() ; i++)
		{
			uint bacon = bfs.distance(i);
			if(bacon % 2 ==0 && bfs.hasPathTo(i))//Son actores y no peliculas.
			{
				bacon/=2;
				v[bacon]++;
			}
		}

		std::cout << "Origen: " << pelis.nombre(vorigen) <<std::endl; 
		std::cout << "Numero" << "\t" << "# de actores" <<std::endl; 
		for(int i=0; i < 11 ; i++)
		{
			std::cout << i << "\t" << v[i] <<std::endl; 
		}

	}

}