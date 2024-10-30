/*
    Cho dãy số A[] có N phần tử.

Hãy đếm số cặp chỉ số (L, R) thỏa mãn tổng dãy con liên tiếp (A[L] + A[L+1] + … + A[R]) chia hết cho số nguyên M.

Input:

Dòng đầu tiên gồm 2 số nguyên dương N và M (1 ≤ N ≤ 105, 1 ≤ M, A[i] ≤ 109).

Dòng tiếp theo gồm N số nguyên mô tả dãy số A[].

Output: 

In ra số cặp chỉ số thỏa mãn yêu cầu của đề bài.
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> prefixSum(n + 1);
    prefixSum[0] = 0;
    
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        prefixSum[i] = (prefixSum[i - 1] + a) % m;
    }

    map<int, int> frequen;
    for (int i = 0; i <= n; ++i) {
        frequen[prefixSum[i]]++;
    }

    long long res = 0;
    for (const auto& [key, value] : frequen) {
        res += (long long)value * (value - 1) / 2;
    }

    cout << res;
    return 0;
}