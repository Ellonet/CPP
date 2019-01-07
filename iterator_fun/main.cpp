#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<class T>
void add_for_each(vector<T>& v, const T& c)

{
    for_each(v.begin(),v.end(),[&](T& k){k+=c;});
}

int main()
{
    vector<int> v({1,2,3,4,5});
    add_for_each(v, 5); //now v will be equal to {6,7,8,9,10}
    for (auto &i : v) {
        cout << i << endl;
    }
}

