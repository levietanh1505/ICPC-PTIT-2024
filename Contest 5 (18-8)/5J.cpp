// Với 3 đoạn thẳng có độ tương ứng ta có thể ghép được một tam giác nếu ba điều kiện sau thỏa mãn: x + y > z, x + z > y, y + z > x.
// Cho dãy số nguyên dương a[] gồm có n phần tử. Hãy tìm dãy con liên tiếp dài nhất mà 3 phần tử khác nhau bất kỳ trong dãy tương ứng là độ dài 3 cạnh của một tam giác.
// Input:
// Dòng đầu tiên là số nguyên n ≤ 105
// Dòng tiếp theo gồm n số nguyên dương không quá 109.
// Output:
// Với mỗi test, in ra đáp án tìm được.
// Ví dụ:
// Input	Output
// 5
// 3 1 1 1 2
// 3
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    int max_len = 0;
    int left = 0;
    multiset<int> s;

    for (int right = 0; right < n; ++right) {
        s.insert(arr[right]);

        while (s.size() >= 3) {
            auto it = s.begin();
            int min1 = *it;
            it++;
            int min2 = *it;
            int max_val = *s.rbegin();  

            if (min1 + min2 > max_val) {
                max_len = max(max_len, right - left + 1);
                break;
            } else {
                s.erase(s.find(arr[left]));
                left++;
            }
        }
    }

    cout << max_len << endl;

    return 0;
}
