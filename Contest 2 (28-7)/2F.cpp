

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m; cin >> n >> m; int arr[n + 3];
    int l = m - 1;

    int index;
    for (int i = 1; i <= n; i ++){
        cin >> arr[i];
        if (arr[i] == 1) index = i;
    }

    int LenR, LenL;

    LenR = (n - index) + 1 ;
    LenL = (index - 1) + 1 ;
    cout << ceil(1.0 * (LenL + l - 1) / l) + ceil(1.0 * (LenR + l - 1) / l) - 2;
}