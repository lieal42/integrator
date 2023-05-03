#ifndef CompositeSystem_hh
#define CompositeSystem_hh

#include "Body.hh"
#include "Vector3D.hh"
#include <list>

class CompositeSystem : public Body {
public:
    CompositeSystem(const std::string& name, Body* center = 0);
    virtual double mass() const;
    virtual Vector3D position() const;
    virtual Vector3D velocity() const;
    virtual void move(const Vector3D& Force, double dt);
    virtual void print() const;
    virtual void setPosition(const Vector3D& p);
    virtual void setVelocity(const Vector3D& v);
    virtual void translate(const Vector3D& dr);
    virtual void addVelocity(const Vector3D& dv);
    virtual Vector3D forceOn(const Body* obj) const;
    virtual Vector3D forceFrom(const Body* source) const;

    virtual void add(Body* b, const Vector3D p0 = Vector3D(0, 0, 0), const Vector3D v0 = Vector3D(0, 0, 0));
    virtual std::list<Body*> bodies() const { return bodies_; }

    void evolve(const double& dt);

private:
    std::list<Body*> bodies_;
    Body* center_;
};

#endif