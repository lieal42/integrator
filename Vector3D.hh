#ifndef Vector3D_hh
#define Vector3D_hh

#include <iostream>
#include <cmath>

class Vector3D {
public:
    Vector3D() {};
    Vector3D(double n1, double n2, double n3, std::string SoC = "cartesian");
    Vector3D(const Vector3D& vec);
    ~Vector3D() {};

    double r() const;
    double mod() const { return r(); }; // done
    double phi() const;
    double theta() const;
    double x() const;
    double y() const;
    double z() const;

    double distance(const Vector3D& r0) const; // done

    Vector3D operator+(const Vector3D& rhs) const;
    Vector3D operator-(const Vector3D& rhs) const;

    Vector3D operator*(const double& rhs) const;
    Vector3D operator/(const double& rhs) const;

    Vector3D& operator=(const Vector3D& rhs); // done
    Vector3D& operator+=(const Vector3D& rhs); // done

    Vector3D& operator=(const double& rhs); // done

    friend const Vector3D operator*(const double& lhs, const Vector3D& rhs);

    friend double scalarProduct(const Vector3D& lhs, const Vector3D& rhs);
    friend Vector3D vectorProduct(const Vector3D& lhs, const Vector3D& rhs);

    friend std::ostream& operator<<(std::ostream& os, const Vector3D& rhs); // done

private:
    double x_;
    double y_;
    double z_;
};

#endif