#include <iostream>

int main() {
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
    
    using namespace std;


    int main() {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT */
        int n, q, len, temp;
        cin >> n;
        cin >> q;
        vector <vector<int>> bla;
        for (int i = 0; i < n; i++) {
            cin >> len;
            for (int j = 0; j < len; ++j) {
                cin >> temp;
                bla[i].push_back(temp);
            }
        }
        int x, y;
        for (int i = 0; i < q; i++) {
            cin >> x >> y;
            cout << bla[x][y] << endl;
        }

        return 0;
    }
}