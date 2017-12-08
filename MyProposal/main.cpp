#include <iostream>
#include <fstream>
#include "CsvLector.h"
#include "CNode.h"
#include <string>

using namespace std;


int main() {
    //string name = "files/YearPredictionMSD.txt";
    string name = "files/Year100.txt";
    ifstream file(name);
    auto allRegisters = readCSV(file, false);
    
    for(int i =0;i<10;i++){
        ///allRegisters[registro][columna]
        cout<<allRegisters[i][0]<<"["<<i<<"]";
    }
    //cout<<comparePoints(allRegisters[8],allRegisters[9],0);  
    
}
