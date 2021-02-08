#include <iostream>
#include "shapefil.h"
#include <iomanip>
#include <exception>
#include <string>
#include <GeographicLib/UTMUPS.hpp>

using namespace std;
using namespace GeographicLib;

int main()
{
	double x_coords[10];
	double y_coords[10];
	int nr_of_ent;
	int shapetype;
	double pad_of_min_bound;
	double pad_of_max_bound;
	
	SHPHandle a = SHPOpen("harvest\\harvest", "rb");
	SHPGetInfo(a, &nr_of_ent, &shapetype, NULL, NULL);

	SHPObject* ob = SHPReadObject(a, 2);

	int n_vertices = ob->nVertices;

	for(int i = 0; i < n_vertices; i++)
	{
		x_coords[i] = *((ob->padfX) + i);
		y_coords[i] = *((ob->padfY) + i);
	}

	cout << "----- LL2UTM and UTM2LL ------- " << endl;
	// Sample forward calculation
	double lat = 33.3, lon = 44.4; // Baghdad
	int zone;
	bool northp;
	double x_utm = 0;
	double y_utm = 0;
	UTMUPS::Forward(lat, lon, zone, northp, x_utm, y_utm);
	string zonestr = UTMUPS::EncodeZone(zone, northp);
	cout << fixed << setprecision(2) << x_utm <<" "<< y_utm <<endl;
	
	//close the shapefile & Destroy the SHP object
	SHPClose(a);
	SHPDestroyObject(ob);

	cout << "--- END ---";
}