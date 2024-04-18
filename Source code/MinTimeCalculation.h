#pragma once
#include "common.h"
class MinTimeCalculation
{
public:
	double distance(int x1, int y1, int x2, int y2); 
    vector<double> minTimeToDestination(const vector<vector<waypointInfo>>& input); 
private:
	double greedyDp(const vector<waypointInfo>& waypoints);
	double dijkstra(const vector<waypointInfo>& waypoints);
};

