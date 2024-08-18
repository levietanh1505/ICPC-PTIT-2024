// Đất nước Alpha có N thành phố, tất cả nằm dọc theo một con đường cao tốc. Các thành phố được đánh số liên tiếp bắt đầu từ 1 đến N. 
// Thành phố thứ i có khoảng cách đến điểm bắt đầu con đường cao tốc là D[i]. Chính phủ của đất nước muốn thành lập một trung tâm văn hóa.
// Nếu trung tâm được đặt ở vị trí có khoảng cách đến điểm bắt đầu con đường cao tốc là P thì tổng chi phí giao lưu đi lại được tính bằng:
// S = |D[1]-P|k + |D[2]-P|k + … + |D[N]-P|k
// Các bạn hãy tính thử xem vị trí đặt trung tâm văn hóa ở đâu để tổng chi phí giao lưu đi lại là nhỏ nhất có thể.
// Input: 
// Dòng đầu gồm 2 số nguyên N và k (1 ≤ N ≤ 100, k = 1 hoặc k = 2).
// Dòng tiếp theo gồm N số nguyên A[i] (1 ≤ A[i] ≤ 108).
// Output: 
// In ra tổng chi phí giao lưu (S) nhỏ nhất có thể, với độ chính xác 2 chữ số sau dấu phảy.
// Test ví dụ:
// Input:
// Output:
// 3 1
// 1 4 2
// 3.00
// 2 2
// 1 
// 8.00
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<long long> a(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    double result = 0;

    if (k == 1) {
        sort(a.begin(), a.end());
        long long p1 = a[n / 2];
        for (int i = 0; i < n; ++i) {
            result += abs(a[i] - p1);
        }
    } else if (k == 2) {
        double p2 = 0;
        for (int i = 0; i < n; ++i) {
            p2 += a[i];
        }
        p2 /= n;
        for (int i = 0; i < n; ++i) {
            result += pow(a[i] - p2, 2);
        }
    }

    std::cout << std::fixed << std::setprecision(2) << result;

    return 0;
}
