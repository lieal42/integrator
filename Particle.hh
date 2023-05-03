// Particle.hh

#ifndef Particle_hh
#define Particle_hh


#include "TLorentzVector.h"
#include "Vector3D.hh"
#include <string>

class Particle {
public:
    Particle(const std::string& name);
    Particle(const std::string& name, const TLorentzVector& P);
    Particle(const std::string& name, const double& px, const double& py, const double& pz, const double& m);
    Particle(const std::string& name, Particle* particle);
    virtual ~Particle() {}

    virtual Vector3D p() const;
    virtual double energy() const;
    virtual double mass() const;
    virtual std::string name() const;
    virtual TLorentzVector P() const;

    virtual void setp(const Vector3D& p);
    virtual void setP(const TLorentzVector& P);

    virtual void boost(const Vector3D& b);

private:
    TLorentzVector P_;
    std::string name_;
};

#endif