#include <vector>
#include <cassert>
#include "Vector.h"
#include "VectorTest.h"

int main(int argc, const char** argv) {
    Vector v1;
    Vector v2(5);
    double* data2 = v2.data();
    std::cout << data2[0] << std::endl;

    Vector v3(3, 3);
    double* data3 = v3.data();
    std::cout << data3[2] << std::endl;

    Vector v4({1, 2, 3});
    std::vector<int> tvec1({1, 2, 3});
    assert(v4[0] == 1 && v4[2] == 3);
    assert(v4.size() == 3);
    assert(tvec1.size() == v4.size());
    assert(tvec1.capacity() == v4.capacity());
    assert(tvec1.at(0) == v4.at(0));
    assert(tvec1.at(2) == v4.at(2));
    assert(tvec1.at(0) == v4[0]);
    assert(tvec1.front() == v4.front());
    assert(tvec1.back() == v4.back());
    
    // test reserve()
    reserve_test();

    // test shrink_to_fit()
    shrink_to_fit_test();

    // test resize
    // -----------
    resize_test();

    // test push_back
    push_back_test();

    return 0;
}