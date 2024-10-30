/*
 * Cho dãy số A[] gồm các số nguyên dương là lũy thừa của 2.
 * Tại mỗi bước, bạn được phép chọn 1 trong 2 thao tác sau:
 *   o Loại bỏ 1 số bất kỳ
 *   o Hoặc cộng 2 số giống nhau và liền kề với nhau trở thành 1 số mới.
 * Các thao tác trên dừng lại khi chỉ còn 1 số duy nhất.
 * Hãy tính xem giá trị lớn nhất có thể đạt được là bao nhiêu.
 * Input:
 * Dòng đầu ghi số N là số phần tử của dãy A[] (1 ≤ N ≤ 1000).
 * Dòng thứ 2 ghi N số của dãy A[], trong đó 1 ≤ A[i] ≤ 2100.
 * 
 * Output:
 * Ghi ra giá trị lớn nhất có thể đạt được.
 */

#include <bits/stdc++.h>

using namespace std;

// tổng số lớn
string add(const string &a, const string &b) {
    string result;
    int carry = 0;
    int i = a.size() - 1, j = b.size() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        carry = sum / 10;
        result.push_back(sum % 10 + '0');
    }

    reverse(result.begin(), result.end());
    return result;
}

// So sánh a > b 
bool compare(const string &a, const string &b) {
    if (a.size() != b.size()) {
        if (a.size() > b.size())
            return true;
        else
            return false;
    }
    if (a > b)
        return true;
    else
        return false;
}

int main() {
    long long n;
    cin >> n;
    vector<string> arr(n);

    for (long long i = 0; i < n; ++i) std::cin >> arr[i];

    for (long long i = 0; i < n - 1; ++i) {
        if (arr[i] == arr[i + 1]) {
            string s = arr[i];
            arr[i] = add(s, s);
            arr.erase(arr.begin() + i + 1);
            i -= 2;
            n--;
        }
    }

    // Tìm giá trị lớn nhất
    string maxVal = arr[0];
    for (int i = 1; i < n; ++i) {
        if (!compare(maxVal, arr[i])) maxVal = arr[i];
    }
    
    // Xóa các phần tử khác maxVal
    for (long long i = 0; i < n; ++i)
        if (maxVal != arr[i]) {
            arr.erase(arr.begin() + i);
            i--;
            n--;
        }

    // Duyệt lại lần cuối
    for (long long i = 0; i < n - 1; ++i) {
        if (arr[i] == arr[i + 1]) {
            arr[i] = add(arr[i], arr[i]);
            arr.erase(arr.begin() + i + 1);
            i -= 2;
            n--;
        }
    }

    string result = arr[0];
    // So sánh res với các giá trị của arr 
    for (int i = 1; i < n; ++i) {
        if (!compare(result, arr[i])) result = arr[i];
    }
    cout << result;
    return 0;
}