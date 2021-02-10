#pragma once

#include <iostream>

namespace Prog3C {
    template <typename T>
    T getNum(const char *msg) {
        std::cout << msg;
        T num = 0;
        while (!(std::cin >> num)) {
           std::cout << "Try again: ";
           if (std::cin.eof()) {
              break;
           }
           std::cin.clear();
           std::cin.ignore();
        }
        return num;
    }
}