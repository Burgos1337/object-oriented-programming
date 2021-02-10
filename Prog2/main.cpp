#include <iostream>

#include "Cassini.h"
#include "Dialog.h"
#include "util.h"

using namespace Prog2;

int main() {
    try {
        Cassini cassini;
        Dialog(cassini);
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