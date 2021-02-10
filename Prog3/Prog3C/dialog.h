#pragma once

#include <iostream>

#include "include/train.h"
#include "util.h"

namespace Prog3C {
    void dialog(train& main_train);
    void menu();
    void set_train(train& main_train);
    void get_train_occupancy_information(train& main_train);
    void occupy_seats(train& main_train);
    void get_carriage_occupancy_information(train& main_train);
    void add_carriage(train& main_train);
    void unhook_train(train& main_train);
    void get_passengers_number(train& main_train);
}