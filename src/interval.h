#pragma once

class interval
{
public:
    double min,max;

    interval() :min(+infinity), max(-infinity){}

    interval(double _min, double _max) : min(_min), max(_max){}

    bool contains(double x) const
    {
        return min <= x && x <= max;
    }

    bool surrounds(double x) const
    {
        return min < x && x < max;
    }

    static const interval empty, universe;
};

const interval interval::empty = interval(+infinity, -infinity);
const interval interval::universe = interval(-infinity, +infinity);