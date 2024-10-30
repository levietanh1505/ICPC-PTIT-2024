// Cho hai xâu S và T có độ dài bằng nhau và chỉ chứa các kí tự thường. Bạn được phép thực hiện thao tác sau với số lượt tùy ý:
// mỗi lượt, chọn 2 kí tự X và Y, rồi thay thế tất cả các kí tự X trong xâu S thành Y, còn kí tự Y sẽ đổi ngược lại thành kí tự X.
// Nhiêm vụ của bạn là hãy xác định xem có thể thu được xâu T bằng cách biến đổi xâu S như vậy không?
// Input:
// Gồm 2 dòng, dòng đầu chứa xâu S, dòng thứ hai chứa xâu T (1 ≤ |S|, |T| ≤ 2 × 105).
// Output: 
// In ra “Yes” nếu có thể biến đổi được, in ra “No” trong trường hợp ngược lại.
// Test ví dụ:
// Input:
// Output
// balloon
// barrnno
// Yes
// aaa
// xxy
// No
// abcd
// efgh
// Yes

#include <iostream>
#include <map>

using namespace std;

int main() {
    string S1, S2;
    cin >> S1 >> S2;

    // Nếu hai chuỗi có độ dài khác nhau, không thể ánh xạ một-một
    if (S1.size() != S2.size()) {
        cout << "No";
        return 0;
    }

    map<char, char> forward_map;  // Ánh xạ từ S1 đến S2
    map<char, char> backward_map; // Ánh xạ từ S2 đến S1

    for (int i = 0; i < S1.size(); i++) {
        char c1 = S1[i];
        char c2 = S2[i];

        // Kiểm tra ánh xạ từ S1 đến S2
        if (forward_map.find(c1) != forward_map.end()) {
            if (forward_map[c1] != c2) {
                cout << "No";
                return 0;
            }
        } else {
            forward_map[c1] = c2;
        }

        // Kiểm tra ánh xạ từ S2 đến S1
        if (backward_map.find(c2) != backward_map.end()) {
            if (backward_map[c2] != c1) {
                cout << "No";
                return 0;
            }
        } else {
            backward_map[c2] = c1;
        }
    }

    cout << "Yes";
    return 0;
}