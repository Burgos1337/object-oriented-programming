#include <ctime>
#include <iostream>

#include "include/Dice.h"
#include "dialog.h"
#include "util.h"

using namespace Prog3;

int main() {
    srand(time(NULL));
    int dices_number;
    try {
        dices_number = getNum<int>("Number of dices to operate with: ");
        DICE dice(dices_number);
        dialog(dice);
    }
    catch (const std::length_error& error) {
        std::cout << "Error: " << error.what() << std::endl;
    }
    catch (std::bad_alloc &ba) {
        std::cout << "Error in allocating memory: " << ba.what() << std::endl;
    }
    catch (std::exception &ex) {
        std::cout << "Exception detected: " << ex.what() << std::endl;
    }
    catch (...) {
        std::cout << "Unknown error occured!" << std::endl;
    }
    return 0;
}