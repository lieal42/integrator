//
//  Calculator.cc
//  computing_methods
//
//  Created by Fabio Pandolfi on 20/10/2020.
//

#include "Calculator.hh"
#include <vector>
#include "Datum.hh"

//	MARK:- Class Function

Calculator::Calculator() {}

Datum Calculator::weightedAverage(const std::vector<Datum>& dati) {
	Datum mean(0, 0);
	double norm = 0;
	for (Datum i : dati) {
		mean = mean + i / (i.error() * i.error());
		norm += 1. / (i.error() * i.error());
	}
	return mean * (1. / norm);
}

Datum Calculator::arithmeticAverage(const std::vector<Datum>& dati) {
	Datum mean(0, 0);
	unsigned int j = 0;
	for (Datum i : dati) {
		mean = mean + i;
		j++;
	}
	return mean / j;
}
