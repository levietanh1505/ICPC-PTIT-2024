// Cho K dãy số nguyên, các số trong dãy thuộc [-10^9…10^9]. Hãy viết chương trình tìm số xuất hiện trong cả K dãy.
// Nếu không có số nào xuất hiện trong cả K dãy thì in ra “NO”, còn nếu có nhiều số cùng xuất hiện trong K dãy thì ghi số nhỏ nhất tìm được.

#include<iostream>
#include<set>
#include<vector>

using namespace std;

int main(){
    int k;  cin >> k;
    int len[k];
    for(int i = 0; i < k; ++i)  cin >> len[i];

    vector<set<int> > a(k);    
    for(int i = 0; i < k; ++i)
        for(int j = 0; j < len[i]; ++j){
            int n;    cin >> n;
            a[i].insert(n);
        }
    
    set<int> res = a[0];
    for(int i = 1; i < k; ++i){
        set<int> tmp;
        for(int x : a[i])
            if(res.find(x) != res.end())
                tmp.insert(x);
        res = tmp;
    }

    if(res.empty()) cout << "NO";
    else cout << *res.begin();
    return 0;
}