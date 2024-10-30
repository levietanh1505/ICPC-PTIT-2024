// Cho dãy số A[] có N phần tử. Hãy tìm số chỉ số i (1 ≤ i ≤ N) thỏa mãn tính chất:
// Với mọi chỉ số j (j khác i) thì A[i] không chia hết cho A[j].

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; ++i) std::cin >> a[i];

    unordered_map<long long, long long> freq;
    for (long long i = 0; i < n; ++i) freq[a[i]]++;
    
    std::vector<bool> isDiv(1000001, false);

    for (long long i = 0; i < n; ++i) {
        if (!isDiv[a[i]]) {
            for (long long j = 2 * a[i]; j <= 1000000; j += a[i]) {
                isDiv[j] = true;
            }
        }
        if (freq[a[i]] > 1) {
            isDiv[a[i]] = true;
        }
    }

    long long count = 0;
    for (long long i = 0; i < n; ++i) {
        if (!isDiv[a[i]] && freq[a[i]] == 1) {
            count++;
        }
    }

    cout << count;
    return 0;
}
