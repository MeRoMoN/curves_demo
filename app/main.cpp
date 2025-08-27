#include <algorithm>
#include <cmath>
#include <iostream>
#include <memory>
#include <numeric>
#include <random>
#include <vector>

#if __has_include(<execution>)
  #include <execution>
  #define HAS_EXECUTION 1
#else
  #define HAS_EXECUTION 0
#endif

#include "curves/Circle.hpp"
#include "curves/Ellipse.hpp"
#include "curves/Helix3D.hpp"

using namespace curves;
constexpr double PI = 3.14159265358979323846;

int main() {
    try {
        std::mt19937 rng(std::random_device{}());
        std::uniform_int_distribution<int> kind_dist(0, 2);
        std::uniform_int_distribution<int> count_dist(10, 25);
        std::uniform_real_distribution<double> radius_dist(0.5, 10);
        std::uniform_real_distribution<double> z_dist(-5, 5);
        std::uniform_real_distribution<double> step_dist(0.5, 8);

        std::vector<std::shared_ptr<Curve>> curves;
        const int n = count_dist(rng);
        curves.reserve(n);

        for (int i = 0; i < n; ++i) {
            switch (kind_dist(rng)) {
                case 0:
                    curves.push_back(std::make_shared<Circle>(radius_dist(rng), z_dist(rng)));
                    break;
                case 1:
                    curves.push_back(std::make_shared<Ellipse>(radius_dist(rng), radius_dist(rng), z_dist(rng)));
                    break;
                case 2:
                    curves.push_back(std::make_shared<Helix3D>(radius_dist(rng), step_dist(rng)));
                    break;
            }
        }

        // Print point & derivative at t = PI/4
        const double t = PI / 4.0;
        std::cout << "t = PI/4\n\n";
        for (const auto& c : curves) {
            if (auto cir = std::dynamic_pointer_cast<Circle>(c)) {
                std::cout << "Circle  (r=" << cir->radius() << "):\n";
            } else if (dynamic_cast<const Ellipse*>(c.get())) {
                std::cout << "Ellipse:\n";
            } else if (dynamic_cast<const Helix3D*>(c.get())) {
                std::cout << "Helix3D:\n";
            } else {
                std::cout << "Curve:\n";
            }
            std::cout << "  point      = " << c->point(t) << '\n';
            std::cout << "  derivative = " << c->derivative(t) << '\n';
        }

        // Collect circles
        std::vector<std::shared_ptr<Circle>> circles;
        for (const auto& c : curves) {
            if (auto cir = std::dynamic_pointer_cast<Circle>(c))
                circles.push_back(std::move(cir));
        }

        // Sort by radius
        std::sort(circles.begin(), circles.end(),
                  [](const auto& a, const auto& b){ return a->radius() < b->radius(); });

        std::cout << "\nCircles sorted by radius:\n";
        for (const auto& cir : circles) std::cout << "  r=" << cir->radius() << '\n';

        // Sum of radii
        double total = 0.0;
    #if HAS_EXECUTION
        total = std::transform_reduce(std::execution::par, circles.begin(), circles.end(),
                                      0.0, std::plus<>(),
                                      [](const auto& c){ return c->radius(); });
    #else
        total = std::accumulate(circles.begin(), circles.end(), 0.0,
                                [](double s, const auto& c){ return s + c->radius(); });
    #endif
        std::cout << "\nTotal sum of radii: " << total << '\n';
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }
}