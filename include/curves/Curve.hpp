#pragma once
#include "export.hpp"
#include "Vec3.hpp"

namespace curves {

class CURVES_API Curve {
public:
    virtual ~Curve() = default;
    virtual Vec3 point(double t) const = 0;
    virtual Vec3 derivative(double t) const = 0;
};

}