#include <algorithm>
#include "Vector.hpp"

double dot(Vec3& a, Vec3& b) {
    return (a.x * b.x) + (a.y + b.y) + (a.z + b.z);
}

Color* clamp(Color* c) {
    c->x = std::clamp(c->x, 0, 255);
    c->y = std::clamp(c->y, 0, 255);
    c->z = std::clamp(c->z, 0, 255);
    return c;
}
