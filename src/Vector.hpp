#ifndef VECTOR_H
#define VECTOR_H

#include <type_traits>
#include <cmath>

//Debug
#include <iostream>

struct Vec3 {
    double x, y, z;

    Vec3(double a, double b, double c) : x(a), y(b), z(c) {};

    inline Vec3 operator+(const Vec3& o) { return Vec3(x + o.x, y + o.y, z + o.z); }
    inline Vec3 operator-(const Vec3& o) { return Vec3(x - o.x, y - o.y, z - o.z); }
    inline Vec3 operator*(double m)      { return Vec3(x * m, y * m, z * m); }
    inline Vec3 operator/(double m)      { return Vec3(x / m, y / m, z / m); }

    double length() {
        return std::sqrt(x*x + y*y + z*z);
    }

    Vec3 unit() {
        return (*this) / this->length();
    }
};

struct Color {
    int r, g, b;

    Color(double a, double b, double c) : r(a), g(b), b(c) {};
};

double dot(const Vec3& a, const Vec3& b);
//Vec3 cross(const Vec3& a, const Vec3& b);
Color* clamp(Color* c);

struct Ray {
    Vec3 origin; //origin
    Vec3 direction; //direction

    Ray(Vec3 a, Vec3 b) : origin(a), direction(b) {}

    Vec3 at(double t) {
        return origin + (direction * t);
    }
};

#endif // VECTOR_H
