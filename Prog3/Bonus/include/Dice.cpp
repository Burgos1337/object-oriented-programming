#include <iostream>
#include <stdexcept>

#include "Dice.h"

namespace Prog3 {
    int rand_t() {
        int s = rand() % 6 + 1;
        return s;
    }

    DICE::DICE() {
        r_number = 0;
        for (int i = 0; i < SIZE; i++) {
            value[i] = 0;
        }
    }

    DICE::DICE(int r_number) {
        if (r_number > SIZE || r_number < 0) {
           throw std::length_error("invalid dices array length!");
        }
        this->r_number = r_number;
        for (int i = 0; i < r_number; i++) {
           value[i] = rand_t();
        }
    }

    DICE::DICE(const int *values, int r_number) {
        this->r_number = r_number;
        for (int i = 0; i < r_number; i++) {
            value[i] = values[i];
        }
    }

    int DICE::get_r_number() const {
        return r_number;
    }

    int DICE::get_sum_of_dice() const {
        int sum = 0;
        for (int i = 0; i < r_number; i++) {
            sum += value[i];
        }
        return sum;
    }

    DICE& DICE::roll_dice() {
        for (int i = 0; i < r_number; i++) {
            value[i] = rand_t();
        }
        return *this;
    }

    std::ostream& operator << (std::ostream& out, const DICE& dice) {
        if (dice.r_number == 0) {
           out << "You don't have any dices now...\n";
           return out;
        }
        for (int i = 0; i < dice.r_number; i++) {
            out << "+---------";
        }
        out << "+\n";
        for (int i = 0; i < dice.r_number; i++) {
            switch (dice.value[i]) {
                case 1:
                    out << "|         ";
                break;
                case 2:
                case 3:
                    out << "| *       ";
                break;
                case 4:
                case 5:
                case 6:
                    out << "| *     * ";
                    break;
            }
        }
        out << "|\n";
        for (int i = 0; i < dice.r_number; i++) {
            switch (dice.value[i]) {
                case 1:
                case 3:
                case 5:
                    out << "|    *    ";
                break;
                case 2:
                case 4:
                    out << "|         ";
                break;
                case 6:
                    out << "| *     * ";
                    break;
            }
        }
        out << "|\n";
        for (int i = 0; i < dice.r_number; i++) {
            switch (dice.value[i]) {
                case 1:
                    out << "|         ";
                    break;
                case 2:
                case 3:
                    out << "|       * ";
                    break;
                case 4:
                case 5:
                case 6:
                    out << "| *     * ";
                    break;
            }
        }
        out << "|\n";
        for (int i = 0; i < dice.r_number; i++) {
            out << "+---------";
        }
        out << "+\n";
        return out;
    }

    bool DICE::find_concurrence() const {
        for (int i = 0; i < r_number; i++) {
            int current = value[i];
            for (int j = 0; j < r_number; j++) {
                if (i == j) break;
                if (value [j] == current) return true;
            }
        }
        return false;
    }

    DICE& DICE::operator += (int value) {
        if (r_number + 1 > SIZE) {
           throw std::length_error("dices array overflow!");
        }
        if (value < 1 || value > 6) {
           throw std::invalid_argument("invalid argument!");
        }
        r_number++;
        this->value[r_number - 1] = value;
        return *this;
    }

    DICE& DICE::operator -= (int value) {
        int check = 0;
        if (value > 6 || value < 1) {
           throw std::invalid_argument("invalid argument!");
        }
        for (int i = 0; i < r_number; i++) {
            if (this->value[i] == value) {
               check++;
            }
            else {
               this->value[i - check] = this->value[i];
            }
        }
        r_number = r_number - check;
        if (check == 0) {
           throw std::logic_error("no dice found for your request!");
        }
        return *this;
    }

    int& DICE::operator [] (int value) {
        if (value > r_number || value < 1) {
           throw std::invalid_argument("this dice doesn't exist!");
        }
        return this->value[value - 1];
    }
}