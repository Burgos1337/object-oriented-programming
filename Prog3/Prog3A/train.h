#pragma once

#include <iosfwd>

namespace Prog3A {
    struct carriage {
        int maximum_capacity;
        int occupied_seats_number;
        carriage();
        carriage(int maximum_capacity, int occupied_seats_number);
        carriage& set_carriage(int maximum_capacity, int occupied_seats_number);
    };
    class train {
    private:
        struct carriage cars[100];
        int length;
    public:
        train();
        train(struct carriage *cars, int length);
        train& set_length(int length);
        train& set_carriages(struct carriage *cars);
        int get_length();
        struct carriage *get_carriages();
        friend std::istream& operator >> (std::istream& in, train& main_train);
        friend std::ostream& operator << (std::ostream& out, const train& main_train);
        train& operator () (int carriage_index, int seats_number);
        int& operator [] (int carriage_index);
        train& operator += (carriage& main_carriage);
        train& operator ( ) (int carriages_number, int *min_train);
        int get_passengers_number();
    };
}