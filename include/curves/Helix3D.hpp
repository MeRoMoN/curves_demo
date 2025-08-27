#pragma once
#include "export.hpp"
#include "Curve.hpp"

namespace curves {

class CURVES_API Helix3D final : public Curve {
public:
    Helix3D(double r, double step_per_turn);
    Vec3 point(double t) const override;
    Vec3 derivative(double t) const override;

private:
    double r_;
    double step_per_turn_;
};

}