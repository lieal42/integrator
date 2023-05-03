//Counter.cc

#include "Counter.hh"
#include <iostream>


int Counter::value() const {
    return count_;
}

void Counter::reset() {
    count_ = 0;
}

void Counter::increment(int step) {
    count_ += step;
}