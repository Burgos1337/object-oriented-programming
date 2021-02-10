#include <iostream>
#include <stdexcept>

#include "train.h"

namespace Prog3A {
    carriage::carriage() {
        this->maximum_capacity = 0;
        this->occupied_seats_number = 0;
    }
    
    carriage::carriage(int maximum_capacity, int occupied_seats_number) {
        this->set_carriage(maximum_capacity, occupied_seats_number);
    }
    
    carriage& carriage::set_carriage(int maximum_capacity, int occupied_seats_number) {
        if (maximum_capacity < 0 || occupied_seats_number < 0 || maximum_capacity < occupied_seats_number) {
           throw std::invalid_argument("invalid carriage parameters!");
        }
        
        this->maximum_capacity = maximum_capacity;
        this->occupied_seats_number = occupied_seats_number;
        
        return *this;
    }
    
    train::train() {
        this->cars[0] = { 0, 0 };
        this->length = 1;
    }
    
    train::train(struct carriage *cars, int length) {
        this->set_length(length);
        this->set_carriages(cars);
    }
    
    train& train::set_length(int length) {
        if (length < 1 || length > 100) {
           throw std::length_error("invalid train length!");
        }

        this->length = length;
        
        return *this;
    }
    
    train& train::set_carriages(struct carriage *cars) {
        this->cars[0] = { 0, 0 };
        for (int i = 0; i < this->length - 1; i++) {
            this->cars[i + 1] = cars[i];
        }
        
        return *this;
    }
    
    int train::get_length() {
        return this->length;
    }
    
    struct carriage *train::get_carriages() {
        return this->cars;
    }
    
    std::istream& operator >> (std::istream& in, train& main_train) {
        int maximum_capacity, occupied_seats_number, carriages_number;

        in >> carriages_number;
        if (carriages_number < 1 || carriages_number > 100) {
           throw std::invalid_argument("invalid carriages number!");
        }
        
        for (int i = 0; i < carriages_number; i++) {
            in >> maximum_capacity;
            in >> occupied_seats_number;
            if (maximum_capacity < occupied_seats_number) {
               throw std::invalid_argument("invalid carriage parameters!");
            }
        
            main_train.cars[main_train.length].maximum_capacity = maximum_capacity;
            main_train.cars[main_train.length].occupied_seats_number = occupied_seats_number;
            main_train.length++;
        }
        
        return in;
    }
    
    std::ostream& operator << (std::ostream& out, const train& main_train) {
        for (int i = 0; i < main_train.length; i++) {
            out << "Carriage #" << i << " occupancy: " << main_train.cars[i].occupied_seats_number << " passenger(s)\n";
        }
        
        return out;
    }
    
    train& train::operator () (int carriage_index, int seats_number) {
        if (carriage_index < 1 || carriage_index > this->length - 1) {
           throw std::invalid_argument("invalid carriage index!");
        }

        if (seats_number < 0 || seats_number >= this->cars[carriage_index].maximum_capacity - this->cars[carriage_index].occupied_seats_number) {
           throw std::invalid_argument("invalid seats number!");
        }

        this->cars[carriage_index].occupied_seats_number += seats_number;
        
        return *this;
    }
    
    int& train::operator [] (int carriage_index) {
        if (carriage_index < 1 || carriage_index > this->length - 1) {
           throw std::invalid_argument("invalid carriage index!");
        }
        
        return this->cars[carriage_index].occupied_seats_number;
    }
    
    train& train::operator += (carriage& main_carriage) {
        if (this->length == 100) {
           throw std::logic_error("unable to add carriage!");         
        }
        
        this->cars[this->length] = main_carriage;
        this->length++;
        
        return *this;
    }
    
    train& train::operator ( ) (int carriages_number, int *min_train) {
        if (carriages_number < 1 || carriages_number > this->length - 1) {
           throw std::invalid_argument("invalid carriages number!");
        }

        for (int i = 0; i < carriages_number; i++) {
            for (int j = min_train[i] - i; j < this->length; j++) {
                cars[j] = cars[j + 1];
            }
            this->length--;
        }
        
        return *this;
    }
    
    int train::get_passengers_number() {
        int passengers_number = 0;
        
        for (int i = 0; i < this->length; i++) {
            passengers_number += this->cars[i].occupied_seats_number;
        }
        
        return passengers_number;
    }
}