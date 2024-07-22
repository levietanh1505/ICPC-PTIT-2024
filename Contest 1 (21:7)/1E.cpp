#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<deque>

using namespace std;

const long long INF = 9223372036854775807L;

struct line {
    long long a, b, p;
    
    line(long long a, long long b) : a(a), b(b) {}
    long long val(long long x){ return a * x + b; }
};

deque<line> hull;

long long Floor(long long a, long long b){
    return a / b - ((a < 0) != (b < 0) && (a % b));
}

bool isEct(line& x, const line& y){
    if(x.a == y.a) x.p = (x.b > y.b) ? INF : -INF;
    else x.p = Floor(y.b - x.b, x.a - y.a);
    return x.p >= y.p;
}

void addLine(long long a, long long b){
    line l(a, b);
    while (hull.size() >= 2 && (isEct(l, hull.back()),
        isEct(hull.back(), hull[hull.size() - 2]), l.p < hull.back().p))
        hull.pop_back();
    hull.push_back(l);
}

long long query(long long x){
    while(hull.size() >= 2 && hull[0].val(x) >= hull[1].val(x))
        hull.pop_front();
    return hull[0].val(x);
}

int main(){
    int n;
    long long c;
    cin >> n >> c;
    long long a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<long long> dp(n);
    dp[0] = 0;
    addLine(-2 * a[0], a[0] * a[0]);

    for(int i = 1; i < n; i++){
        dp[i] = query(a[i]) + a[i] * a[i] + c;
        addLine(-2 * a[i], dp[i] + a[i] * a[i]);
    }

    cout << dp[n - 1] << endl;
    return 0;
}