#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <tuple>
#include <list>
#include <iomanip>
#include <cmath>
#include <unordered_map>
#include <unordered_set>

using namespace std;

string operate = "+-*";

long long n, m;
long long cnt;
vector<long long> a;

// Cach nop khi thi
/*
long long prio(char op){
    if(op == '+' || op == '-') return 1;
    return 2;
}

void process(vector<long long>& val, char op){
    long long n2 = val.back();     val.pop_back();
    long long n1 = val.back();     val.pop_back();

    switch(op){
        case '+':   val.push_back(n1 + n2); break;
        case '-':   val.push_back(n1 - n2); break;
        case '*':   val.push_back(n1 * n2); break;
        default:   break;
    }   
}

long long solve(string s){
    vector<long long> val;
    vector<char> op;

    for(long long i = 0; i <  s.size(); ++i){
        if(isdigit(s[i])){
            long long num = 0;
            while(i < s.size() && isdigit(s[i])){
                num = num * 10 + (s[i] - '0');
                ++i;
            }
            val.push_back(num);
            --i;
        }
        else{
            if(!op.empty() && prio(op.back()) >= prio(s[i])){
                process(val, op.back());
                op.pop_back();
            }
            op.push_back(s[i]);
        }
    }
    while(!op.empty()){
        process(val, op.back());
        op.pop_back();
    }
    return val.back();
}

bool check(string s){
    return solve(s) % m == 0;
}
*/

bool check(string s){
    stack<long long> st;
    st.push(a[0]);
    for(int i = 0; i < n - 1; ++i)
        if(s[i] == '+')
            st.push(a[i + 1]);
        else if(s[i] == '-')
            st.push(-a[i + 1]);
        else{
            long long tmp = st.top();
            st.pop();
            st.push(tmp * a[i + 1]);
        }
    long long sum = 0;
    while(!st.empty()){
        sum += st.top();
        st.pop();
    }
    return sum % m == 0;
}


void backtrack(long long idx, string expression){
    if(idx == n - 1){
        expression += to_string(a[idx]);
        cnt += check(expression);
        return;
    }
    for(char op : operate){
        backtrack(idx + 1, expression + to_string(a[idx]) + op);
    }
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        cnt = 0;
        cin >> n >> m;
        a.clear();
        a.resize(n);
        for (long long i = 0; i < n; ++i) cin >> a[i];
        string s;
        backtrack(0, s);
        cout << cnt << endl;
    } 
    return 0;
}