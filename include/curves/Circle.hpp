#pragma once
#include "export.hpp"
#include "Curve.hpp"

namespace curves {

class CURVES_API Circle final : public Curve {
public:
    explicit Circle(double r, double z0 = 0.0);
    Vec3 point(double t) const override;
    Vec3 derivative(double t) const override;

    double radius() const { return r_; }

private:
    double r_;
    double z0_;
};

}