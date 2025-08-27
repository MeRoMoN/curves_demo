#pragma once
#include "export.hpp"
#include "Curve.hpp"

namespace curves {

class CURVES_API Ellipse final : public Curve {
public:
    Ellipse(double a, double b, double z0 = 0.0);
    Vec3 point(double t) const override;
    Vec3 derivative(double t) const override;

private:
    double a_, b_, z0_;
};

}