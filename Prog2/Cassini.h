#pragma once

#include <math.h>
#include <sstream>

namespace Prog2 {
    class Cassini {
    private:
        double a;
        double c;
    public:
        Cassini();
        Cassini(double a, double c);
        Cassini &Set_Distance(double a);
        double Get_Distance() const;
        Cassini &Set_Focal_Parameter(double c);
        double Get_Focal_Parameter() const;
        double Get_Center_Distance(double t) const;
        std::string Get_Shape_Type() const;
        double Get_Curvature_Radius(double t) const;
        double Get_Inflection_Points_Polar_Radius() const;
        double Get_Inflection_Points_Polar_Angle() const;
        std::string Get_Equation() const;
    };
}