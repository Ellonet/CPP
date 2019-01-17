//
// Created by אלה on 16/01/2019.
//

#include <iostream>

using namespace std;
template<class T>
class BigNumber {
public:
    BigNumber(const T base, const T exponent) : _base(base), _exp(exponent) {}

    BigNumber<T> operator+(const BigNumber<T>& other) const {
        T bigger = _exp;
        if (_exp < other._exp) {
            bigger = other._exp;
        }
        return (BigNumber<T>(_base+other._base, bigger));
    }

    BigNumber<T> operator*(const BigNumber& other) const {
        return (BigNumber<T>(_base*other._base, _exp+other._exp));
    }

    friend ostream &operator<<(ostream &out, const BigNumber &t) {
        out << t._base << "e" << t._exp;
        return out;
    }


private:
    T _base;
    T _exp;
};