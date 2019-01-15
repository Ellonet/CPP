//
// Created by ellonet on 1/15/19.
//

//
// Created by ellonet on 1/15/19.
//
#include <string>
#include <vector>
#include <iostream>

using namespace std;


class person {
public:
    person(string name, int age) : _name(name), _age(age) {}
d

    person &operator+=(person &other) {
        _friends.push_back(other._name);
        return *this;
    }

    friend ostream &operator<<(ostream &out, person &p) {
        out << "My name is " << p._name << endl;
        out << "My friends are: ";
        for (string &i : p._friends) {
            out << i << " ";
        }
        out << endl;
        return out;
    }


protected:
    string _name;
    int _age;
    vector<string> _friends;

};

// -------------------------- programmer ------------------------------------- //

class programmer : public virtual person {
public:
    programmer(string name, int age, string company) : person(name, age), _company(company) {}

    friend ostream &operator<<(ostream &out, programmer &p) {
        out << "My name is " << p._name << " and i work in " << p._company << endl;
        out << "My friends are: ";
        for (string &i : p._friends) {
            out << i << " ";
        }
        out << endl;
        return out;
    }


protected:
    string _company;
};

// -------------------------- student ------------------------------------- //

class student : public virtual person {
public:
    student(string name, int age, string school) : person(name, age), _school(school) {}

    friend ostream &operator<<(ostream &out, student &s) {
        out << "My name is " << s._name << " and i study in " << s._school << endl;
        out << "My friends are: ";
        for (string &i : s._friends) {
            out << i << " ";
        }
        out << endl;
        return out;
    }

protected:
    string _school;
};


// -------------------------- both! ------------------------------------- //

class work_and_learn : programmer, student {
public:
    work_and_learn(string name, int age, string company, string uni) : student(name, age, uni),
                                                                       programmer(name, age, company),
                                                                       person(name, age) {}


    ~work_and_learn() = default;

    friend ostream &operator<<(ostream &out, work_and_learn &w) {
        out << "My  name is " << w._name << " and i study in " << w._school << " and work in " << w._company << endl;
        out << "My  friends are: ";
        for (string &i : w._friends) {
            out << i << " ";
        }
        out << endl;
        return out;
    }


};