/*
 * Cho dãy số A[] có N phần tử. Mỗi bước biến đổi, bạn cần thực hiện một trong hai loại thao tác sau 
 * lên các phần tử A[i]: (1) nhân A[i] với 3, hoặc (2) lấy A[i] chia cho 2.
 * Phép chia được thực hiện khi và chỉ khi A[i] là một số chẵn. 
 * Tại mỗi bước, không được phép thực hiện duy nhất thao tác (1) lên cả N phần tử.
 * Nhiệm vụ của bạn là hãy xác định xem số lượng bước biến đổi có thể được thực hiện lớn nhất bằng bao nhiêu?
 *
 * Input:
 * Dòng đầu tiên là số nguyên dương N (1 ≤ N ≤ 10000).
 * Dòng tiếp theo gồm N số nguyên A[i] (1 ≤ A[i] ≤ 109).
 *
 * Output: 
 * In ra đáp án là mức năng lượng tìm được.
 */

#include<iostream>
#include<cmath>

using namespace std;

int solve(int n){
    int cnt = 0;
    while(n % 2 == 0){
        n /= 2;
        cnt++;
    }
    return cnt;
}

int main(){
    int n;  cin >> n;
    int res = 0, a;
    for(int i = 0; i < n; ++i){
        cin >> a;
        res += solve(a);
    }
    cout << res << endl;
    return 0;
}