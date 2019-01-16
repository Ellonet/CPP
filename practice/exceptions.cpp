//
// Created by ellonet on 1/16/19.
//

#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>

using namespace std;


class badUsage : public runtime_error {
public:
    explicit badUsage(const char *message) : runtime_error(message) {}
};

class stupid : logic_error {
public:
    explicit stupid(const char *message) : logic_error(message) {}
};


class suck {
private:
    string arr[5];
    int nothing;
public:
    vector<int> positives;

    explicit suck(int x, string bla) : nothing(x) {
        for (auto &i : arr) {
            i = bla;
        }
    }

    string do_shit(int i) {
        string res;
        try {
            res = arr[i];
        }
        catch (exception &e) {
            throw badUsage("ah ha!!!");
        }
        return res;
    }
};

int main() {
    suck lala(3, "silly nilly");

    string shit;
    try {
        shit = lala.do_shit(10);
    }
//    catch (...) {
//        cout << "here!" << endl;
//
    catch (exception &b) {
        cerr << b.what();
    }


    return 0;
}