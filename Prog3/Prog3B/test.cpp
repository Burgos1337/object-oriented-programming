#include <sstream>

#include "gtest/gtest.h"

#include "train.cpp"

using namespace Prog3B;

TEST(carriage_constructor, default_constructor) {
    ASSERT_NO_THROW(carriage main_carriage);
}

TEST(carriage_constructor, initial_constructor) {
    ASSERT_NO_THROW(carriage main_carriage_1(14, 8));
    ASSERT_ANY_THROW(carriage main_carriage_2(5, 9));
    ASSERT_ANY_THROW(carriage main_carriage_3(-2, 3));
    ASSERT_ANY_THROW(carriage main_carriage_2(7, -4));
}

TEST(carriage_method, setter) {
    carriage main_carriage_1;
    ASSERT_NO_THROW(main_carriage_1.set_carriage(12, 5));
    carriage main_carriage_2;
    ASSERT_ANY_THROW(main_carriage_2.set_carriage(6, 13));
    carriage main_carriage_3;
    ASSERT_ANY_THROW(main_carriage_3.set_carriage(-3, 18));
    carriage main_carriage_4;
    ASSERT_ANY_THROW(main_carriage_4.set_carriage(15, -9));
}

TEST(train_constructor, default_constructor) {
    train main_train;
    ASSERT_NO_THROW(main_train);
    ASSERT_EQ(1, main_train.get_length());
    ASSERT_EQ(0, main_train.get_carriages()[0].maximum_capacity);
    ASSERT_EQ(0, main_train.get_carriages()[0].occupied_seats_number);
}

TEST(train_constructor, initial_constructor) {
    carriage main_carriage_1(7, 3);
    carriage main_carriage_2(12, 7);
    struct carriage *cars = new struct carriage[2];
    cars[0] = main_carriage_1;
    cars[1] = main_carriage_2;
    train main_train_1(cars, 3);
    ASSERT_NO_THROW(main_train_1);
    ASSERT_EQ(3, main_train_1.get_length());
    ASSERT_ANY_THROW(train main_train_2(cars, -10));
    train main_train_3(cars, 0);
    ASSERT_EQ(nullptr, main_train_3.get_carriages());
}

TEST(train_constructor, copying_constructor) {
    carriage main_carriage_1(7, 3);
    carriage main_carriage_2(12, 7);
    struct carriage *cars = new struct carriage[2];
    cars[0] = main_carriage_1;
    cars[1] = main_carriage_2;
    train main_train(cars, 3);
    train main_train_copy(main_train);
    ASSERT_NO_THROW(main_train_copy);
    ASSERT_EQ(3, main_train_copy.get_length());
}

TEST(train_methods, basic_methods) {
    carriage main_carriage_1(6, 4);
    carriage main_carriage_2(11, 5);
    struct carriage *cars = new struct carriage[2];
    cars[0] = main_carriage_1;
    cars[1] = main_carriage_2;
    train main_train_1;
    ASSERT_NO_THROW(main_train_1.set_carriages(cars, 3));
    ASSERT_ANY_THROW(train main_train_2(cars, -7));
    train main_train_3(cars, 0);
    ASSERT_EQ(nullptr, main_train_3.get_carriages());
}

TEST(train_methods, input) {
    carriage main_carriage_0;
    carriage main_carriage_1(12, 7);
    carriage main_carriage_2(14, 5);
    carriage main_carriage_3(11, 6);
    struct carriage *cars = new struct carriage[4];
    cars[0] = main_carriage_0;
    cars[1] = main_carriage_1;
    cars[2] = main_carriage_2;
    cars[3] = main_carriage_3;  
    train main_train;
    std::stringstream ss_1, ss_2;
    ss_1 << "-2";
    ASSERT_ANY_THROW(ss_1 >> main_train);
    ss_2 << "3 12 7 14 5 11 6";
    ASSERT_NO_THROW(ss_2 >> main_train);
    ASSERT_EQ(4, main_train.get_length());
    ASSERT_TRUE(0 == memcmp(cars, main_train.get_carriages(), sizeof(cars)));
}

TEST(train_methods, output) {
    carriage main_carriage_1(5, 2);
    carriage main_carriage_2(12, 9);
    struct carriage *cars = new struct carriage[2];
    cars[0] = main_carriage_1;
    cars[1] = main_carriage_2;
    train main_train(cars, 3);
    std::stringstream ss;
    ss << main_train;
    ASSERT_EQ("Carriage #0 occupancy: 0 passenger(s)\nCarriage #1 occupancy: 2 passenger(s)\nCarriage #2 occupancy: 9 passenger(s)\n", ss.str());
}

TEST(train_methods, assignment) {
    carriage main_carriage_1(18, 7);
    carriage main_carriage_2(8, 5);
    struct carriage *cars = new struct carriage[2];
    cars[0] = main_carriage_1;
    cars[1] = main_carriage_2;
    train main_train_1(cars, 3);
    train main_train_2;
    ASSERT_NO_THROW(main_train_2 = main_train_1);
    ASSERT_EQ(3, main_train_2.get_length());
}

TEST(train_methods, occupy_seats) {
    carriage main_carriage_1(18, 7);
    carriage main_carriage_2(52, 32);
    struct carriage *cars = new struct carriage[2];
    cars[0] = main_carriage_1;
    cars[1] = main_carriage_2;
    train main_train(cars, 3);
    ASSERT_ANY_THROW(main_train(-3, 7));
    ASSERT_ANY_THROW(main_train(1, -6));
    ASSERT_ANY_THROW(main_train(3, 8));
    ASSERT_ANY_THROW(main_train(1, 15));
    ASSERT_NO_THROW(main_train(1, 5));
    ASSERT_EQ(12, main_train.get_carriages()[1].occupied_seats_number);
}

TEST(train_methods, carriage_occupancy_information) {
    carriage main_carriage_1(22, 15);
    carriage main_carriage_2(31, 12);
    struct carriage *cars = new struct carriage[2];
    cars[0] = main_carriage_1;
    cars[1] = main_carriage_2;
    train main_train(cars, 3);
    ASSERT_ANY_THROW(main_train[-2]);
    ASSERT_ANY_THROW(main_train[7]);
    ASSERT_NO_THROW(main_train[1]);
    ASSERT_EQ(15, main_train[1]);
}

TEST(train_methods, add_carriage) {
    carriage main_carriage_1(9, 4);
    carriage main_carriage_2(27, 16);
    carriage main_carriage_3(18, 13);
    struct carriage *cars = new struct carriage[2];
    cars[0] = main_carriage_1;
    cars[1] = main_carriage_2;
    train main_train(cars, 3);
    main_train += main_carriage_3;
    ASSERT_EQ(4, main_train.get_length());
    ASSERT_EQ(18, main_train.get_carriages()[3].maximum_capacity);
    ASSERT_EQ(13, main_train.get_carriages()[3].occupied_seats_number);
}

TEST(train_methods, train_unhook) {
    carriage main_carriage_1(32, 17);
    carriage main_carriage_2(23, 14);
    carriage main_carriage_3(45, 22);
    carriage main_carriage_4(19, 11);
    struct carriage *cars = new struct carriage[4];
    cars[0] = main_carriage_1;
    cars[1] = main_carriage_2;
    cars[2] = main_carriage_3;
    cars[3] = main_carriage_4;
    train main_train(cars, 5);
    int min_train[2] = { 2, 4 };
    ASSERT_ANY_THROW(main_train( -7, min_train ));
    ASSERT_ANY_THROW(main_train( 9, min_train ));
    ASSERT_NO_THROW(main_train( 2, min_train ));
    ASSERT_EQ(3, main_train.get_length());
    ASSERT_EQ(45, main_train.get_carriages()[2].maximum_capacity);
    ASSERT_EQ(22, main_train.get_carriages()[2].occupied_seats_number);
}

TEST(train_methods, passengers_number) {
    carriage main_carriage_1(8, 3);
    carriage main_carriage_2(49, 36);
    struct carriage *cars = new struct carriage[2];
    cars[0] = main_carriage_1;
    cars[1] = main_carriage_2;
    train main_train(cars, 3);
    ASSERT_EQ(39, main_train.get_passengers_number());
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}