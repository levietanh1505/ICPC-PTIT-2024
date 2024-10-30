#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int gcd(int a, int b){
    if(b == 0)  return a;
    return gcd(b, a % b);
}

int kthDivisor(int n, int k){
    vector<int> divisors;
    for(int i = 1; i * i <= n; ++i){
        if(n % i == 0){
            divisors.push_back(i);
            if(i * i != n) divisors.push_back(n / i);
        }
    }
    sort(divisors.rbegin(), divisors.rend());
    return divisors[k - 1];
}

int main(){
    int a, b, k;
    cin >> a >> b >> k;

    cout << kthDivisor(gcd(a, b), k);
    return 0;
}