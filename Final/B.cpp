#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int myPow(int mu, int mod) {
    if (mu == 0) return 1;
    int res = 1;
    for (int i = 1; i <= mu; ++i) res = (res * 10) % mod;
    return res;
}

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    if (a.first + a.second == b.first + b.second)
        return a.first < b.first;
    else 
        return a.first + a.second < b.first + b.second;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        int temp = 0;
        vector<pair<int, int>> res;

        for (int i = 0; i <= 200; i++) {
            for (int j = 0; j <= 200 - i; j++) {
                if (i == 0 && j == 0) continue;
                temp = (8 * myPow(i + j, 9 * x) - 2 * myPow(j, 9 * x) - 6) % (9 * x);
                if (temp == 0) 
                    res.push_back({i, j});
            }
        }
        if (res.empty())
            cout << "-1" << endl;
        else {
            sort(res.begin(), res.end(), cmp);
            cout << string(res[0].first, '8') +  string(res[0].second, '6') << endl;
        }
    }
    return 0;
}