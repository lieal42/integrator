// RandomFata.cc

#include "RandomData.hh"

using std::rand;
using std::srand;
using std::cout;
using std::endl;


bool RandomData::randomData(const int& nData, std::ofstream& file) {
    unsigned int mySeed, i;
    std::ifstream fileSeed("/dev/urandom");

    fileSeed >> mySeed;

    if (!fileSeed.is_open()) {
        mySeed = 1;
    }

    fileSeed.close();

    srand(mySeed);

    if (!file.is_open()) {
        return false;
    }

    for (i = 0; i < nData; i++) {
        file << (double)rand() / RAND_MAX * 3 << " +/- " << (double)rand() / RAND_MAX * 0.43 << endl;
    }

    file.close();

    return true;
}