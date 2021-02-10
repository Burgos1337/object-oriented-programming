#pragma once

#include <iostream>

#define SIZE 10

namespace Prog3 {
    class DICE {
        private:
            int value[SIZE];
            int r_number;
        public:
            DICE();
            DICE(int r_number);
            DICE(const int *values, int r_number);
            int get_r_number() const;
            int get_sum_of_dice() const;
            friend std::ostream& operator << (std::ostream& out, const DICE& dice);
            DICE& roll_dice();
            bool find_concurrence() const;
            DICE& operator += (int value);
            DICE& operator -= (int value);
            int& operator [] (int value);
    };
}