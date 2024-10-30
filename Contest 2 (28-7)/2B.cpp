/*
 * Cho một số nguyên dương N, hãy đếm xem có bao nhiêu số nguyên dương trong đoạn [1, N] 
 * có biểu diễn thập phân gồm không quá 2 chữ số. (N <= 10^9)
 */

#include<iostream>
#include<cmath>
#include<set>

using namespace std;

int N, n, ok;
int a[10];
set<int> res;

void initilize(){
    for(int i = 1; i <= n; ++i) a[i] = 0;
}

void create(){
    int i = n;
    while(i >= 1 && a[i] == 1){
        a[i] = 0;
        i--;
    }
    if(i == 0) ok = 0;
    else a[i] = 1;
}

void solve(int n){
    initilize();
    ok = 1;
    while(ok){
        for(int d1 = 0; d1 < 10; d1++)
            for(int d2 = d1 + 1; d2 < 10; d2++){
                int sum = 0;
                for(int i = 1; i <= n; ++i)
                    if (a[i] == 0) sum = sum * 10 + d1;
                    else sum = sum * 10 + d2;
                if(sum <= N) res.insert(sum);
            }
        create();
    }
}

int main(){
    cin >> N;
    n = log10(N) + 1;
    for(int i = 1; i <= n; ++i) solve(i);
    cout << res.size() - 1 << endl;
    return 0;
}