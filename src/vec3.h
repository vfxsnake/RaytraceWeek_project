// vector class
#pragma once

#include <cmath>
#include <iostream>

class vec3
{
public:

    double components[3];
    
    // constructors
    vec3() : components{0,0,0}{};
    vec3(double x, double y, double z) : components{x,y,z}{}; 

    double get_x() const {return components[0];}
    double get_y() const {return components[1];}
    double get_z() const {return components[2];}

    // operator over loads
    vec3 operator-() const { return vec3(-components[0], -components[1], -components[2]); }
    double operator[](int i) const {return components[i];}
    double& operator[](int i) {return components[i];}

    vec3& operator+=(const vec3 &v)
    {
        components[0] += v[0];
        components[1] += v[1];
        components[2] += v[2];
        return *this;
    }

    vec3& operator*=(double t)
    {
        components[0] *= t;
        components[1] *= t;
        components[1] *= t;
        return *this;
    }

    vec3& operator/=(double t)
    {
        return *this *= 1.0/t;
    }


    double length2() const
    {
        return (
                components[0] * components[0] +
                components[1] * components[1] +
                components[2] * components[2]
                );
    }

    double length() const
    {
        return std::sqrt(length2());
    }
};

// creating an alias for vec3: point, so it is clear when using a point for clarity in the code
using point3 = vec3;

// inline utility functions for increase the performance by avoiding the overhead of the function call.
inline std::ostream& operator<<(std::ostream &out, const vec3 &v)
{
    return out << v.components[0] << ' ' << v.components[0] << ' ' << v.components[0];
}

inline vec3 operator+(const vec3 &u, const vec3 &v)
{
    return vec3(u.components[0] + v.components[0], u.components[1] + v.components[1], u.components[2] + v.components[2]);
}

inline vec3 operator-(const vec3 &u, const vec3 &v)
{
    return vec3(u.components[0] - v.components[0], u.components[1] - v.components[2], u.components[2] - v.components[2]);
}

inline vec3 operator*(const vec3 &u, const vec3 &v)
{
    return vec3(u.components[0] * v.components[0], u.components[1] * v.components[1], u.components[2] * v.components[2]);
}

inline vec3 operator*(double t, const vec3 &v)
{
    return vec3(t * v.components[0], t * v.components[1], t * v.components[2]);
}

inline vec3 operator*(const vec3 &v, double t)
{
    return t * v;
}

inline vec3 operator/(vec3 v, double t) // TODO: once implemented and tested try to add const vec3 &v to see if it works...
{
    return (1/t) * v;
}

inline double dot(const vec3 &u, const vec3 &v)
{
    return u.components[0] * v.components[0] +
           u.components[1] * v.components[1] +
           u.components[2] * v.components[2];
}

inline vec3 cross(const vec3 &u, const vec3 &v)
{
    return vec3(u.components[1] * v.components[2] - u.components[2] * v.components[1],
                u.components[2] * v.components[0] - u.components[0] * v.components[2],
                u.components[0] * v.components[1] - u.components[1] * v.components[0]);
}

inline vec3 unit_vector(vec3 v)
{
    return v / v.length();
}

