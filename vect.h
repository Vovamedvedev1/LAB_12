#ifndef VECT_H_INCLUDED
#define VECT_H_INCLUDED


#include <iostream>
#include <typeinfo>
#include <string>
using namespace std;



template <typename T>
class Vector
{
private:
    size_t size;
    T* data;
public:
    Vector() : size(0), data(nullptr) {}
    Vector(size_t size) : size(size)
    {
        this->data = new T[size];
    }
    Vector(Vector& other)
    {
        this->size = other.size;
        this->data = new T[size];
        for (size_t i = 0; i < size; ++i)
        {
            data[i] = other.data[i];
        }
    }
    const Vector<T> operator=(const Vector<T> other)
    {
        if (this == &other)
            return *this;
        if (this->data != nullptr)
            delete[] this->data;
        this->size = other.size;
        this->data = new T[this->size];
        for (int i = 0; i < this->size; i++)
            this->data[i] = other.data[i];
        return *this;
    }
    ~Vector()
    {
        if (data == nullptr)
            return;
        delete[] data;
    }
    T& operator[](size_t index)
    {
        return this->data[index];
    }
    size_t getSize()
    {
        return this->size;
    }
    friend std::ostream& operator<<(std::ostream& os, const Vector<T>& vec)
    {
        os << "[";
        for (size_t i = 0; i < vec.size; ++i)
        {
            os << vec.data[i];
            if (i != vec.size - 1)
                os << " ";
        }
        os << "]";
        return os;
    }
    friend std::istream& operator>>(std::istream& is, const Vector<T>& vec)
    {
        std::cout << "Input elements of vector:  ";
        for (size_t i = 0; i < vec.size; ++i)
            is >> vec.data[i];
        return is;
    }
    template <typename T1>
    Vector<T1>operator+(Vector<T1>& other)
    {
        if (this->getSize() != other.getSize())
            throw "Error out of range";
        Vector<T1> temp(this->size);
        for (int i = 0; i < this->getSize(); ++i)
            temp[i] = (*this)[i] + other[i];
        return temp;
    }
    template <typename T1>
    Vector<T>operator-(Vector<T1>& other)
    {
        if (this->getSize() != other.getSize())
            throw "Error out of range";
        Vector<T> temp(this->size);
        for (int i = 0; i < this->getSize(); ++i)
            temp[i] = (*this)[i] - other[i];
        return temp;
    }
    template <typename T1>
    T1 operator*(Vector<T1>& other)
    {
        if (this->getSize() != other.getSize())
            throw "Error out of range";
        T1 sizem = 0;
        for (int i = 0; i < this->size; i++)
            sizem += (*this)[i] * other[i];
        return sizem;
    }
};

template <>
class Vector<string>
{
private:
    size_t size;
    string* data;
public:
    Vector() : size(0), data(nullptr) {}
    Vector(size_t size) : size(size)
    {
        this->data = new string[size];
    }
    Vector(Vector& other)
    {
        this->size = other.size;
        this->data = new string[size];
        for (size_t i = 0; i < size; ++i)
        {
            data[i] = other.data[i];
        }
    }
    const Vector<string> operator=(const Vector<string> other)
    {
        if (this == &other)
            return *this;
        if (this->data != nullptr)
            delete[] this->data;
        this->size = other.size;
        this->data = new string[this->size];
        for (int i = 0; i < this->size; i++)
            this->data[i] = other.data[i];
        return *this;
    }
    ~Vector()
    {
        if (data == nullptr)
            return;
        delete[] data;
    }
    string& operator[](size_t index)
    {
        return this->data[index];
    }
    size_t getSize()
    {
        return this->size;
    }
    friend std::ostream& operator<<(std::ostream& os, const Vector<string>& vec)
    {
        os << "[";
        for (size_t i = 0; i < vec.size; ++i)
        {
            os << '|' << vec.data[i];
            if (i != vec.size - 1)
                os << " ";
        }
        os << "]";
        return os;
    }
    friend std::istream& operator>>(istream& is, const Vector<string>& vec)
    {
        vec.data[0] = "";
        while(vec.data[0] == "")
            getline(is, vec.data[0]);
        for (size_t i = 1; i < vec.size; ++i)
            getline(is, vec.data[i]);
        return is;
    }
    Vector<string>operator+(Vector<string>& other)
    {
        if (this->getSize() != other.getSize())
            throw "Error out of range";
        Vector<string> temp(this->size);
        for (int i = 0; i < this->getSize(); ++i)
            temp[i] = (*this)[i] + "_" + other[i];
        return temp;
    }
    Vector<string> operator-(Vector<string>& other)
    {
        if (this->getSize() != other.getSize())
            throw "Error out of range";
        Vector<string> temp(this->size);
        for (int i = 0; i < this->getSize(); ++i)
        {
            temp.data[i] = "";
            for (int j = 0; j < this->data[i].length(); ++j)
            {
                if (other.data[i].find_first_of(this->data[i][j]) == -1)
                    temp.data[i] += this->data[i][j];
            }
        }
        return temp;
    }
    string operator*(Vector<string>& other)
    {
        if (this->getSize() != other.getSize())
            throw "Error out of range";
        string sizem = "";
        for (int i = 0; i < this->size; i++)
        {
            sizem += (*this)[i] + "_" + other[i];
            if (i != this->size - 1)
                sizem += "///";
        }
        return sizem;
    }
};


#endif // VECT_H_INCLUDED
