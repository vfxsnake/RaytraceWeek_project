#pragma once

#include <cmath>
#include <limits>
#include <memory>

// Constants

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;  // our double precision definition of pi

// utility Functions
const double degree_to_radians(double degrees)
{
    return degrees * pi /180.0;
}

// common headers... at the end of the file to avoid circular dependencies and other include issues
//  also this includes are not required hire NOTE: provably will worth to move them to the cpp in they are.
// for this particular case those includes are required for main..

#include "ray.h"
#include "vec3.h"
