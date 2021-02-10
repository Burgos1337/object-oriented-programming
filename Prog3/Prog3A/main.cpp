#include <iostream>

#include "train.h"
#include "dialog.h"
#include "util.h"

using namespace Prog3A;

int main() {
    try {
        train main_train;
        dialog(main_train);
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