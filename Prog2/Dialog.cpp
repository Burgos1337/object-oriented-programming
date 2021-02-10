#include "Dialog.h"

#define options_number 9

namespace Prog2 {
    typedef void(*opt_t)(Cassini&);

    static const opt_t options[options_number] = {
        &Set_Distance,
        &Get_Distance,
        &Set_Focal_Parameter,
        &Get_Focal_Parameter,
        &Get_Center_Distance,
        &Get_Shape_Type,
        &Get_Curvature_Radius,
        &Get_Inflection_Points_Polar_Coordinates,
        &Get_Equation
    };

    void Dialog(Cassini &cassini) {
        int choice = 0;
        
        std::cout << "------------------------------------------------------------" << std::endl;
        while (true) {
           Menu();
           std::cout << "------------------------------------------------------------" << std::endl;
           choice = getNum<int>("Your choice: ");
           std::cout << "------------------------------------------------------------" << std::endl;
           if (!choice) {
              break;
           }
           else if (choice < 0 || choice > options_number) {
              std::cout << "Invalid option detected!" << std::endl; 
           }
           else {
              options[choice - 1](cassini);
           }
           std::cout << "------------------------------------------------------------" << std::endl;
        }
    }
    
    void Menu() {
        std::cout <<
            "0. Quit" << std::endl <<
            "1. Set distance" << std::endl <<
            "2. Get distance" << std::endl <<
            "3. Set focal parameter" << std::endl <<
            "4. Get focal parameter" << std::endl <<
            "5. Get center distance" << std::endl <<
            "6. Get shape type" << std::endl <<
            "7. Get curvature radius" << std::endl <<
            "8. Get inflection points polar coordinates" << std::endl <<
            "9. Get equation" << std::endl;
    }
    
    void Set_Distance(Cassini &cassini) {
        double a = getNum<double>("Enter the distance: ");
        
        try {
            cassini.Set_Distance(a);
        }
        catch (const char *error) {
            std::cerr << error << std::endl;
        }
    }
    
    void Get_Distance(Cassini &cassini) {
        std::cout << "Distance = " << cassini.Get_Distance() << std::endl;
    }
    
    void Set_Focal_Parameter(Cassini &cassini) {
        double c = getNum<double>("Enter the focal parameter: ");
        
        try {
            cassini.Set_Focal_Parameter(c);
        }
        catch (const char *error) {
            std::cerr << error << std::endl;
        }
    }
    
    void Get_Focal_Parameter(Cassini &cassini) {
        std::cout << "Focal parameter = " << cassini.Get_Focal_Parameter() << std::endl;
    }
    
    void Get_Center_Distance(Cassini &cassini) {
        double t = getNum<double>("Angle value in degrees: ");
        
        if (cassini.Get_Center_Distance(t) >= 0) {
           std::cout << "Center distance = " << cassini.Get_Center_Distance(t) << std::endl;
        }
        else {
           std::cout << "Invalid polar angle coordinate!" << std::endl;
        }
    }
    
    void Get_Shape_Type(Cassini &cassini) {
        std::cout << "Shape type: " << cassini.Get_Shape_Type() << std::endl;
    }
    
    void Get_Curvature_Radius(Cassini &cassini) {
        double t = getNum<double>("Angle value in degrees: ");
        
        if (cassini.Get_Curvature_Radius(t) >= 0) {
           std::cout << "Curvature radius = " << cassini.Get_Curvature_Radius(t) << std::endl;
        }
        else {
           std::cout << "Invalid polar angle coordinate!" << std::endl;
        }
    }
    
    void Get_Inflection_Points_Polar_Coordinates(Cassini &cassini) {
        if (cassini.Get_Shape_Type() == "with inflection points") {
           std::cout << "Inflection points polar radius = " << cassini.Get_Inflection_Points_Polar_Radius() << std::endl;
           std::cout << "Inflection points polar angle = " << cassini.Get_Inflection_Points_Polar_Angle() << std::endl;
        }
        else {
           std::cout << "Inflection points don't exist!" << std::endl;
        }
    }
    
    void Get_Equation(Cassini &cassini) {
        std::cout << cassini.Get_Equation() << std::endl;
    }
}