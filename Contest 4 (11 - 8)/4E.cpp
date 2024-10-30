/*
    Cho trước số nguyên dương N. Hãy đếm xem có bao nhiêu cặp số dương (a, b) có giá trị không vượt quá N và thỏa mãn a % b >= số K cho trước.

Input:

Gồm hai số nguyên N và K (1 ≤ N ≤ 100000, 0 ≤ K ≤ N-1).

Output: 

In ra đáp án là số cặp (a, b) thỏa mãn.
 */

#include <iostream>

long long myMax(long long a, long long b) { return a > b ? a : b; }

int main() {
    long long n, k;
    std::cin >> n >> k;
    long long result = 0;
    if (k == 0) {
        std::cout << n * n;
        return 0;
    }
    for (long long i = k; i <= n; ++i) {
        result += n / i * (i - k) + myMax(0, n % i - k + 1);
    }
    std::cout << result;
    return 0;
}