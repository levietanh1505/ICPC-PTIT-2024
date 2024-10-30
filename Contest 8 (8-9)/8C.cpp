#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

const long long factorial[16] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 6227020800, 87178291200, 1307674368000};

void type2(int n, long long k){
    bool visited[n + 1];
    memset(visited, false, sizeof(visited));

    for(int i = 0; i < n; ++i)
        for(int j = 1; j <= n; ++j)
            if(!visited[j]){
                if(k > factorial[n - i - 1]) k -= factorial[n - i - 1];
                else{
                    cout << j << ' ';
                    visited[j] = true;
                    break;
                }
            }

    cout << endl;
}

long long type1(int arr[], int n){
    bool visited[n + 1];
    memset(visited, false, sizeof(visited));
    long long res = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 1; j < arr[i]; ++j)
            if(!visited[j]) 
                res +=  factorial[n - i - 1];
        visited[arr[i]] = true;
    }
    return res + 1;
}


int main(){
    int t;  cin >> t;
    while(t--){
        int n;  cin >> n;       
        int type;   cin >> type;
        if(type == 1){
            int p[n];
            for(int i = 0; i < n; ++i) cin >> p[i];
            cout << type1(p, n) << endl;
        }
        else {
            long long idx;    cin >> idx;
            type2(n, idx);
        }
    }
    return 0;
}
