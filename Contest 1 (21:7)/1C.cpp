#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
bool isInCol[100],                    // kiểm tra trên cột i
     isInDiag1[100],                  // kiểm tra trên đường chéo phụ tổng i
     isInDiag2[100];                  // kiểm tra trên đường chéo chính hiệu i
vector <int> QueenSetX, QueenSetY;    // vị trí quân Hậu
long long cnt = 0;                          // số cách sắp xếp

void genQueenSet(int row){
    for(int col = 1; col <= n; col++){
        int diag1 = col + row,          // quân Hậu nằm trên đường chéo phụ tổng i
            diag2 = row - col + n;      // quân Hậu nằm trên đường chéo chính hiệu i (+n để tránh âm)
        
        // Kiểm tra tọa độ
        if(isInCol[col]) continue;
        if(isInDiag1[diag1]) continue;
        if(isInDiag2[diag2]) continue;
        
        // Nếu không bị ăn thì đánh dấu
        QueenSetX.push_back(row);
        QueenSetY.push_back(col);
        isInCol[col] = true;
        isInDiag1[diag1] = true;
        isInDiag2[diag2] = true;

        // Đủ số quân Hậu -> in ra, kết thúc; nếu không -> tiếp tục đệ quy
        if(QueenSetX.size() == n) cnt++;      //do tối đa chỉ có n quân hậu
        else genQueenSet(row + 1);

        // Xóa quân Hậu vừa thêm
        QueenSetX.pop_back();
        QueenSetY.pop_back();
        isInCol[col] = false;
        isInDiag1[diag1] = false;
        isInDiag2[diag2] = false;
    }
}

int main(){
    cin >> n;

    memset(isInCol, 0, sizeof(isInCol));
    memset(isInDiag1, 0, sizeof(isInDiag1));
    memset(isInDiag2, 0, sizeof(isInDiag2));

    genQueenSet(1);                             // Xét theo hàng, bắt đầu từ 1 đến n

    cout << cnt;
    return 0;
}
