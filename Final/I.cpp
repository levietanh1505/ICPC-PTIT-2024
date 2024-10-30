#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr1[n], arr2[n];
        for(int i = 0; i < n; ++i) cin >> arr1[i];
        for(int i = 0; i < n; ++i) cin >> arr2[i];

        int cnt = 0;
        for(int i = n - 1, idx = n - 1; idx >= 0, i >= 0; i--){
            if(arr2[idx] != arr1[i]) cnt++;
            else idx--;
        }
        
        cout << cnt << endl;
    }
    return 0;
}