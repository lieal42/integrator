//
//  Calculator.hh
//  computing_methods
//
//  Created by Fabio Pandolfi on 20/10/2020.
//

#ifndef Calculator_hh
#define Calculator_hh
#include <vector>
#include "Datum.hh"
class Calculator {
public:

	//	MARK:- Constructor

	Calculator();

	//	MARK:- Methods

	static Datum
		weightedAverage(const std::vector<Datum>& dati);
	static Datum
		arithmeticAverage(const std::vector<Datum>& dati);
};

#endif /* Calculator_hpp */
