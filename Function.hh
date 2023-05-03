//Function.hh

#ifndef Function_hh
#define Function_hh

#include <string>

class Function {
public:
    Function(const std::string& name);
    virtual ~Function();
    virtual double value(double x) const = 0;

    virtual std::string name() const { return name_; }

    friend std::ostream& operator<<(std::ostream& os, const Function& rhs);


private:
    std::string name_;
};
#endif