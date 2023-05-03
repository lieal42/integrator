// Datum.hh
#ifndef Datum_hh
#define Datum_hh
#include <iostream>
#include <cmath>

class Datum {

public:
	Datum() {};
	Datum(double val, double err);
	Datum(const Datum& datum);

	~Datum() {};

	double value() const { return value_; };
	double error()const { return error_; };
	//	std::string name() const { return name_; };

	double significance() const;
	void print() const;

	void setValue(double val) { value_ = val; };
	void setError(double err) { error_ = err; };
	//	void setName(std::string nam) { name_ = nam; };

	Datum operator+(const Datum& rhs) const;
	Datum operator*(const double& rhs) const;
	Datum operator/(const double& rhs) const;

	//	friend std::istream& operator>>(std::istream& is, Datum& rhs);

	friend std::ostream& operator<<(std::ostream& os, const Datum& rhs);
private:
	double value_;
	double error_;
	std::string name_;
};

#endif
