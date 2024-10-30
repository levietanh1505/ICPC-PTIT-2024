/*
    Cho dãy số F(n) với n >= 0 được định nghĩa theo công thức như sau:

F(0) = 0
F(1) = 1
F(n) = F(n-1) + F(n-2) với n >= 2.
Cho 3 số nguyên dương a, b, M. 

Hãy tính GCD(F(a), F(b)) theo modulo M.

Input:

Dòng đầu tiên là số lượng bộ test T (T <= 10).

Mỗi test gồm 3 số nguyên a, b và M (a, b, M <= 10^12).

Output: 

Với mỗi test, in ra một số nguyên là UCLN tìm được.
*/

#include <iostream>
#include <vector>

using namespace std;

long long gcd(long long a, long long b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

long long mod;

struct matrix{
    long long m[2][2];
    friend matrix operator * (matrix a, matrix b){
        matrix res;
        for(int i = 0; i < 2; ++i)
            for(int j = 0; j < 2; ++j){
                res.m[i][j] = 0;
                for(int k = 0; k < 2; ++k){
                    res.m[i][j] += a.m[i][k] * b.m[j][k];
                    res.m[i][j] %= mod;
                }
            }
        return res;   
    }
};

matrix powMatrix(matrix a, long long n){
    if (n == 1) return a;
    matrix tmp = powMatrix(a, n / 2);
    return (n % 2 == 0) ? tmp * tmp : tmp * tmp * a;
}

long long fibonacci(long long n) {
    if (n <= 1) return n;
    matrix a;
    a.m[0][0] = 1; a.m[0][1] = 1; a.m[1][0] = 1; a.m[1][1] = 0;
    
    matrix res = powMatrix(a, n);
    return res.m[0][1];
}

int main(){
    int q;  cin >> q;
    while(q--){
        long long a, b;    cin >> a >> b >> mod;
        //cout << a << b << mod << endl;
        cout << fibonacci(gcd(a, b)) << endl;
    }
    return 0;
}