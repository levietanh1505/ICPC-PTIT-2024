#include<iostream>
#include<string>

using namespace std;

int main(){
    string a, b;
    cin >> a >> b;
    
    int idx = 0;
    while(a.find(b, idx) != string::npos){
        idx = a.find(b, idx) + 1;
        cout << idx << ' ';
    }

    return 0;
}