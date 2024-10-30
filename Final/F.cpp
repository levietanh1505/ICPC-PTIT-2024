#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int freq[10] = {0};
    if(s.size() == 1){
        if(s == "8")cout << "YES";
        else cout << "NO";
        return 0;
    }
    if(s.size() == 2) freq[0] = 1;

    for (char c : s) {
        freq[c - '0']++;
    }

    int check = 0;
    for(int i = 111; i <= 999; i ++){
        
        if(i % 8 == 0){
            int ok = 0;
            string val = to_string(i);

            int freq1[10] = {0};
            for (char c : val) 
                freq1[c - '0']++;
            for(char c: val)
                if(freq[c - '0'] >= freq1[c -'0'])
                    ok++;

            if(ok == 3){
                cout << "YES ";
                check = 1;
                break;
            }
        }
        
    }
    if(!check) cout << "NO";
}