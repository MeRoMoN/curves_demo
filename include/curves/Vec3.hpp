#pragma once
#include <ostream>

namespace curves {

struct Vec3 {
    double x{}, y{}, z{};
};

inline std::ostream& operator<<(std::ostream& os, const Vec3& v) {
    return os << '(' << v.x << ", " << v.y << ", " << v.z << ')';
}

}