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

// TODO: add vector utility functions.