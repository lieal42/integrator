// Particle.cc

#include "Particle.hh"
#include <cmath>

Particle::Particle(const std::string& name) {
    name_ = name;
}

Particle::Particle(const std::string& name, const TLorentzVector& P) {
    P_ = P;
    name_ = name;
}

Particle::Particle(const std::string& name, const double& px, const double& py, const double& pz, const double& m) {
    P_ = TLorentzVector(px, py, pz, sqrt(m * m + px * px + py * py + pz * pz));
    name_ = name;
}

Particle::Particle(const std::string& name, Particle* particle) {
    P_ = particle->P_;
    name_ = name;
}

Vector3D Particle::p() const {
    return Vector3D(P_.Px(), P_.Py(), P_.Pz());
}

double Particle::energy() const {
    return P_.E();
}

double Particle::mass() const {
    return sqrt(energy() * energy() - p().r() * p().r());
}

std::string Particle::name() const {
    return name_;
}

TLorentzVector Particle::P() const {
    return P_;
}

void Particle::setp(const Vector3D& p) {
    P_ = TLorentzVector(p.x(), p.y(), p.z(), sqrt(mass() * mass() + p.r() * p.r()));
}

void Particle::setP(const TLorentzVector& P) {
    P_ = P;
}

void Particle::boost(const Vector3D& b) {
    P_.Boost(b.x(), b.y(), b.z());
}