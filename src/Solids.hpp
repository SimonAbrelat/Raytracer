#ifndef SOLIDS_H
#define SOLIDS_H

#include "Vector.hpp"

class Solid {
public:
    bool hit(const Ray& ray, double* t);
};

class Sphere : Solid {
public:
    Sphere (Vec3 p, double r, Color c) : pos(p), radius(r), color(c) {}

    bool hit(const Ray& ray, double* t);

    Vec3 pos;
    double radius;
    Color color;
};

class Plane : Solid {
public:
    Plane (Vec3 p, Vec3 n, Color c) : pos(p), normal(n.unit()), color(c) {}

    bool hit(const Ray& ray, double* t);

    Vec3 pos;
    Vec3 normal;
    Color color;
};

#endif // SOLIDS_H
