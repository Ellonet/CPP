//
// Created by ellonet on 1/15/19.
//
#include <string>
#include <vector>
#include <iostream>

using namespace std;


class person {
public:
    person(string name, int age) : _name(name), _age(age), _isHappy(true) {}


    person &operator+=(person &other) {
        _friends.push_back(other._name);
        return *this;
    }

    friend ostream &operator<<(ostream &out, person &p) {
        out << "My  name is " << p._name << endl;
        out << "My  friends are: ";
        for (string &i : p._friends) {
            out << i << " ";
        }
        out << endl;
        return out;
    }


    string getName() {
        return _name;
    }

    int getAge() {
        return _age;
    }

    virtual bool getMood() {
        return _isHappy;
    }


protected:
    string _name;
    int _age;
    vector<string> _friends;
    bool _isHappy;

};



// --------------------------------------------------------------- //


class programmer : public person {
public:
    programmer(string name, int age, string company) : person(name, age), _company(company), _isHappy(false) {}

    friend ostream &operator<<(ostream &out, programmer &p) {
        out << "My  name is " << p._name << " and i work in " << p._company << endl;
        out << "My  friends are: ";
        for (string &i : p._friends) {
            out << i << " ";
        }
        out << endl;
        return out;

    }

    bool getMood() override {
        return programmer::_isHappy;
    }

    bool getOldMood() {
        return person::_isHappy;
    }


private:
    string _company;
    bool _isHappy;
};