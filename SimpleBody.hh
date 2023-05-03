#ifndef SimpleBody_hh
#define SimpleBody_hh

#include "Body.hh"
#include "Vector3D.hh"

class SimpleBody : public Body {
public:
    SimpleBody(const std::string& name, const double mass, const Vector3D& x0 = Vector3D(0, 0, 0));
    virtual void move(const Vector3D& Force, double dt);
    virtual double mass() const { return mass_; }
    virtual Vector3D position() const { return pos_; }
    virtual Vector3D velocity() const { return vel_; }
    virtual void setPosition(const Vector3D& p) { pos_ = p; }
    virtual void setVelocity(const Vector3D& v) { vel_ = v; }
    virtual void translate(const Vector3D& dr) { pos_ += dr; }
    virtual void addVelocity(const Vector3D& dv) { vel_ += dv; }
    virtual Vector3D forceOn(const Body* obj) const;
    virtual Vector3D forceFrom(const Body* source) const;

    virtual void print() const;

private:
    Vector3D pos_;
    Vector3D vel_;
    double mass_;
};

#endif