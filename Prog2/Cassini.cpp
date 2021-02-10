#include <stdio.h>

#include "Cassini.h"

namespace Prog2 {
    Cassini::Cassini() {
        this->a = 0;
        this->c = 0;
    }
    
    Cassini::Cassini(double a, double c) {
        this->Set_Distance(a);
        this->Set_Focal_Parameter(c);
    }
    
    Cassini &Cassini::Set_Distance(double a) {
        if (a < 0) {
           throw "The distance should be a non-negative number!";
        }
        this->a = a;
        return *this;
    }
    
    double Cassini::Get_Distance() const {
        return this->a;
    }
    
    Cassini &Cassini::Set_Focal_Parameter(double c) {
        if (c < 0) {
           throw "The focal parameter should be a non-negative number!";
        }
        this->c = c;
        return *this;
    }
    
    double Cassini::Get_Focal_Parameter() const {
        return this->c;
    }
    
    double Cassini::Get_Center_Distance(double t) const {
        t = 2 * t * M_PI / 180;
        if ((pow(this->c, 4) * pow(cos(t), 2) + pow(this->a, 4) - pow(this->c, 4)) >= 0) {
           return fabs(pow(this->c, 2) * cos(t) + sqrt(pow(this->c, 4) * pow(cos(t), 2) + pow(this->a, 4) - pow(this->c, 4)));
        }
        return -1;
    }
    
    std::string Cassini::Get_Shape_Type() const {   
        if (this->a == 0 && this->c != 0) {
           return "two points";
        }
        if (this->a != 0 && this->c == 0) {
           return "circle";
        }
        if (this->a > 0 && this->a < this->c) {
           return "two separate ovals";
        }
        if (this->a == this->c && this->a != 0 && this->c != 0) {
           return "lemniscate";
        }
        if (this->c < this->a && this->a <= this->c * sqrt(2)) {
           return "with inflection points";
        }
        if (this->a >= this->c * sqrt(2) && this->a != 0 && this->c != 0) {
           return "oval";
        }
        return "point of origin";
    }
    
    double Cassini::Get_Curvature_Radius(double t) const {
        t = 2 * t * M_PI / 180;
        if ((pow(this->c, 4) * pow(cos(t), 2) + pow(this->a, 4) - pow(this->c, 4)) >= 0) {
           double r = fabs(pow(this->c, 2) * cos(t) + sqrt(pow(this->c, 4) * pow(cos(t), 2) + pow(this->a, 4) - pow(this->c, 4)));
           if (r > 0) {
              return pow(this->a, 2) * r / (pow(r, 2) + cos(t) * pow(this->c, 2));
           }
        }
        return -1;
    }
    
    double Cassini::Get_Inflection_Points_Polar_Radius() const {  
        return pow(((pow(this->a, 4) - pow(this->c, 4)) / 3), 0.25);
    }
    
    double Cassini::Get_Inflection_Points_Polar_Angle() const {
        return acos((-1) * sqrt((pow((this->a / this->c), 4) - 1) / 3)) * 180 / (2 * M_PI);
    }
    
    std::string Cassini::Get_Equation() const {
        if (this->a == 0 && this->c == 0) {
           return "(x ^ 2 + y ^ 2) ^ 2 = 0";
        }
        else {
           std::stringstream ss;
           if (this->a == 0) {
              ss << "(x ^ 2 + y ^ 2) ^ 2 - " << 2 * pow(this->c, 2) << " (x ^ 2 - y ^ 2) = " << (-1) * pow(this->c, 4);
           }
           else if (this->c == 0) {
              ss << "(x ^ 2 + y ^ 2) ^ 2 = " << pow(this->a, 4);
           }
           else {
              ss << "(x ^ 2 + y ^ 2) ^ 2 - " << 2 * pow(this->c, 2) << " * (x ^ 2 - y ^ 2) = " << pow(this->a, 4) - pow(this->c, 4);
           }
           return ss.str();
        }
    }
}