#pragma once

#include <iostream>

#include "Cassini.h"
#include "util.h"

namespace Prog2 {
    void Dialog(Cassini &cassini);
    void Menu();
    void Set_Distance(Cassini &cassini);
    void Get_Distance(Cassini &cassini);
    void Set_Focal_Parameter(Cassini &cassini);
    void Get_Focal_Parameter(Cassini &cassini);
    void Get_Center_Distance(Cassini &cassini);
    void Get_Shape_Type(Cassini &cassini);
    void Get_Curvature_Radius(Cassini &cassini);
    void Get_Inflection_Points_Polar_Coordinates(Cassini &cassini);
    void Get_Equation(Cassini &cassini);
}