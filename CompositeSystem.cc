#include "CompositeSystem.hh"
#include <iostream>
#include <cmath>

using std::cout;
using std::endl;
using std::list;

CompositeSystem::CompositeSystem(const std::string& name, Body* center) : Body(name) {
    bodies_.push_back(center);
    center_ = center;
}

double CompositeSystem::mass() const {
    double m = 0;
    for (Body* i : bodies_) {
        m += i->mass();
    }
    return m;
}

Vector3D CompositeSystem::position() const {
    Vector3D p = Vector3D(0, 0, 0);
    for (Body* i : bodies_) {
        p += i->mass() * i->position();
    }
    return p / mass();
}

Vector3D CompositeSystem::velocity() const {
    return center_->velocity();
}

void CompositeSystem::move(const Vector3D& Force, double dt) {
    for (Body* i : bodies_) {
        i->move(Force, dt);
    }
}

void CompositeSystem::print() const {
    std::cout << "===== class: CompositeSystem  name: " << name()
        << "# bodies: " << bodies_.size() << " ======= "
        << std::endl;
    for (Body* i : bodies_) {
        i->print();
    }
    std::cout << "==============================================" << std::endl;
}

void CompositeSystem::setPosition(const Vector3D& p) {
    Vector3D dr = p - center_->position();
    translate(dr);
} // FIXME: change position of center and then find translate to apply

void CompositeSystem::translate(const Vector3D& dr) {
    for (Body* i : bodies_) {
        i->translate(dr);
    }
}

void CompositeSystem::setVelocity(const Vector3D& v) {
    Vector3D dv = v - center_->velocity();
    addVelocity(dv);
}

void CompositeSystem::addVelocity(const Vector3D& dv) {
    for (Body* i : bodies_) {
        i->addVelocity(dv);
    }
}

Vector3D CompositeSystem::forceOn(const Body* obj) const {
    Vector3D force = Vector3D(0, 0, 0);
    for (Body* i : bodies_) {
        if (i == obj) continue;
        force += i->forceOn(obj);
    }
    return force;
}

Vector3D CompositeSystem::forceFrom(const Body* source) const {
    Vector3D force = Vector3D(0, 0, 0);
    for (Body* i : bodies_) {
        if (i == source) continue;
        force += i->forceFrom(source);
    }
    return force;
}

void CompositeSystem::add(Body* b, const Vector3D p0, const Vector3D v0) {
    b->translate(p0);
    b->addVelocity(velocity() + v0);
    bodies_.push_back(b);
}

void CompositeSystem::evolve(const double& dt) {
    for (Body* i : bodies_) {
        Vector3D force(0, 0, 0);
        for (Body* j : bodies_) {
            if (j == i) { continue; }
            force += i->forceFrom(j);
        }
        i->move(force, dt);
    }
}