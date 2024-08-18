// Tí có một chiếc bể cá cũ được cấu tạo từ N cột đá, cột đá thứ i có chiều cao là H[i]. Khi đổ nước vào bể, nước ở trong bể sẽ được giữ lại
// khi ở bên trái và bên phải của bể có một cột đá khác có thể chặn lượng nước đó, nếu không thì nước sẽ trào ra ngoài bể.
// Tí có thể chi ra tối đa là K đồng để nâng cấp bể cá này. Tí có thể chi 1 đồng cho mỗi một viên đá có kích thước 1x1 và 
// đặt viên đá ấy ở trên cùng của một cột đá bất kì tăng độ của cột đá đó lên.
// Các bạn hãy giúp Tí tìm một giải pháp nâng cấp tối ưu sao cho bể cá mới có thể chứa được nhiều nước nhất có thể!
// Input:
// Dòng đầu tiên là hai số nguyên N và K (1 ≤ N, K ≤ 12).
// Dòng tiếp theo gồm N số nguyên H[i] (1 ≤ H[i] ≤ 10^9).
// Output: 
// In ra một số nguyên duy nhất là lượng nước tối đa bể có thể chứa sau khi tu sửa.
// Example:
// Input
// Output
// 9 2
// 1 4 1 2 2 4 1 2 1
// 11
// 5 2
// 1 1 1 1 1
// 3
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int n, heights[20],
    maxWater;

int calWater(){
    int left[n], right[n];
    left[0] = heights[0];
    for (int i = 1; i < n; i++) left[i] = max(left[i - 1], heights[i]);
    right[n - 1] = heights[n - 1];
    for (int i = n - 2; i >= 0; i--) right[i] = max(right[i + 1], heights[i]);

    int water = 0;
    for (int i = 0; i < n; i++) water += min(left[i], right[i]) - heights[i];

    return water;
}

void backtrack(int idx, int k){
    if(idx >= n){
        if(k == 0) maxWater = max(maxWater, calWater());
        return;
    }
    for(int i = 0; i <= k; ++i){
        heights[idx] += i;
        backtrack(idx + 1, k - i);
        heights[idx] -= i;
    }
}

void solve(int k){
    maxWater = calWater();
    backtrack(0, k);
    cout << maxWater << endl;
}


int main() {
    cin >> n;
    int k;  cin >> k;
    for (int i = 0; i < n; i++) cin >> heights[i];

    solve(k);
    return 0;
}
