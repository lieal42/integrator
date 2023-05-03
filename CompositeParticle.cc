// CompositeParticle.cc

#include "CompositeParticle.hh"
#include <iostream>

CompositeParticle::CompositeParticle(const std::string& name) : Particle(name) {}

CompositeParticle::CompositeParticle(const std::string& name, Particle* particle) : Particle(name, particle) {
    particles_.push_back(particle);
}

Vector3D CompositeParticle::p() const {
    TLorentzVector P1(0, 0, 0, 0);
    for (Particle* i : particles_) {
        P1 += i->P();
    }
    return Particle("", P1).p();
}

double CompositeParticle::energy() const {
    TLorentzVector P1(0, 0, 0, 0);
    for (Particle* i : particles_) {
        P1 += i->P();
    }
    return Particle("", P1).energy();
}

double CompositeParticle::mass() const {
    TLorentzVector P1(0, 0, 0, 0);
    for (Particle* i : particles_) {
        P1 += i->P();
    }
    return Particle("", P1).mass();
}

TLorentzVector CompositeParticle::P() const {
    TLorentzVector P1(0, 0, 0, 0);
    for (Particle* i : particles_) {
        P1 += i->P();
    }
    return P1;
}

void CompositeParticle::setp(const Vector3D& p) {
    std::cout << "You should not change the momentum of a composite particle!" << std::endl;
}

void CompositeParticle::setP(const TLorentzVector& p) {
    std::cout << "You should not change the 4-momentum of a composite particle!" << std::endl;
}

void CompositeParticle::boost(const Vector3D& b) {
    for (Particle* i : particles_) {
        i->boost(b);
    }
}

void CompositeParticle::add(Particle* particle) {
    particles_.push_back(particle);
}