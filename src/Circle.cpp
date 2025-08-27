#include <cmath>
#include <stdexcept>
#include "curves/Circle.hpp"

namespace curves {

Circle::Circle(double r, double z0) : r_(r), z0_(z0) {
    if (r_ <= 0) throw std::invalid_argument("Circle radius must be positive");
}

Vec3 Circle::point(double t) const {
    return { r_ * std::cos(t), r_ * std::sin(t), z0_ };
}

Vec3 Circle::derivative(double t) const {
    return { -r_ * std::sin(t), r_ * std::cos(t), 0.0 };
}

}