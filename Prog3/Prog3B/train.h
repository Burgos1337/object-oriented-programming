#pragma once

#include <iosfwd>

namespace Prog3B {
    struct carriage {
        int maximum_capacity;
        int occupied_seats_number;
        carriage();
        carriage(const int maximum_capacity, const int occupied_seats_number);
        carriage& set_carriage(const int maximum_capacity, const int occupied_seats_number);
    };
    class train {
    private:
        struct carriage *cars;
        int length;
        void cars_push_back(const carriage& main_carriage);
        void swap(train& another);
    public:
        train();
        train(struct carriage *&cars, const int length);
        train(const train& another);
        train(train&& another) noexcept;
        ~train();
        train& set_carriages(struct carriage *&cars, const int length);
        int get_length() const noexcept;
        struct carriage *get_carriages() const;
        friend std::istream& operator >> (std::istream& in, train& main_train);
        friend std::ostream& operator << (std::ostream& out, const train& main_train);
        train& operator = (const train& another);
        train& operator = (train&& another) noexcept;
        train& operator () (const int carriage_index, const int seats_number);
        const int& operator [] (const int carriage_index) const;
        train& operator += (const carriage& main_carriage);
        train& operator ( ) (const int carriages_number, int *min_train);
        int get_passengers_number() const;
    };
}