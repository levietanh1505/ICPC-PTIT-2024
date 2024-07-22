#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solve(vector<int> a){
    int maxVal = *max_element(a.begin(), a.end());
    vector<int> frequent(maxVal + 1, 0);                // mảng đếm tần suất
    for(int x : a) frequent[x]++;

    for(int i = maxVal; i > 0; --i){
        int cnt = 0;
        for(int j = i; j <= maxVal; j += i){
            cnt += frequent[j];
        }
        if(cnt > 1) return i;
    }
    return 1;
}

int main(){
    int q;  cin >> q;
    while(q--){
        int n;  cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i)  cin >> a[i];

        cout << solve(a) << endl;
    }
    return 0;
}