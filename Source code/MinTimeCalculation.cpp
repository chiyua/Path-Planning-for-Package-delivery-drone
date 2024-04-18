#include "MinTimeCalculation.h"

double MinTimeCalculation::distance(int x1, int y1, int x2, int y2)
{
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

vector<double> MinTimeCalculation::minTimeToDestination(const vector<vector<waypointInfo>>& input)
{
    vector<waypointInfo> waypoints;
    vector<double> results;
    for (int i = 0; i < input.size(); i++) {
        waypoints = input[i];
        results.push_back(greedyDp(waypoints));
        //results.push_back(dijkstra(waypoints));
    }
    return results;
}

double MinTimeCalculation::greedyDp(const vector<waypointInfo>& waypoints)
{
    int n = waypoints.size();
    double dTime = 0;
    double sum = 0;
    for (int i = 0; i < n - 1; ) {
        dTime = distance(waypoints[i].coordinate_x, waypoints[i].coordinate_y, waypoints[i + 1].coordinate_x, waypoints[i + 1].coordinate_y) / UAV_SPEED + STOP_TIME;
        //cout <<"dTime is: "<<dTime<<endl;

        double dPenaltyTime = 0;
        int nIndex = i;
        for (int j = i + 2; j < n; ++j) {
            dPenaltyTime += waypoints[j - 1].penalty;
            double dTimeSkip = distance(waypoints[i].coordinate_x, waypoints[i].coordinate_y, waypoints[j].coordinate_x, waypoints[j].coordinate_y) / UAV_SPEED + dPenaltyTime + STOP_TIME;
            //cout <<"Penalty time is: "<<dPenaltyTime<<endl;
            if (dTime > dTimeSkip) {
                dTime = dTimeSkip;
                nIndex = j;
            }
            // cout <<"dTimeSkip is: "<<dTimeSkip << endl;
        }

        i = (i == nIndex) ? ++i : nIndex;
        sum += dTime;
    }
    return sum;
}

double MinTimeCalculation::dijkstra(const vector<waypointInfo>& waypoints)
{
    int n = waypoints.size();
    vector<double> min_time(n, -1); // initialize all times to -1 (infinity)
    priority_queue<Node> pq;
    pq.push(Node(0, 0)); // start from the first waypoint
    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();
        int index = node.index;
        double time = node.time;
        if (min_time[index] != -1) continue; // if already visited, skip
        min_time[index] = time;
        for (int i = index + 1; i < n; ++i) {
            double d = distance(waypoints[index].coordinate_x, waypoints[index].coordinate_y, waypoints[i].coordinate_x, waypoints[i].coordinate_y);
            double penalty_time = 0.0;
            for (int j = index + 1; j < i; ++j) {
                penalty_time += waypoints[j].penalty;
            }
            double next_time = time + d / UAV_SPEED + STOP_TIME + penalty_time;
            pq.push(Node(i, next_time));
        }
    }
    return min_time[n - 1]; // time to reach the last waypoint
}
