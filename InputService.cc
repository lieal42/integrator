//
//  InputService.cc
//  computing_methods
//
//  Created by Fabio Pandolfi on 20/10/2020.
//

#include "InputService.hh"

std::vector<Datum> InputService::readDataFromUser(std::ifstream& inFile) {
	std::vector<Datum> v;
	Datum x;
	double val, err;
	std::string str;
	while (inFile >> val >> str >> err) {
		x = Datum(val, err);
		v.push_back(x);
	}
	return v;
}
