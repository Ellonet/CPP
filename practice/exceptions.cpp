//
// Created by ellonet on 1/16/19.
//

#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>

using namespace std;


class badUsage : public runtime_error
{
public:
    explicit badUsage(const char *message) : runtime_error(message)
    {}
};

class stupid : public logic_error
{
public:
    explicit stupid(const char *message) : logic_error(message)
    {}
};


class suck
{
private:
    string arr[5];
    int nothing;
    vector<int> positives;
public:

    suck() try
    {
        positives.push_back(100);
        throw (bad_alloc());
        nothing = 100;
    }
    catch (bad_alloc &e)
    {
        throw stupid("i got you babe");
    }

    explicit suck(int x, string bla) : nothing(x)
    {
        for (auto &i : arr)
        {
            i = bla;
        }
        positives.push_back(0);
    }

    string do_shit(int i)
    {
        if (i < 0 || i > 4)
        {
            throw badUsage("you suck!!!");
        }
        return arr[i];
    }
};

int main()
{
//    test -------------------- regualar exceptions -------------------- //
    suck lala(3, "silly nilly");
    string shit;
    try
    {
        shit = lala.do_shit(13);
    }
    catch (exception &b)
    {
        cerr << b.what() << endl;
    }

//    test -------------------- constructor exceptions -------------------- //

    try
    {
        suck bad;
        cout << "yo";
    } catch (logic_error &e)
    {
        cerr << e.what() << endl;
    }

    return 0;
}