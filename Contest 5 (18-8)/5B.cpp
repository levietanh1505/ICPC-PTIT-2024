// Cho hai số nguyên dương N và M. Hãy tìm cách xây dựng dãy số A[] nguyên dương có đúng N phần tử thỏa mãn:
// A[1] + A[2] + … + A[N] = M
// và UCLN(A[1], A[2], …, A[N]) là lớn nhất có thể.
// Input
// Gồm hai số nguyên dương N và M (1 ≤ N ≤ 105, N ≤ M ≤ 109).
// Output
// In ra UCLN của dãy số tìm được.
// Test ví dụ:          
// Input
// Output
// 3 14
// 2
// 22 743
// 1
// 26 695
// 5

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;

    vector<long long> divisor;
    for (long long i = 1; i <= sqrt(m); i++) {
        if (m % i == 0) {
            divisor.push_back(i);
            if (i != m / i && i * i != m) divisor.push_back(m / i);
        }
    }

    sort(divisor.rbegin(), divisor.rend());

    long long res = 1;
    for (long long d : divisor)
        if (d * n <= m) {
            res = d;
            break;
        }
    cout << res;
    return 0;
}
