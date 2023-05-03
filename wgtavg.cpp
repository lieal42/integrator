// wgtavg.cpp

#include <vector>
#include <iostream>
#include <fstream>
#include "Datum.hh" // basic data object
#include "InputService.hh" // class dedicated to handle input of data 
#include "Calculator.hh" // impelments various algorithms
using std::cout;
using std::endl;
int main() {

    std::ifstream fp("/Users/fabio/computing_methods/data_file.dat");

    std::vector<Datum> dati = InputService::readDataFromUser(fp);
    Datum r1 = Calculator::weightedAverage(dati);
    cout << "weighted average : " << r1 << endl;
    Datum r2 = Calculator::arithmeticAverage(dati);
    return 0;
}