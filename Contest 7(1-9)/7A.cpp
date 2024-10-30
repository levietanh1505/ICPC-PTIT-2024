// Cho dãy số gồm A và B gồm có N phần tử. Hãy tìm dãy con dài nhất của dãy A (các phần tử không nhất thiết phải liên tiếp nhau) 
// sao cho tổng các phần tử của dãy con này lớn hơn hoặc bằng tổng các phần tử tương ứng trong dãy B.

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<long long> a(n), b(n), c(n);

    for (long long i = 0; i < n; ++i) std::cin >> a[i];
    for (long long i = 0; i < n; ++i) std::cin >> b[i];
    for (long long i = 0; i < n; ++i) c[i] = a[i] - b[i];
    sort(c.begin(), c.end(), greater<long long>());
    
    long long count = 0;
    long long currentSum = 0;
    for (long long i = 0; i < n; ++i) {
        currentSum += c[i];
        if (currentSum >= 0) {
            count++;
        } else {
            currentSum -= c[i];
        }
    }

    cout << count << endl;
    return 0;
}
