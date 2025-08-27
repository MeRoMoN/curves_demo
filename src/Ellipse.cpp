#include <cmath>
#include <stdexcept>
#include "curves/Ellipse.hpp"

namespace curves {

Ellipse::Ellipse(double a, double b, double z0) : a_(a), b_(b), z0_(z0) {
    if (a_ <= 0 || b_ <= 0) throw std::invalid_argument("Ellipse semiaxes must be positive");
}

Vec3 Ellipse::point(double t) const {
    return { a_ * std::cos(t), b_ * std::sin(t), z0_ };
}

Vec3 Ellipse::derivative(double t) const {
    return { -a_ * std::sin(t),  b_ * std::cos(t), 0.0 };
}

}