#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <string>
#include <sstream>

using namespace std;
using ll = long long;


bool check(vector<int>& v) {
    bool increasing = v[1] > v[0];
    if (!increasing) {
        reverse(v.begin(), v.end());
    }
    bool good = true;
    for (int i = 1; i < v.size(); i++) {
        if (v[i] < v[i-1] + 1 || v[i] > v[i-1] + 3) {
            good = false;
        }
    }
    return good;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);


    vector<vector<int>> reports;
    string str;
    while (getline(cin, str)) {
        stringstream ss(str);
        vector<int> v;
        int x;
        while (ss >> x) {
            v.push_back(x);
        }
        reports.push_back(v);
    }

    ll res = 0;
    for (vector<int>& report : reports) {
        bool anygood = false;
        for (int i = 0; i < report.size(); i++) {
            vector<int> test = report;
            test.erase(test.begin() + i);
            anygood = anygood || check(test);
        }
        if (anygood) res++;
    }

    cout << res << endl;

    return 0;
}