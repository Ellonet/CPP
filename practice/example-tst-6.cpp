//
// Created by אלה on 16/01/2019.
//

#include <iostream>

using namespace std;

template<class T, int size>
class Vector {
public:
    Vector() {
        for (int i = 0; i<size; i++) {
            vec[i] = 0;
        }
    }
    Vector(const T t) {
        for (int i = 0; i<size; i++) {
            vec[i] = t;
        }
    }

    T& operator[](int index) {
        return vec[index];
    }
    T operator[](int index) const {
        return vec[index];
    }

    T operator*(const Vector &v) const {
        T sum = 0;
        for (int i=0; i<size; ++i) {
            sum += (vec[i]*v.vec[i]);
        }
        return sum;
    }

    friend ostream &operator<<(ostream &out, const Vector &t) {
        out << "{ ";
        for (int i=0; i<size;i++) {
            out << t.vec[i] << " ";
        }
        out << "}";
        return out;
    }



private:
    T vec[size];
};