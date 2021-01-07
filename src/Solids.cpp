#include "Solids.hpp"
#include <cmath>

bool Sphere::hit(const Ray& ray, double* t) {
    Vec3 o = ray.origin;
    Vec3 d = ray.direction;
    Vec3 oc = o - pos;
    const double b = 2 * dot(oc, d);
    const double c = dot(oc, oc) - radius*radius;
    double disc = b*b - 4 * c;
    if (disc < 1e-4) return false;
    disc = sqrt(disc);
    const double t0 = -b - disc;
    const double t1 = -b + disc;
    *t = (t0 < t1) ? t0 : t1;
    return true;
}

bool Plane::hit(const Ray& ray, double* t) {
    double num = dot(ray.direction, normal.unit());
    double dem = dot(pos - ray.origin, normal.unit());
    if (num == 0) {
        return dem == 0;
    }
    (*t) = num / dem;
    return true;
}
