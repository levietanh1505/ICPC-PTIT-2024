/*
    Cho 3 hình chữ nhật có kích thước tương ứng là: A[i] x B[i] (i = 1, 2, 3). Hỏi 3 hình chữ nhật trên có thể ghép thành một hình vuông không? Nếu ghép được hãy cho biết độ dài cạnh hình vuông đó, ngược lại ghi số 0.

Input:

Dữ liệu đầu vào gồm có 3 dòng.

Mỗi dòng chứa 2 số nguyên là kích thước của hình chữ nhật (1 ≤ A[i], B[i] ≤ 109).

Output: 

In ra diện tích hình vuông mới tìm được, in ra 0 trong trường hợp không thể ghép được.
 */

#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int check(long long n){
    long long tmp = sqrt(n);
    if(tmp * tmp == n) return tmp;
    tmp++;
    if(tmp * tmp == n) return tmp;
    return 0;
}

int main(){
    int a[3], b[3], A, B;
    for(int i = 0; i < 3; ++i){
        cin >> A >> B;
        a[i] = min(A, B);
        b[i] = max(A, B);
    }



    long long totalArea = 1ll * a[1] * b[1] + 1ll * a[2] * b[2] + 1ll * a[0] * b[0];
    int side = check(totalArea);
    if(side == 0){
        cout << 0;
        return 0;
    }

    if(b[0] == b[1] && b[1] == b[2] && b[2] == side){
        cout << side;
        return 0;
    }

    if(b[1] == side){
        swap(a[0], a[1]);
        swap(b[0], b[1]);
    }
    if(b[2] == side){
        swap(a[0], a[2]);
        swap(b[0], b[2]);
    }
    if(b[0] == side){
        a[0] = side - a[0];
        if((a[0] == a[1] && a[0] == a[2]) || (a[0] == b[1] && a[0] == a[2]) 
            || (a[0] == a[1] && a[0] == b[2]) || (a[0] == b[1] && a[0] == b[2]))
                cout << side;
        else cout << 0;
    }
    else cout << 0;
    return 0;
}