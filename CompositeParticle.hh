// CompositeParticle.hh

#ifndef CompositeParticle_hh
#define CompositeParticle_hh

#include "Particle.hh"
#include <list>

class CompositeParticle : public Particle {
public:
    CompositeParticle(const std::string& name);
    CompositeParticle(const std::string& name, Particle* particle);


    virtual Vector3D p() const;
    virtual double energy() const;
    virtual double mass() const;
    virtual TLorentzVector P() const;

    virtual void setp(const Vector3D& p);
    virtual void setP(const TLorentzVector& P);

    virtual void boost(const Vector3D& b);

    void add(Particle* particle);

private:
    std::list<Particle*> particles_;
};

#endif