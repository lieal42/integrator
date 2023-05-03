#include "Vector3D.hh"

Vector3D::Vector3D(double n1, double n2, double n3, std::string SoC) {
    if (SoC == "polar") {
        x_ = n1 * sin(n2) * cos(n3);
        y_ = n1 * sin(n2) * sin(n3);
        z_ = n1 * cos(n2);
    } else if (SoC == "cylindric") {
        x_ = n1 * cos(n2);
        y_ = n1 * sin(n2);
        z_ = n3;
    } else  if (SoC == "cartesian") {
        x_ = n1;
        y_ = n2;
        z_ = n3;
    } else {
        std::cerr << "Unrecognized identifier: " << SoC << std::endl;
        std::cerr << "Please use \"cartesian\" (default)), \"cylindric\" or \"polar\"." << std::endl;
    }
}

Vector3D::Vector3D(const Vector3D& vec) {
    x_ = vec.x_;
    y_ = vec.y_;
    z_ = vec.z_;
}

double Vector3D::r() const {
    return sqrt(x_ * x_ + y_ * y_ + z_ * z_);
}

double Vector3D::phi() const {
    if (x_ == 0) {
        return ((y_ > 0) - (y_ < 0)) * M_PI_2;
    }
    double angle = atan(y_ / x_);
    if (x_ < 0) {
        return atan(y_ / x_) + ((y_ > 0) - (y_ < 0)) * M_PI;
    }
    return atan(y_ / x_);
}

double Vector3D::theta() const {
    return acos(z_ / sqrt(x_ * x_ + y_ * y_ + z_ * z_));
}

double Vector3D::x() const {
    return x_;
}

double Vector3D::y() const {
    return y_;
}

double Vector3D::z() const {
    return z_;
}

double Vector3D::distance(const Vector3D& r0) const {
    return (*this - r0).r();
}

Vector3D Vector3D::operator+(const Vector3D& rhs) const {
    return Vector3D(x_ + rhs.x_, y_ + rhs.y_, z_ + rhs.z_);
}

Vector3D Vector3D::operator-(const Vector3D& rhs) const {
    return Vector3D(x_ - rhs.x_, y_ - rhs.y_, z_ - rhs.z_);
}

Vector3D Vector3D::operator*(const double& rhs) const {
    return Vector3D(x_ * rhs, y_ * rhs, z_ * rhs);
}

Vector3D Vector3D::operator/(const double& rhs) const {
    return Vector3D(x_ / rhs, y_ / rhs, z_ / rhs);
}

Vector3D& Vector3D::operator=(const Vector3D& rhs) {
    x_ = rhs.x_;
    y_ = rhs.y_;
    z_ = rhs.z_;
    return *this;
}

Vector3D& Vector3D::operator+=(const Vector3D& rhs) {
    *this = *this + rhs;
    return *this;
}

Vector3D& Vector3D::operator=(const double& rhs) {
    x_ = rhs;
    y_ = rhs;
    z_ = rhs;
    return *this;
}

const Vector3D operator*(const double& lhs, const Vector3D& rhs) {
    return Vector3D(lhs * rhs.x_, lhs * rhs.y_, lhs * rhs.z_);
}

double scalarProduct(const Vector3D& lhs, const Vector3D& rhs) {
    return lhs.x_ * rhs.x_ + lhs.y_ * rhs.y_ + lhs.z_ * rhs.z_;
}

Vector3D vectorProduct(const Vector3D& lhs, const Vector3D& rhs) {
    return Vector3D(lhs.y_ * rhs.z_ - lhs.z_ * rhs.y_, lhs.z_ * rhs.x_ - lhs.x_ * rhs.z_, lhs.x_ * rhs.y_ - lhs.y_ * rhs.x_);
}

std::ostream& operator<<(std::ostream& os, const Vector3D& rhs) {
    os << "(" << rhs.x_ << ", " << rhs.y_ << ", " << rhs.z_ << ")";
    return os;
}