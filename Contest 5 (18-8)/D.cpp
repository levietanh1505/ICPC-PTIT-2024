// Cho dãy số A[] có N phần tử. Nhiệm vụ của bạn là hãy chọn ra một dãy con B[] của A[] có K phần tử, sao cho độ chênh lệch của dãy số B[] là nhỏ nhất có thể.
// Gọi Bmax là phần tử lớn nhất của dãy, Bmin là phần tử nhỏ nhất của dãy số. Độ chênh lệch của dãy số được định nghĩa bằng Bmax – Bmin.
// Input:
// Dòng đầu tiên gồm hai số nguyên dương N và K (2 ≤ K < N ≤ 100000).
// Dòng thứ hai gồm N số nguyên A[i] (1 ≤ A[i] ≤ 109).
// Output: 
// In ra một số nguyên là độ chênh lệch của dãy con nhỏ nhất tìm được.
// Test ví dụ:
// Input
// Output
// 5 3
// 10 15 11 14 12
// 2
// 5 3
// 5 6 5 6 6
// 0

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    int res = a[k - 1] - a[0];
    for (int i = k; i < n; ++i) {
        res = min(res, a[i] - a[i - k + 1]);
    }

    cout << res;
    return 0;
}
