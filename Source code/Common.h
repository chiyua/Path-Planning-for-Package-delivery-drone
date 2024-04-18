#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <math.h>
#include <cmath>
#include <queue>
#include <iomanip>

using namespace std;

const double UAV_SPEED = 2.0; // meters per second
const double STOP_TIME = 10.0; // seconds
const int END_X = 100;//meters
const int END_Y = 100;//meters
const int END_PENALTY = 0;
const int START_X = 0;//meters
const int START_Y = 0;//meters
const int START_PENALTY = 0;

struct waypointInfo {
    int coordinate_x;
    int coordinate_y;
    int penalty;
};

struct Node {
    int index;
    double time;
    Node(int i, double t) : index(i), time(t) {}
    bool operator<(const Node& other) const {
        return time > other.time; // priority queue is a min heap
    }
};