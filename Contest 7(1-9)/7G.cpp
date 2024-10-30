// Bạn là thuyển trưởng của một con tàu, hiện tại bạn đang ở vị trí [x1, y1].
// Công việc của bạn là tìm cách đưa con tàu đến vị trí [x2, y2].
// Trên biển gió có thể thổi theo 4 chiều: trên, dưới, trái, phải - tương ứng với U, D, L và R.
// Giả sử con tàu đứng yên:
//      Nếu gió thổi theo hướng U, sau 1 giờ nó sẽ di chuyển từ tọa độ [x, y] đến [x, y + 1].
//      Nếu gió thổi theo hướng D, sau 1 giờ nó sẽ di chuyển từ tọa độ [x, y] đến [x, y - 1].
//      Nếu gió thổi theo hướng L, sau 1 giờ nó sẽ di chuyển từ tọa độ [x, y] đến [x - 1, y].
//      Nếu gió thổi theo hướng R, sau 1 giờ nó sẽ di chuyển từ tọa độ [x, y] đến [x + 1, y].
// Con tàu có tốc độ di chuyển 1 (đơn vị độ dài / giờ) và chỉ được phép đi song song với 2 trục tọa độ.
// Giả sử con tàu di chuyển theo hướng L và gió thổi theo hướng U, nó sẽ di chuyển từ vị trí [x, y] tới [x - 1, y + 1], còn nếu hướng di chuyển con tàu và hướng gió đều là U, sau 1 tiếng nó sẽ di chuyển từ [x, y] tới [x, y + 2].
// Cho [x1, y1], [x2, y2] và xâu ký tự S cho biết hướng gió TẠI THỜI ĐIỂM MỖI GIỜ, hãy tìm thời gian nhỏ nhất để con tàu tới được đích, biết hướng gió biến đổi tuần hoàn.

#include <iostream>


using namespace std;

int startX, startY, endX, endY;
int n;
string s;

bool canReachInTime(int t) {
    int fullCycles = t / n;
    int remainingTime = t % n;

    int x = startX, y = startY;
    int deltaX = 0, deltaY = 0;

    for (char wind : s) {
        if (wind == 'U')
            deltaY++;
        else if (wind == 'D')
            deltaY--;
        else if (wind == 'L')
            deltaX--;
        else if (wind == 'R')
            deltaX++;
    }

    x += fullCycles * deltaX;
    y += fullCycles * deltaY;

    for (int i = 0; i < remainingTime; ++i) {
        char wind = s[i];
        if (wind == 'U')
            ++y;
        else if (wind == 'D')
            --y;
        else if (wind == 'L')
            --x;
        else if (wind == 'R')
            ++x;
    }

    return abs(endX - x) + abs(endY - y) <= t;
}

int solve() {
    int low = 0, high = 1e8, result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canReachInTime(mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> startX >> startY >> endX >> endY;
    cin >> n;
    cin >> s;

    cout << solve() << endl;

    return 0;
}