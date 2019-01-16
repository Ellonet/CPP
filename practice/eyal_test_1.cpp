//
// Created by ellonet on 1/16/19.
//

#include <algorithm>
#include <iostream>

#define SIZE 10

class safe_array {

public:

    safe_array() : _data(new double[SIZE]) {};

    safe_array(const safe_array &other) : _data(new double[SIZE]) {

        for (int i = 0; i < SIZE; ++i) {

            _data[i] = other._data[i];

        }

    };

    safe_array(safe_array &&other) : _data(other._data) { other._data = nullptr; };

    safe_array &operator=(safe_array other) {

        using std::swap;

        swap(*this, other);

        return *this;

    };

    ~safe_array() noexcept { delete _data; };


    double &operator[](int index) {

        if (index < 0 || index >= SIZE) {
//            throw "Bad indexing amigo";
            throw std::logic_error("Bad indexing my friend");
        }

        return _data[index];

    };

    friend void swap(safe_array &a1, safe_array &a2) {

        double *temp = a1._data;

        a1._data = a2._data;

        a2._data = temp;

    };


private:

    double *_data;

};



//int main() {
//    safe_array arr;
//    arr[0] = 1;
//    std::cout << arr[0] << std::endl;
//
//    safe_array arr1;
//    try {
//        arr1[12] = 1;
//        std::cout << "No exception" << std::endl;
//    }
//    catch (std::exception &e) {
//        std::cout << "Caught exception" << std::endl;
//    }
//
//    return 0;
//}