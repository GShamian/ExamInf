#include "stdfx.h"
#include <stdexcept>
#include <iostream>


UIntVector::UIntVector(const std::size_t size)
{
    _num_elements = size;
    _size = size;
    if (size < BASE_SIZE)
        _size = BASE_SIZE;
    _elements = new unsigned int[_size];

    reset();
}

UIntVector::UIntVector(const UIntVector& other)
{
    std::size_t size = other.size();
    _elements = new unsigned int[size];
    _size = size;
    _num_elements = size;

    for (std::size_t i = 0; i < _size; ++i)
        _elements[i] = other[i];
}

UIntVector::UIntVector(UIntVector&& other) :
    _elements(other._elements), _size(other._size),
    _num_elements(other._num_elements)
{
    other._elements = nullptr;
    other._size = 0;
    other._num_elements = 0;
}

UIntVector::UIntVector(std::initializer_list<unsigned int> list)
{
    std::size_t size = list.size();
    _elements = new unsigned int[size];
    _size = size;
    _num_elements = 0;

    for (auto v : list)
        add(v);
}

UIntVector::~UIntVector()
{
    delete [] _elements;
}

unsigned int& UIntVector::operator[](const std::size_t x)
{
    if (x < 0)
        throw std::out_of_range("negative index");
    else if (x >= _num_elements)
        throw std::out_of_range("index larger than vector size");
    return _elements[x];
}

const unsigned int& UIntVector::operator[](const std::size_t x) const
{
    if (x < 0)
        throw std::out_of_range("negative index");
    else if (x >= _num_elements)
        throw std::out_of_range("index larger than vector size");
    return _elements[x];
}

UIntVector& UIntVector::operator=(const UIntVector& other)
{
    if (this == &other)
        return *this;
    UIntVector temp = UIntVector(other);
    *this = std::move(temp);
    return *this;
}

UIntVector& UIntVector::operator=(UIntVector&& other)
{
    if (this == &other)
        return *this;
    delete [] _elements;
    _elements = other._elements;
    _size = other._size;
    _num_elements = other._num_elements;
    other._elements = nullptr;
    other._size = 0;
    other._num_elements = 0;
    return *this;
}

const void UIntVector::expand(const int size)
{
    std::size_t new_size       = _size + size;
    unsigned int* new_elements = new unsigned int[new_size];

    std::copy(_elements, _elements + _size, new_elements);
    delete [] _elements;

    _elements = new_elements;
    _size = new_size;
}

const std::size_t UIntVector::size() const
{
    return _num_elements;
}

const void UIntVector::reset()
{
    for (std::size_t i = 0; i < _size; ++i)
        _elements[i] = (unsigned int) {0};
}

const void UIntVector::add(const unsigned int x)
{
    if (_num_elements >= _size)
        expand(_size);

    _elements[_num_elements] = x;
    ++_num_elements;
}
