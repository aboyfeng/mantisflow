#pragma once

#include <vector>
#include <array>
#include <cmath>

namespace mantis {

// Basic types
using Real = double;
using Index = std::size_t;

// Vector types
using Vec3 = std::array<Real, 3>;

// Field types
using ScalarField = std::vector<Real>;
using VectorField = std::vector<Vec3>;

// Vector operations
inline Real dot(const Vec3& a, const Vec3& b) {
    return a[0]*b[0] + a[1]*b[1] + a[2]*b[2];
}

inline Vec3 cross(const Vec3& a, const Vec3& b) {
    return {
        a[1]*b[2] - a[2]*b[1],
        a[2]*b[0] - a[0]*b[2],
        a[0]*b[1] - a[1]*b[0]
    };
}

inline Real magnitude(const Vec3& v) {
    return std::sqrt(dot(v, v));
}

inline Vec3 normalize(const Vec3& v) {
    Real mag = magnitude(v);
    return {v[0]/mag, v[1]/mag, v[2]/mag};
}

} // namespace mantis
