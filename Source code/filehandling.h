#pragma once
#include "common.h"
class FileHandling
{
public:
	vector<vector<waypointInfo>> parseData(const char* filename);
	void saveData(vector<double> result, const char* output_filename);
	double roundToThreeDecimalPlaces(double num); 
};

