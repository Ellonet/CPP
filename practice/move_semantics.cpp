//
// Created by ellonet on 1/15/19.
//
#include <vector>
#include <string>
#include <iostream>

using namespace std;


        class Bla {
        public:
            Bla(string name, int len) : _name(move(name)), _len(len), _vec(_len, 0) {}
//            Bla(string name, int len) : _name(name), _len(len), _vec(_len, 0) {}

            Bla(Bla &other) = default;

            Bla(Bla &&other) noexcept {
                _vec = other._vec;
                _len = other._len;
                _name = other._name;

        other._vec = vector<int>(0);
        other._len = 0;
        other._name = nullptr;
    }

    Bla superCrazy() {
        string name = _name + " got bigger";
        int len = _len*1000;
        Bla huge_bla(name, len);
        return huge_bla;
    }

    int getSize() {
        return _len;
    }

    string getName() {
        return _name;
    }
private:
    string _name;
    int _len;
    vector<int> _vec;


};


int main() {

    Bla normal("normal", 10);
    Bla huge(normal.superCrazy());

    cout << huge.getName() << " and is now: " << huge.getSize() << endl;
    return 0;
}