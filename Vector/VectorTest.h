#include <vector>
#include <iostream>
#include <cassert>
#include "Vector.h"

void reserve_test() {
    Vector v5({0, 1, 2, 3, 4, 5});
    std::vector<double> tv5({0, 1, 2, 3, 4, 5});
    assert(v5.capacity() == tv5.capacity());
    v5.reserve(3);
    tv5.reserve(3);
    assert(v5.capacity() == tv5.capacity());
    v5.reserve(30);
    tv5.reserve(30);
    assert(v5.capacity() == tv5.capacity());
    assert(v5.size() == tv5.size());
    assert(v5[5] == tv5[5]);
    assert(v5.at(4) == tv5.at(4));
    // You can actually access index 29 with operator[] without triggering sig fault bc it doesn't do bound checking
    v5[29] = tv5[29] = 5;
    assert(v5[29] == tv5[29]);
}

void shrink_to_fit_test() {
    Vector v6({0, 1, 2, 3, 4, 5});
    std::vector<double> tv6({0, 1, 2, 3, 4, 5});
    v6.reserve(10);
    tv6.reserve(10);
    assert(tv6.capacity() == v6.capacity());  
    tv6.shrink_to_fit();
    v6.shrink_to_fit();
    assert(tv6.capacity() == v6.capacity());
}

void resize_test() {
    Vector v7({0, 1, 2, 3, 4, 5});
    std::vector<double> tv7({0, 1, 2, 3, 4, 5});
    // case 1 new_size == _size
    v7.resize(6);
    tv7.resize(6);
    assert(tv7.capacity() == v7.capacity());
    assert(tv7.size() == v7.size());

    // case 2 new_size < _size
    tv7.resize(3);
    v7.resize(3);
    assert(tv7.size() == v7.size());
    //std::cout << "tv7.capacity = " << tv7.capacity() << std::endl;
    assert(tv7.capacity() == v7.capacity());
    assert(v7.at(2) == tv7.at(2));

    // case3 new_size > _size
    tv7.resize(30);
    v7.resize(30);
    assert(tv7.size() == v7.size());
    //std::cout << "tv7.capacity = " << tv7.capacity() << std::endl;
    //std::cout << "tv7.size = " << tv7.size() << std::endl;
    assert(tv7.capacity() == v7.capacity());
    assert(v7[29] == tv7[29]);
    assert(v7.at(20) == tv7.at(20));

    // case 4 new_size > _size with a custom value
    tv7.resize(30, 500);
    tv7.resize(30, 500);
    assert(tv7.size() == v7.size());
    //std::cout << "tv7.capacity = " << tv7.capacity() << std::endl;
    //std::cout << "tv7.size = " << tv7.size() << std::endl;
    assert(tv7.capacity() == v7.capacity());
    assert(v7[29] == tv7[29]);
    assert(v7.at(20) == tv7.at(20));
}

void push_back_test() {
    Vector v8(5, 5);
    size_t old_size = v8.size();
    size_t old_capacity = v8.capacity();
    v8.push_back(6);
    assert(v8.size() == old_size + 1);
    assert(v8.capacity() == 2 * old_capacity);
    assert(v8.at(5) == 6);
}