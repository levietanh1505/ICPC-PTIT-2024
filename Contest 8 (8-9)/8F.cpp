#include <algorithm>
#include <iostream>
#include <vector>

const long long MOD = 1e9 + 7;
const long long MAX = 200000;

using namespace std;

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

long long countPaths(long long x, long long y) { return combination(x + y, x); }

int main() {
    factorial();
    inverse();

    long long t;
    cin >> t;

    while (t--) {
        long long N, M, K;
        cin >> N >> M >> K;

        std::vector<std::pair<long long, long long>> blocked(K);
        for (long long i = 0; i < K; ++i) {
            cin >> blocked[i].first >> blocked[i].second;
        }

        sort(blocked.begin(), blocked.end());

        long long totalPaths = countPaths(N - 1, M - 1);  // Tổng số đường không xét ô cấm
        vector<long long> dp(K);

        for (long long i = 0; i < K; ++i) {
            // Tính số đường từ (1,1) đến ô cấm thứ i
            dp[i] = countPaths(blocked[i].first - 1, blocked[i].second - 1);
            // Loại bỏ các đường đi qua ô cấm trước đó
            for (long long j = 0; j < i; ++j) {
                if (blocked[j].first <= blocked[i].first &&
                    blocked[j].second <= blocked[i].second) {
                    dp[i] = (dp[i] - dp[j] * countPaths(blocked[i].first - blocked[j].first, blocked[i].second - blocked[j].second) % MOD + MOD) % MOD;
                }
            }
            // Trừ đi các đường đi qua ô cấm i từ tổng số đường
            totalPaths = (totalPaths - dp[i] * countPaths(N - blocked[i].first, M - blocked[i].second) % MOD + MOD) % MOD;
        }

        cout << totalPaths << std::endl;
    }

    return 0;
}