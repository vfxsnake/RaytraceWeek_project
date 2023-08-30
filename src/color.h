#pragma once

#include <iostream>
#include "vec3.h"

using color = vec3;

void write_color(std::ostream &out, color pixel_color)
{
    out << static_cast<int>(255.999 * pixel_color.get_x()) << ' '
        << static_cast<int>(255.999 * pixel_color.get_y()) << ' '
        << static_cast<int>(255.999 * pixel_color.get_z()) << '\n';
}
