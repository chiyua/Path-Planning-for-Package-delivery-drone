#include "common.h"
#include "filehandling.h"
#include "MinTimeCalculation.h"


int main() {
    FileHandling file_obj;
    MinTimeCalculation cal_obj;
    vector<vector<waypointInfo>> temp;
    temp=file_obj.parseData("input.txt");
    file_obj.saveData(cal_obj.minTimeToDestination(temp), "output.txt");
    cout << "Press 'Enter' to quit" << endl;
    getchar();
    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

