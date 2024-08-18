// Cho N điểm trên mặt phẳng Oxy. Nhiệm vụ của bạn là xác định xem có tồn tại một đường tròn ngoại tiếp của 3 đỉnh 
// và thỏa mãn có đúng K điểm nằm trong đường tròn hay không (không tính các điểm nằm trên đường tròn).
// Dữ liệu vào:
// Dòng đầu tiên là số lượng bộ test T (T ≤ 10).
// Mỗi test gồm số nguyên N (3 ≤ N ≤ 100), là số lượng điểm trên mặt phẳng. Dòng tiếp theo là số nguyên K (1 ≤ K ≤ 100).
// N dòng tiếp theo, dòng thứ i gồm 2 số nguyên xi, yi  (-1000 ≤ xi, yi ≤ 1000).
// Kết quả: 
// Với mỗi test, in ra “YES” nếu tìm được đường tròn chứa đúng K điểm. In ra “NO” trong trường hợp ngược lại.
// Ví dụ:                  
// Input
// Output
// 2
// 4
// 1
// 0 0
// 5 0
// 0 5
// 1 1
// 5
// 2
// 5 5
// 5 -5
// -5 5
// -5 -5
// 0 0
// YES
// NO

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

struct point { double x, y; };

double distance(point A, point B){  return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y)); }

bool isStraight(point A, point B, point C){ return (A.x - B.x) * (A.y - C.y) == (A.y - B.y) * (A.x - C.x); }

bool isInsideCircle(point A, point center, double radius){ return distance(A, center) - radius < 0; }

pair<point, double> circle(point A, point B, point C){
    double a = B.x - A.x, b = B.y - A.y;
    double c = C.x - A.x, d = C.y - A.y;
    double e = a * (A.x + B.x) + b * (A.y + B.y);
    double f = c * (A.x + C.x) + d * (A.y + C.y);
    double g = 2 * (a * (C.y - B.y) - b * (C.x - B.x));
    point center;
    center.x = (d * e - b * f) / g;
    center.y = (a * f - c * e) / g;
    double radius = distance(center, A);
    return make_pair(center, radius);
}


int main() {
    int t;  cin >> t;
    while(t--){
        int n, k;  cin >> n >> k;
        vector<point> p(n);
        for(int i = 0; i < n; ++i) cin >> p[i].x >> p[i].y;

        bool check = false;
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                for(int h = j + 1; h < n; ++h){
                    if(!isStraight(p[i], p[j], p[h])){
                        pair<point, double> C = circle(p[i], p[j], p[h]);
                        int count = 0;
                        for(int l = 0; l < n; ++l)
                            if(l != i && l != j && l!= h && isInsideCircle(p[l], C.first, C.second))
                                ++count;
                        if(k == count){
                            check = true;
                            break;
                        }
                    }
                }
                if(check) break;
            }
            if(check) break;
        }
        cout << (check ? "YES" : "NO") << endl;
    }
    return 0;
}
