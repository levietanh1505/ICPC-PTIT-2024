#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
// Giải thuật: những chỉ số trong chuỗi bị đối đối xứng khi chỉ số đó có lệnh đối có giá trị bé hơn hoặc bằng chỉ số ấy
// suy ra nếu có n lệnh đối bé hơn hoặc bằng chỉ số đấy, mà n lẻ thì chỉ số ấy bị đổi, ngược lại thì giữ nguyên
// ví dụ chỉ số thứ 3 4.. của string có 3 lệnh đối (bé hơn hoặc bằng chỉ số) là 1 2 3 nên suy ra các chỉ số đấy bị đối
// còn chỉ số tại 2 thì chỉ có 2 lệnh thỏa mãn là 1 và 2 nên sẽ không bị đổi vì là số chẵn
int main(){
    string s;   cin >> s;
    int n;      cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    // sắp xếp để tạo màn đếm b là đếm số lượng lệnh đối bé hơn bằng chỉ số
    sort(a.begin(), a.end());
    int b[s.size()+1]={0};
    // index i đại diện cho chỉ số của string còn value đại diện cho số lệnh bé hơn hoặc bằng đấy
    for(int i = 0; i < a.size(); i++)
        b[a[i]] = i + 1;

    // Làn đầy khoảng chứa toàn 8: ví dụ 12003004>>> 12223334 
    int temp = b[0];
    for (int i = 0; i < s.size(); i++)
        if (b[i] == 0) b[i] = temp;
        else temp = b[i];

    // OUT
    for(int i = 0; i < s.size(); i++){
        // k là giá trị số lệnh bé hơn hoặc bằng index i 1 của string (chú ý là index của bài toán nó chạy từ 1 mà ta chạy từ 0)
        int k = b[i+1];
        // Lẻ thì đổi
        if(k % 2 == 1) swap(s[i], s[s.size() - i - 1]);
    }

    cout << s;
    return 0;
}