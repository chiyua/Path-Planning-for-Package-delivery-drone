#include "filehandling.h"

vector<vector<waypointInfo>> FileHandling::parseData(const char* filename)
{
    waypointInfo info;
    ifstream inputFile(filename);
    vector<waypointInfo> values;
    vector<vector<waypointInfo>> parsedData;
    if (!inputFile) {
        cerr << "Error: Unable to open input file." << endl;
        return parsedData;
    }
    while (true) {
        values.clear();
        string line;
        getline(inputFile, line);
        int num;
        istringstream temp_str(line);
        temp_str >> num;
        if (num == 0) {
            break;
        }
        else {
            int count = 0;
            info.coordinate_x = START_X;
            info.coordinate_y = START_Y;
            info.penalty = START_PENALTY;
            values.push_back(info);
            while (count++ < num) {
                getline(inputFile, line);
                istringstream iss(line);
                int val;
                iss >> val;
                info.coordinate_x = val;
                iss >> val;
                info.coordinate_y = val;
                iss >> val;
                info.penalty = val;
                values.push_back(info);               
            }
            info.coordinate_x = END_X;
            info.coordinate_y = END_Y;
            info.penalty = END_PENALTY;
            values.push_back(info);
        }
        parsedData.push_back(values);
    }
    inputFile.close();
    cout << filename<<" reading completed." << endl;
    return parsedData;
}

double FileHandling::roundToThreeDecimalPlaces(double num)
{
    return round(num * 1000.0) / 1000.0;
}

void FileHandling::saveData(vector<double> result, const char* output_filename)
{
    ofstream outputFile(output_filename);
    if (!outputFile) {
        cerr << "Error: Unable to open output file." << endl;
        return;
    }
    for (int i = 0; i < result.size(); i++) {
        outputFile << std::setprecision(9)<< roundToThreeDecimalPlaces(result[i]) << endl;
    }
    outputFile.close();
    cout << "Results written to output.txt" << endl;
}


