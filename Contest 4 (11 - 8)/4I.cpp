/*
Cho dãy ký tự dấu cộng (+) và trừ (-).

Với mỗi truy vấn gồm hai số a và b, hãy kiểm tra xem có cách nào lựa chọn trong hai số này kèm theo mỗi dấu cộng trừ thì ta được một dãy số có tổng bằng 0 hay không.

Ví dụ trong test 1 dưới đây, dãy ký tự là +-+---+-

Với hai số a = 2 và b = 1, ta có thể có cách lựa chọn:

{+1, -1, +2, -1, -1, -1, +2, -1} cho giá trị tổng bằng 0.
 */

#include<iostream>
#include<algorithm>

using namespace std;

using namespace std;

int main(){
    int N; cin >> N;
    string s; cin >> s;

    int countPlus = count(s.begin(), s.end(), '+'), 
        countSub = count(s.begin(), s.end(), '-');

    int T; cin >> T;
    while(T --){
                                    // am + bn = am' + bn';
        // m + n = countPlus;
        // m' + n' = countSub;
        // ==> m = m' + delta;
        // -> delta phải nguyên -> giải phương trình

        long long a, b; cin >> a >> b;

        if(a == b && countPlus == countSub){
            cout << "YES" << endl;
            continue;
        }
        
        if(a == b && countPlus != countSub){
            cout << "NO" << endl;
            continue;
        }

        if(b * (countSub - countPlus) % (a - b) != 0){
            cout << "NO" << endl;
            continue;
        }

        long long delta = b * (countSub - countPlus) / (a - b);

        long long m = delta;
        long long M = countSub + delta;

        if((m >= 0 && m <= countPlus) || (m < 0 && M >= 0 )) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}