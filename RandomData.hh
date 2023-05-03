// RandomData.hh


// Created by Fabio Pandolfi 20:52 21/10/2020

#ifndef RandomData_hh
#define RandomData_hh

#include <iostream>
#include <cstdlib>
#include <fstream>
#include "Datum.hh"

class RandomData {
public:

    static bool randomData(const int& nData, std::ofstream& file);
};

#endif /* RandomData_hh */