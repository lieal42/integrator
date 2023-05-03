//
//  InputService.hh
//  computing_methods
//
//  Created by Fabio Pandolfi on 20/10/2020.
//

#ifndef InputService_hh
#define InputService_hh

#include <iostream>
#include <vector>
#include <fstream>
#include "Datum.hh"

class InputService {
public:
	InputService();
	static std::vector<Datum> readDataFromUser(std::ifstream& inFile);
private:
};

#endif /* InputService_hh */
