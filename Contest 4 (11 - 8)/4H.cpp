/*
    Dãy số X[] có N phần tử là các số nguyên dương được tạo ra theo quy tắc sau:

Cho trước các hằng số X[0], a, c, m
X[i] = (a*X[i-1] + c) % m
Đảm bảo N phần tử là phân biệt, không có 2 giá trị nào trùng nhau.
 Ai cũng đã biết đến thuật toán tìm kiếm nhị phân trên dãy đã sắp xếp.

Bài toán của bạn hôm nay là hãy đếm xem có bao nhiêu giá trị của dãy số X[] có thể được tìm thấy theo quy tắc tìm kiếm nhị phân khi chưa sắp xếp dãy X[].
 */

#include <algorithm>
#include <iostream>
#include <vector>

bool binarySearch(const std::vector<unsigned long long>& x, unsigned long long target) {
    unsigned long long left = 0;
    unsigned long long right = x.size() - 1;
    while (left <= right) {
        unsigned long long mid = (right + left) / 2;

        if (x[mid] == target) {
            return true;
        }
        if (left >= x.size() || left < 0)
            return false;
        else {
            if (x[mid] < target) {
                left = mid + 1;
            }
        }
        if (right < 0 || right >= x.size())
            return false;
        else {
            if (x[mid] > target) {
                right = mid - 1;
            }
        }
    }
    return false;
}

int main() {
    unsigned long long n, m, a, c, num;
    std::cin >> n >> m >> a >> c >> num;
    std::vector<unsigned long long> x(n);
    x[0] = (num * a + c) % m;
    for (unsigned long long i = 1; i < n; ++i) x[i] = (a * x[i - 1] + c) % m;
    unsigned long long result = 0;
    for (unsigned long long i = 0; i < n; ++i) {
        if (binarySearch(x, x[i])) ++result;
    }
    std::cout << result;
}