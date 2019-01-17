#include <iosfwd>
#include <bits/basic_string.h>
#include <utility>
#include <vector>

using namespace std;

class AntonymFinder
{
public:
    void readDictionary(istream &in) {
        string first, second;

        while (in >> first) {
            in >> second;
            auto p = make_pair(first, second);
            bla.push_back(p);
        }
    }

    string findAntonym(string s) {
        for (auto &p : bla) {
            if (p.first == s) {
                return p.second;
            }
            if (p.second == s) {
                return p.first;
            }
        }
        return (string) "";
    }


private:
    vector<pair<string,string>> bla;

};