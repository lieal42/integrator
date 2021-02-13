// Integrator.hh

#ifndef Integrator_hh
#define Integrator_hh

class Function;

class Integrator {
public:
    Integrator(int npoints) { npoints_ = npoints; };
    virtual ~Integrator() {};
    void setNPoints(int n) {
        npoints_ = n;
    }
    int nPoints() const { return npoints_; };
    virtual double point(double xlo, double xhi, int i) const = 0;
    virtual double integrate(double xlo, double xhi, const Function* f) const = 0;
private:
    int npoints_;
};


#endif