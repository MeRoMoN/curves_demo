#include <cmath>
#include <stdexcept>
#include "curves/Helix3D.hpp"

namespace curves {

constexpr double PI = 3.14159265358979323846;

Helix3D::Helix3D(double r, double step_per_turn)
    : r_(r), step_per_turn_(step_per_turn) {
    if (r_ <= 0) throw std::invalid_argument("Helix radius must be positive");
    if (step_per_turn_ <= 0) throw std::invalid_argument("Helix step per turn must be positive");
}

Vec3 Helix3D::point(double t) const {
    return { r_ * std::cos(t), r_ * std::sin(t), (step_per_turn_ / (2.0 * PI)) * t };
}

Vec3 Helix3D::derivative(double t) const {
    return { -r_ * std::sin(t), r_ * std::cos(t), step_per_turn_ / (2.0 * PI) };
}

}