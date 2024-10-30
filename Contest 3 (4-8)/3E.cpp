/*
    Thuật toán Quick-Sort đã rất nổi tiếng và quen thuộc với tất cả lập trình viên. Một trong vấn đề quan trọng là chọn phần từ chốt (pivot) sao cho phù hợp. Giả sử giá trị chốt là p thì sau bước phân hoạch dãy số mới sẽ như sau:

A black and white rectangular object with a heart  Description automatically generated

Với XL và XR là hai dãy con (có thể rỗng) của dãy số ban đầu. Giá trị trong XL ≤ p còn XR > p

Bài toán đặt ra cho bạn là hãy đếm và liệt kê các giá trị chốt thỏa mãn điều kiện nếu được chọn thì dãy số đã được phân hoạch từ trước.

Input

Chỉ có 1 dòng trong đó:

Số đầu tiên là số phần tử của dãy 1 ≤ N ≤ 106
N số tiếp theo là các giá trị trong dãy, các số đều nguyên dương phân biệt và không quá 106.
Output

Chỉ có 1 dòng trong đó:

Số đầu tiên là số M, số lượng các phần tử thỏa mãn điều kiện đề bài (M có thể bằng 0).
Tiếp theo là M số thỏa mãn lần lượt theo thứ tự trong dãy ban đầu.
Chú ý: nếu M lớn hơn 100 thì chỉ in ra 100 số đầu tiên.  
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;  cin >> n;
    int a[n], left[n], right[n];
    vector<int>res;

    for(int i = 0; i < n; i++)cin >> a[i];

    left[0] = a[0];
    for(int i = 1; i < n; i++)left[i] = max(left[i - 1], a[i]);

    right[n - 1] = a[n - 1];
    for(int i = n - 2; i >= 0; i--)right[i] = min(right[i + 1], a[i]);

    for(int i = 0; i < n; i++){
        if(a[i] == left[i] && a[i] == right[i])res.push_back(a[i]);
    }

    cout << res.size();
    for(int i = 0; i < min(100, (int)res.size()); i++) cout << " " << res[i];
    return 0;
}