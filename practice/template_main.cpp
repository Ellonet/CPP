//
// Created by ellonet on 1/15/19.
//
#include "template.cpp"

int main() {
    double measurements[10] = { 1.0, 2.0, 1.5, 0.75, 1.3, 1.45, 1.4, 1.75, 1.6, 1.55};
    double measurements2[10] = { 1.1, 1.9, 1.0, 0.85, 1.2, 1.4, 1.6, 1.7, 1.6, 1.65};
    MeasurementContainer<double, 10> c(measurements);
    MeasurementContainer<double, 10> c2(measurements2);

    std::cout << c.average() << std::endl;
    std::cout << c2.average() << std::endl;

    std::cout << c.rmse(c2) << std::endl;



    return 0;
}