#pragma once

#include <iostream>

#include "include/Dice.h"
#include "util.h"

namespace Prog3 {
    void dialog(DICE& dice);
    void menu();
    void dice_output(DICE& dice);
    void average_of_average(DICE& dice);
    void try_your_luck(DICE& dice);
    void deleting_concurrences(DICE& dice);
    void another_test_for_your_luck(DICE& dice);
    void table_game(DICE& dice);
}