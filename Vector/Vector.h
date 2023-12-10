#include <iostream>
#include <algorithm>

class Vector {
public:
    // constructors and destructors
    Vector();
    Vector(std::size_t);
    Vector(std::size_t, double);
    Vector(std::initializer_list<double>);
    ~Vector();

    // accessors
	double& at(std::size_t);
	double& operator[](std::size_t);
	double& front();
	double& back();
	
    // Capacity
    double* data() const;
    std::size_t size() const;
    std::size_t capacity() const;
    bool empty() const;
    void reserve(size_t);
    void shrink_to_fit();

    // Modifiers
	void push_back(double);
	void pop_back();
    void resize(size_t);
    void resize(size_t, double);
	void clear();

private:
    double* _data;
    std::size_t _size;
    std::size_t _capacity;
};

Vector::Vector()
    : _data{new double[0]}, _size{0}, _capacity{0}
{}

Vector::Vector(std::size_t size)
    : _data{new double[size]}, _size{size}, _capacity{size}
{
    for (int i = 0; i < size; ++i) {
        _data[i] = {};
    }
}

Vector::Vector(std::size_t size, double val)
    : _data{new double[size]}, _size{size}, _capacity{size}
{
    for (int i = 0; i < size; ++i) {
        _data[i] = val;
    }
}

Vector::Vector(std::initializer_list<double> ilist) 
    : _data{new double[ilist.size()]}, _size{ilist.size()}, _capacity{ilist.size()}
{
    int i = 0;
    for (auto& e : ilist)
    {
        *(_data + i) = e;
        ++i;
    }
}

Vector::~Vector() {
	delete[] _data;
}

double& Vector::at(std::size_t idx) {
    if (idx > _size || idx < 0)
        throw std::out_of_range("index greater than the size or less than zero is not allowed");

    return *(_data + idx);   
}

double& Vector::operator[](std::size_t idx) {
    return *(_data + idx);
}

double& Vector::front() {
    return *_data;
}

double& Vector::back() {
    return *(_data + (_size - 1));  // or, _data[_size - 1]
}

double* Vector::data() const {
    return _data;
}

std::size_t Vector::size() const {
    return _size;
}

std::size_t Vector::capacity() const {
    return _capacity;
}

bool Vector::empty() const {
    return _size == 0;
}

void Vector::reserve(size_t new_cap) {
    if (new_cap == 0 || new_cap <= capacity())
        return;
    
    double* temp = new double[new_cap];
    std::copy(_data, _data + capacity(), temp);
    delete[] _data;
    _data = temp;
    _capacity = new_cap;
}

void Vector::shrink_to_fit() {
    if (_capacity == _size)
        return;

    double* temp = new double[_size];
    std::copy(_data, _data + _size, temp);
    delete[] _data;
    _data = temp;
    _capacity = _size;
}

void Vector::push_back(double val) {
    if (_size == _capacity)
        reserve(2*_size);
    
    *(_data+_size) = val;
    ++_size;
}

void Vector::pop_back() {
    --_size;
}

void Vector::resize(size_t new_size) {
    if (_size == new_size)
        return;
    else if (_size > new_size)
        _size = new_size;
    else {
        double* temp = new double[new_size];
        std::copy(_data, _data + _size, temp);
        delete[] _data;
        _data = temp;

        for (size_t i = _size; i < new_size; i++)
        {
            *(_data + i) = {};
        }
        
        _capacity = _size = new_size;
    }
}

void Vector::resize(size_t new_size, double val) {
    if (_size == new_size)
        return;
    else if (_size > new_size)
        _size = new_size;
    else {
        double* temp = new double[new_size];
        std::copy(_data, _data + _size, temp);
        delete[] _data;
        _data = temp;

        for (size_t i = _size; i < new_size; i++)
        {
            *(_data + i) = val;
        }
        
        _capacity = _size = new_size;
    }
}

void Vector::clear() {
    _size = 0;
}