#include <algorithm>
#include "Vector.hpp"

double dot(const Vec3& a, const Vec3& b) {
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

/*
Vec3 crossProduct(const Vec3& a, const Vec3& b) {
   Vec3 ret;
   ret.x = a.y * b.z - a.z * b.y;
   ret.y = -(a.x * b.z - a.z * b.x);
   ret.z = a.x * b.y - a.y * b.x;
   return ret;
}
*/


Color* clamp(Color* c) {
    c->r = std::clamp(c->r, 0, 255);
    c->g = std::clamp(c->g, 0, 255);
    c->b = std::clamp(c->b, 0, 255);
    return c;
}
