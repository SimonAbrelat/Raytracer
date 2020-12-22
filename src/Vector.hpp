#ifndef VECTOR_H
#define VECTOR_H

#include <type_traits>

//Debug
#include <iostream>

template<typename T, std::enable_if_t<std::is_arithmetic<T>::value, bool> = true>
struct V3 {
    T x;
    T y;
    T z;

    V3() {
        x = y = z = 0;
    }

    V3(T a, T b, T c) {
        x = a;
        y = b;
        z = c;
    }

    V3<T> operator+(const V3<T>& other) {
        V3<T> ret;
        ret.x = x + other.x;
        ret.y = y + other.y;
        ret.z = z + other.z;
        return ret;
    }

    V3<T> operator-(const V3<T>& other) {
        V3<T> ret;
        ret.x = x - other.x;
        ret.y = y - other.y;
        ret.z = z - other.z;
        return ret;
    }

    V3<T> operator*(T m) {
        V3<T> ret;
        ret.x = x * m;
        ret.y = y * m;
        ret.z = z * m;
        return ret;
    }

    V3<T> operator/(T m) {
        V3<T> ret;
        ret.x = x / m;
        ret.y = y / m;
        ret.z = z / m;
        return ret;
    }

    T length() {
        return x*x + y*y + z*z;
    }

    V3<T> unit() {
        V3<T> ret(x,y,z);
        return ret / ret.length();
    }
};

typedef V3<double> Vec3;
typedef V3<int> Color;

double dot(Vec3& a, Vec3& b);
Color* clamp(Color* c);

struct Ray {
    Vec3 o; //orientation
    Vec3 u; //direction

    Ray(Vec3 a, Vec3 b) {
        o = a;
        u = b;
    }
};


struct Sphere {
    Vec3 c; //center
    double r; //radius
    Color color;

    Sphere(Vec3 a, double r, Color col) {
        c = a;
        r = r;
        color = col;
    }

    bool intersect(Ray& y, double& t) {
        Vec3 L = c - y.o;
        double tca = dot(L, y.u);
        double d2 = L.length() - (tca * tca);
        if (d2 > r*r) { return false; }
        double thc = std::sqrt((r*r) - d2);
        double t0 = tca - thc;
        double t1 = tca + thc;
        t = std::min(t0, t1);
        return true;
    }
};

#endif // VECTOR_H
