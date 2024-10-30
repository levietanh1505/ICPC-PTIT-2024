#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <cmath>

using namespace std;
const long long MOD = 1e9 + 7;
const long long MAX = 200000;
long long fact[MAX + 1], invFact[MAX + 1];

long long myPow(long long a, long long b, long long mod) {
    long long result = 1;
    while (b > 0) {
        if (b % 2 == 1) result = ((long long)result * a) % mod;
        a = ((long long)a * a) % mod;
        b /= 2;
    }
    return result;
}

void factorial() {
    fact[0] = 1;
    for (long long i = 1; i <= MAX; ++i) {
        fact[i] = ((long long)fact[i - 1] * i) % MOD;
    }
}

void inverse() {
    invFact[MAX] = myPow(fact[MAX], MOD - 2, MOD);
    for (long long i = MAX; i >= 1; --i) {
        invFact[i - 1] = ((long long)invFact[i] * (i)) % MOD;
    }
}

long long combination(long long n, long long k) {
    return ((long long)fact[n] * invFact[k] % MOD * invFact[n - k] % MOD) % MOD;
}


vector<int> primes;

void sieve(int n){
    bool isPrime[n];
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i * i < n; ++i)
        if(isPrime[i])
            for(int j = i * i; j < n; j += i)
                isPrime[j] = false;

    for(int i = 2; i < n; ++i)
        if(isPrime[i]) primes.push_back(i);
}

int main() {
    factorial();
    inverse();
    sieve(1e3 + 7);

    long long n, m;
    cin >> n >> m;
    
    unordered_map<int, int> divisor;
    for(int p : primes){
        if(p * p > m) break;
        if(m % p == 0){
            int cnt = 0;
            while(m % p == 0){
                m /= p;
                cnt++;
            }
            divisor[p] = cnt;
        }
    }
    if(m > 1) divisor[m] = 1;

    long long res = 1;
    for(const auto& [_, cnt] : divisor)
        res = (res * combination(n + cnt - 1, cnt)) % MOD;

    cout << res;

    return 0;
}