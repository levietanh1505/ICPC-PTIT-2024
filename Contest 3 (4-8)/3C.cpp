/*
    Alice đến quầy mua bánh sandwich, nhưng trong tay anh chỉ có những tờ tiền có mệnh giá 4$ và 7$. Giá một chiếc bánh là N $. Quầy bánh rất đông khách, vì vậy, họ chỉ muốn nhận đúng số tiền chứ không muốn mất thời gian để trả lại.

Biết rằng Alice có tới 100 tờ 4$ và 100 tờ 7$. Mặc dù vậy, anh ta lại rất tiết kiệm. Các bạn hãy xác định xem Alice có thể chọn được một số tờ tiền loại 4$ và 7$ sao cho tổng giá trị đúng bằng với giá tiền của chiếc bánh hay không?

Input: 

Một số nguyên dương N duy nhất (1 <= N <= 200).

Output: 

In ra “Yes” nếu tồn tại cách lựa chọn, in ra “No” trong trường hợp ngược lại.
 */

#include <iostream>

using namespace std;

int main(){
    int n;  cin >> n;
    for(int i = 0; i <= 100; i++){
        for(int j = 0; j <= 100; j++){
            if(i*4 + j*7 == n){
                cout << "Yes";
                return 0;
            }
        }
    }
    cout << "No";
    return 0;
}