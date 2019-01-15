//
// Created by ellonet on 1/15/19.
//

#include <string>
#include <ostream>
#include <vector>


using namespace std;


class Yo {
public:
    Yo(string name, int age) : _name(name), _age(age) {}

    Yo &operator+=(Yo &new_friend) {
        friends.push_back(new_friend._name);
        return *this;
    }



    bool operator<(Yo &other) {
        return (other._age > _age);

    }

    friend ostream &operator<<(ostream &out, Yo &other) {
        out << "my name is: " << other._name << endl;
        out << "my friends are: ";
        for (string &i : other.friends) {
            out << i << ", ";
        }
        out << endl;
        return out;
    }


private:
    string _name;
    vector<string> friends;
    string _nickNames[10];
    int _age;
};



