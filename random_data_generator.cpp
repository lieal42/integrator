// random_data_generator.cpp

#include "RandomData.hh"
#include <iostream>

int main() {
    std::ofstream fp("/Users/fabio/computing_methods/data_file.dat");
    RandomData::randomData(50, fp);
    return 0;
}