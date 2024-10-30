// Trên mỗi ô của vùng diện tích có kích thước MxN, các khối vuông đơn vị (kích thước 1x1x1) được xếp chồng lên nhau để tạo thành một khối lớn có chiều cao bằng H[i, j]. Các khối lớn khi được đặt cạnh nhau sẽ che phủ một phần mặt bên của chúng.
//Nhiệm vụ của bạn là hãy tính diện tích toàn phần của khối thể tích thu được, bao gồm cả phần bề mặt trên, mặt đáy và bốn mặt xung quanh.

#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int main(){
    int t;  cin >> t;
    while(t--){
        int n, m;   cin >> m >> n;
        int h[m + 2][n + 2];
        memset(h, 0, sizeof(h));
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
                cin >> h[i][j];
        
        int res = 2 * m * n;
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
                if(h[i][j] == 0) res -= 2;
                else res += max(h[i][j] - h[i - 1][j], 0) + max(h[i][j] - h[i + 1][j], 0) 
                            + max(h[i][j] - h[i][j - 1], 0) + max(h[i][j] - h[i][j + 1], 0);
                
        cout << res << endl;
    }
    return 0;
}