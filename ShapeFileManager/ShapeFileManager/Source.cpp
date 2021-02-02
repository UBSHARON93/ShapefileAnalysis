#include <iostream>
#include "shapefil.h"

int main()
{
	double *x_coords;
	x_coords = new double[10];
	double *y_coords;
	y_coords = new double[10];

	int* nr_of_ent;
	nr_of_ent = new int;

	int* shapetype;
	shapetype = new int;

	double* pad_of_min_bound;
	pad_of_min_bound = new double;

	double *pad_of_max_bound;
	pad_of_max_bound = new double;

	SHPHandle a = SHPOpen("harvest\\harvest", "rb");
	SHPGetInfo(a, nr_of_ent, shapetype, pad_of_min_bound, pad_of_max_bound);

	SHPObject* ob = SHPReadObject(a, 2);

	int n_vertices = ob->nVertices;

	for(int i = 0; i < n_vertices; i++)
	{
	   //*(x_coords[i]+1) = *((ob->padfX)+1);
		x_coords[i] = *((ob->padfX) + i);
		y_coords[i] = *((ob->padfY) + i);
	}
	

	std::cout << "working";
}