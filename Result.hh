//Result.hh

#ifndef Result_hh
#define Result_hh

#include<iostream>
using namespace std;

class Result {
public:
    Result() {};
    Result(const double& mean, const double& stdDev);

    double getMean() { return mean_; };
    double getStdDev() { return stdDev_; };

private:
    double mean_;
    double stdDev_;
};

#endif
