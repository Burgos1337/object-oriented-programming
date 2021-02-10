#include <math.h>

#include "gtest/gtest.h"

#include "Cassini.cpp"

using namespace Prog2;

TEST(Cassini_Constructor, Default_Constructor) {
    Cassini cassini;
    ASSERT_NO_THROW(cassini);
    ASSERT_EQ(0, cassini.Get_Distance());
    ASSERT_EQ(0, cassini.Get_Focal_Parameter());
}

TEST(Cassini_Constructor, Initial_Constructor) {
    Cassini cassini_1(4, 3);
    ASSERT_NO_THROW(cassini_1);
    ASSERT_EQ(4, cassini_1.Get_Distance());
    ASSERT_EQ(3, cassini_1.Get_Focal_Parameter());
    ASSERT_ANY_THROW(Cassini cassini_2(-7, 9));
    ASSERT_ANY_THROW(Cassini cassini_3(12, -5));
}

TEST(Cassini_Methods, Setters) {
    Cassini cassini;
    ASSERT_NO_THROW(cassini.Set_Distance(8));
    ASSERT_EQ(8, cassini.Get_Distance());
    ASSERT_NO_THROW(cassini.Set_Focal_Parameter(6));
    ASSERT_EQ(6, cassini.Get_Focal_Parameter());
    ASSERT_ANY_THROW(cassini.Set_Distance(-4));
    ASSERT_ANY_THROW(cassini.Set_Focal_Parameter(-3));
}

TEST(Cassini_Methods, Center_Distance) {
    Cassini cassini(6, 5);
    ASSERT_EQ(fabs(pow(5, 2) * cos(M_PI / 3) + sqrt(pow(5, 4) * pow(cos(M_PI / 3), 2) + pow(6, 4) - pow(5, 4))), cassini.Get_Center_Distance(30));
}

TEST(Cassini_Methods, Shape_Type) {
    Cassini cassini_1;
    ASSERT_EQ("point of origin", cassini_1.Get_Shape_Type());
    Cassini cassini_2(0, 2);
    ASSERT_EQ("two points", cassini_2.Get_Shape_Type());
    Cassini cassini_3(4, 0);
    ASSERT_EQ("circle", cassini_3.Get_Shape_Type());
    Cassini cassini_4(3, 4);
    ASSERT_EQ("two separate ovals", cassini_4.Get_Shape_Type());
    Cassini cassini_5(7, 7);
    ASSERT_EQ("lemniscate", cassini_5.Get_Shape_Type());
    Cassini cassini_6(6, 5);
    ASSERT_EQ("with inflection points", cassini_6.Get_Shape_Type());
    Cassini cassini_7(15, 8);
    ASSERT_EQ("oval", cassini_7.Get_Shape_Type());
}

TEST(Cassini_Methods, Curvature_Radius) {
    Cassini cassini(8, 6);
    double r = fabs(pow(6, 2) * cos(M_PI / 2) + sqrt(pow(6, 4) * pow(cos(M_PI / 2), 2) + pow(8, 4) - pow(6, 4)));
    ASSERT_EQ((pow(8, 2) * r / (pow(r, 2) + cos(M_PI / 2) * pow(6, 2))), cassini.Get_Curvature_Radius(45));
}

TEST(Cassini_Methods, Inflection_Points_Coordinates) {
    Cassini cassini(5, 4);
    ASSERT_EQ((pow(((pow(5, 4) - pow(4, 4)) / 3), 0.25)), cassini.Get_Inflection_Points_Polar_Radius());
    ASSERT_EQ((acos((-1) * sqrt(((pow(5, 4) / pow(4, 4)) - 1) / 3))) * 180 / (2 * M_PI), cassini.Get_Inflection_Points_Polar_Angle());
}

TEST(Cassini_Methods, Equation_NULL) {
    Cassini cassini;
    ASSERT_EQ("(x ^ 2 + y ^ 2) ^ 2 = 0", cassini.Get_Equation());
}

TEST(Cassini_Methods, Equation_Not_NULL) {
    Cassini cassini(2, 3);
    ASSERT_EQ("(x ^ 2 + y ^ 2) ^ 2 - 18 * (x ^ 2 - y ^ 2) = -65", cassini.Get_Equation());
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}