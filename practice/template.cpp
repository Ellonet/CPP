#include <iostream>
#include <cmath>

using namespace std;

template <class T, int size>
class MeasurementContainer {

private:
    T vals[size];


public:
    explicit MeasurementContainer(T* arr) {
        for (int i = 0; i < size; i++) {
            vals[i] = *(arr + i);
        }
    }

    double average() const {
        double sum = 0;
        for (int i=0; i<size; ++i) {
            sum += vals[i];
        }
        return sum / size;
    }

    double rmse(const MeasurementContainer &other) const {
        double sum = 0;
        for (int i=0; i<size; ++i) {
            sum += pow((vals[i]-other.vals[i]), 2);
        }
        return sqrt(sum/size);
    }

    friend ostream &operator<<(ostream &out, const MeasurementContainer &M) {
        for (int i=0; i<size; ++i) {
            out << M.vals[i] << " ";
        }
        return out;
    }

};