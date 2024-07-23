// Cho dãy số a gồm n phần tử. Với mỗi độ dài x, chúng ta có được n−x+1 dãy con liên tiếp.
// - b1={a1,a2,...,ax}
// - b2={a2,a3,...,ax+1}
// ---------------------
// - bn−x+1={an−x+1,an−x+2,...,an}
// Gọi min(b) là giá trị phần tử nhỏ nhất của dãy con b Hãy tính giá trị sx = max(min(b1),min(b2),...,min(bn−x+1))
// Input
// Dòng đầu tiên là số nguyên n (1 ≤ n ≤ 2⋅10^5) Dòng tiếp theo gồm n số nguyên ai (1 ≤ ai ≤ 10^9)
// Output
// Với mỗi độ dài dãy số với giá trị x từ 1 đến n hãy in ra giá trị sx tìm được.
// inputCopy
// 10
// 1 2 3 4 5 4 6 2 1 2
// outputCopy
// 6 4 4 4 3 2 2 1 1 1 
// inputCopy
// 5
// 1 2 3 4 5
// outputCopy
// 5 4 3 2 1 

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Hàm tìm giá trị lớn nhất của các giá trị nhỏ nhất trong các cửa sổ có kích thước khác nhau
vector<int> findMaxOfMins(const vector<int>& A, int N) {
    // Khởi tạo các mảng left, right và result, để tìm chỉ số phần tử nhỏ hơn gần nhất về bên trái và phải 
    // Từ đó suy ra khoảng dài nhất để phần tử A[i] đạt giá trị min, vì tất cả phần tử trong khoảng đó đều >= A[i]
    vector<int> left(N), right(N), result(N, INT_MIN); 
    stack<int> s; // Khởi tạo ngăn xếp chứa các chỉ số để xử lý

    // Tìm phần tử nhỏ hơn gần nhất về bên trái cho mỗi phần tử trong mảng
    // Khi đó độ dài từ chỉ số phần tử tìm được + 1 đến phần tử đang xét là khoảng dài nhất bên trái mà A[i] nhỏ nhất
    for (int i = 0; i < N; ++i) {
        while (!s.empty() && A[s.top()] >= A[i]) {
            s.pop();
        }
        left[i] = s.empty() ? -1 : s.top(); // Nếu ngăn xếp trống, gán -1, ngược lại gán giá trị đỉnh ngăn xếp
        s.push(i); // Đẩy chỉ số hiện tại vào ngăn xếp
    }

    // Làm trống ngăn xếp để sử dụng lại
    while (!s.empty()) s.pop();

    // Tìm phần tử nhỏ hơn gần nhất về bên phải cho mỗi phần tử trong mảng
    for (int i = N - 1; i >= 0; --i) {
        while (!s.empty() && A[s.top()] >= A[i]) {
            s.pop();
        }
        right[i] = s.empty() ? N : s.top(); // Nếu ngăn xếp trống, gán N, ngược lại gán giá trị đỉnh ngăn xếp
        s.push(i); // Đẩy chỉ số hiện tại vào ngăn xếp
    }

    // Tính toán mảng result
    for (int i = 0; i < N; ++i) {
        // Tính độ dài cửa sổ mà phần tử A[i] là nhỏ nhất là hiệu chỉ số dài nhất bên phải trừ đi bên trái - 1 
        // thực chất độ dài là hiệu 2 cái cộng 1 mà do 2 đầu mút ko tính do 2 đầu mút vẫn cho giá trị bé hơn A[i] nên phải trừ cho 2 
        int len = right[i] - left[i] - 1; 

        // Giá trị lớn nhất cho cửa sổ kích thước len là max của các giá trị A[i] mà đạt min tại cửa sổ có độ dài lớn nhất là len
        result[len - 1] = max(result[len - 1], A[i]); 
    }

    //Chú ý là Max của cửa sổ thứ k thì cũng có thể là max của cửa sổ thứ k - 1 vì A[i] đạt min tại cử sổ rộng k
    // thì cũng đạt min tại cửa rộng k - 1, nên là phải so sánh max của các cửa rộng hơn cửa đang xét nữa
    // Do cửa có chiều rộng là N - 1 là rộng nhất nên không có cửa nào rộng hơn để xét thêm nên ta xét từ nó lên đầu 
    int Max_Temp = result[N - 1];
    for (int i = N - 2; i >= 0; --i) {
        // So sánh với các cửa sổ lớn hơn ở trước vì các cửa lớn hơn chồng lên các cửa bé hơn và lấy giá trị max khi so sánh
        Max_Temp = max(result[i], Max_Temp);
        result[i] = Max_Temp;
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false); // Tối ưu hóa tốc độ đọc/ghi
    cin.tie(nullptr); // Tách biệt luồng đầu vào và đầu ra
    int N; cin >> N; vector<int> A(N); for (int i = 0; i < N; ++i) cin >> A[i];

    vector<int> result = findMaxOfMins(A, N); 
    for (int i = 0; i < N; ++i) cout << result[i] << " "; 

    return 0;
}
