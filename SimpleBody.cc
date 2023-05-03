#include "SimpleBody.hh"
#include "Vector3D.hh"

#include <iostream>
#include <cmath>

SimpleBody::SimpleBody(const std::string& name, const double mass, const Vector3D& x0) : Body(name) {
    mass_ = mass;
    pos_ = x0;
}

void SimpleBody::move(const Vector3D& Force, double dt) { // d = dt, dv/dt = a
    Vector3D acc = Force / mass_;
    Vector3D k1 = vel_ * dt;
    Vector3D k2 = k1 * 0.5 + vel_;
    Vector3D k3 = k2 * 0.5 + vel_;
    Vector3D k4 = k3 + vel_;
    Vector3D k = k1 + 2 * k2 + 2 * k3 + k4;
    pos_ += k;
    k1 = acc * dt;
    k2 = k1 * 0.5 + acc;
    k3 = k2 * 0.5 + acc;
    k4 = k3 + acc;
    k = k1 + 2 * k2 + 2 * k3 + k4;
    vel_ += k;

}

Vector3D SimpleBody::forceOn(const Body* obj) const {
    const double Grav_Const = 6.673e-11;
    Vector3D dr = position() - obj->position();
    Vector3D force = Grav_Const * mass() * obj->mass() * dr / pow(dr.r(), 3);
    return force;
}

Vector3D SimpleBody::forceFrom(const Body* source) const {
    const double Grav_Const = 6.673e-11;
    Vector3D dr = source->position() - position();
    Vector3D force = Grav_Const * source->mass() * mass() * dr / pow(dr.r(), 3);
    return force;
}

void SimpleBody::print() const {
    std::cout << "===== class: SimpleBody  name: " << name()
        << "\t mass: " << mass_ << " kg" << " ===== " << std::endl
        << "current position " << pos_ << "\t distance from origin: "
        << pos_.mod() << " m" << std::endl
        << "current velocity " << vel_ << "\t "
        << vel_.mod()
        << " m/s" << std::endl;
}