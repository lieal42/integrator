//Datum.cc

#include "Datum.hh"
#include <iostream>
#include <cmath>

using std::cout;
using std::endl;


Datum::Datum(double val, double err) {
	value_ = val;
	error_ = err;
}

Datum::Datum(const Datum& datum) {
	value_ = datum.value_;
	error_ = datum.error_;
	//	name_ = datum.name();
}

double Datum::significance() const {
	return value_ / error_;
}

void Datum::print() const {
	cout << value_ << " +/- " << error_ << endl;
}

Datum Datum::operator+(const Datum& rhs) const {
	return Datum(value_ + rhs.value_, std::sqrt(error_ * error_ + rhs.error_ * rhs.error_));
}

Datum Datum::operator*(const double& rhs) const {
	return Datum(value_ * rhs, error_ * rhs);
}

Datum Datum::operator/(const double& rhs) const {
	return Datum(value_ / rhs, error_ / rhs);
}

/*std::istream& operator>>(std::istream& is, Datum& rhs) {
	is >> rhs.value_ >> rhs.error_;
	return rhs;
}*/

std::ostream& operator<<(std::ostream& os, const Datum& rhs) {
	os << rhs.value_ << " +/- " << rhs.error_;
	return os;
}

