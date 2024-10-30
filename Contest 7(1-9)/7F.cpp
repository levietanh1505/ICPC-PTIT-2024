// Cho dãy số A[] có N phần tử là nguyên dương không quá 100, N không quá 50.
//Hãy đếm số cách chọn ra các phần tử trong dãy để được giá trị tổng là số chẵn (hoặc lẻ).

#include<iostream>

const long long MOD = 1e9 + 7;

using namespace std;

long long pow(long long a, long long n){
    if(n == 1) return a;
    long long tmp = pow(a, n / 2);
    return (n % 2 == 0) ? tmp * tmp % MOD : (tmp * tmp % MOD) * a % MOD;
}

int main(){
    int n, type;	cin >> n >> type;
    int a[n];
    for(int i = 0; i < n; ++i)  cin >> a[i];
        
    // Cách chọn các phần tử từ i phần tử đầu tiên để đuợc tổng là chẵn / lẻ
    long long dp[n + 1][2] = {0};
    dp[0][0] = 1;   dp[0][1] = 0;

    for(int i = 1; i <= n; ++i){
        if(a[i - 1] % 2 == 0){
            dp[i][0] = (dp[i - 1][0] * 2) % MOD;
            dp[i][1] = (dp[i - 1][1] * 2) % MOD;
        }
        else{
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
        }
    }
    
    cout << dp[n][type];
    return 0;
}