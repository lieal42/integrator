//Function1.hh

#ifndef Function1_hh
#define Function1_hh

#include <string>

class Function1 {
public:
    Function1(const std::string& name);
    virtual ~Function1();
    virtual double value(double x) const = 0;
    virtual double derivative(double x) const {};
    virtual double integrate(double x1, double x2) const {};

    virtual std::string name() const { return name_; }

    friend std::ostream& operator<<(std::ostream& os, const Function1& rhs);


private:
    std::string name_;
};
#endif