//Counter.hh
#ifndef Counter_hh
#define Counter_hh
#include <iostream>

class Counter {

public:
    Counter() { count_ = 0; };
    ~Counter() {};

    int value() const;

    void reset();
    void increment(int step = 1);

private:
    int count_;
};





#endif