//
// Created by ellonet on 1/16/19.
//
#include <iostream>

using namespace std;

template<class T, class U, class S>
class survival_kit {
public:

    survival_kit(): first(T()), second(U()),third(S()){}

    survival_kit(T t, U u, S s) : first(t), third(s), second(u){}




    friend ostream &operator<<(ostream &out, const survival_kit &kit) {
        out << kit.first << endl << kit.second << endl << kit.third << endl;
        return out;
    }

    // COPY CONSTRUCTOR DISALLOW
    survival_kit(const survival_kit& other) = delete;

    // MOVE CONSTRUCTOR DISALLOW
    survival_kit(survival_kit && other) = delete;




    T first;
    U second;
    S third;

};



int main() {
//    survival_kit<int, float, double> kit(5, 6.2, 1.9);
//    kit.first = kit.second * kit.third;
//    std::cout << kit;
    const survival_kit<int, int, int> kit(5, 6, 2);
    std::cout << kit;


    return 0;
}