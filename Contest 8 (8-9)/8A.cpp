#include <bits/stdc++.h>
using namespace std;

/*
Thuật toán Welzl tìm đường tròn bao nhỏ nhất bằng cách thêm các điểm vào một tập
hợp ràng buộc (constrained set) một cách ngẫu nhiên. Nếu đã tìm được một đường
tròn bao qua các điểm trong tập ràng buộc, thuật toán kiểm tra xem các điểm khác
có nằm bên trong đường tròn hay không. Nếu một điểm nằm bên ngoài, thuật toán sẽ
bao gồm điểm đó vào trong tập ràng buộc và tiếp tục tìm đường tròn bao nhỏ nhất
cho tập mới.*/

struct Point {
    double x, y;
};

// Tính khoảng cách giữa hai điểm
double distance(const Point &A, const Point &B) {
    return sqrt((B.x - A.x) * (B.x - A.x) + (B.y - A.y) * (B.y - A.y));
}

// Tìm tâm và bán kính của đường tròn đi qua hai điểm
pair<Point, double> circleFromTwoPoints(Point A, Point B) {
    Point center = {(A.x + B.x) / 2.0, (A.y + B.y) / 2.0};
    double radius = distance(A, B) / 2.0;
    return {center, radius};
}

// Tìm tâm và bán kính của đường tròn đi qua ba điểm
pair<Point, double> circleFromThreePoints(Point A, Point B, Point C) {
    double D = 2 * (A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y));
    double ux = ((A.x * A.x + A.y * A.y) * (B.y - C.y) +
                 (B.x * B.x + B.y * B.y) * (C.y - A.y) +
                 (C.x * C.x + C.y * C.y) * (A.y - B.y)) /
                D;
    double uy = ((A.x * A.x + A.y * A.y) * (C.x - B.x) +
                 (B.x * B.x + B.y * B.y) * (A.x - C.x) +
                 (C.x * C.x + C.y * C.y) * (B.x - A.x)) /
                D;
    Point center = {ux, uy};
    double radius = distance(center, A);
    return {center, radius};
}

// Kiểm tra xem một điểm có nằm trong hoặc trên đường tròn không
bool isInside(const Point &center, double radius, const Point &p) {
    return distance(center, p) <= radius;
}

// Thuật toán Welzl (Helper)
pair<Point, double> welzlHelper(vector<Point> &P, vector<Point> R, int n) {
    if (n == 0 || R.size() == 3) {
        if (R.size() == 0) return {{0, 0}, 0};
        if (R.size() == 1) return {R[0], 0};
        if (R.size() == 2) return circleFromTwoPoints(R[0], R[1]);
        return circleFromThreePoints(R[0], R[1], R[2]);
    }

    Point p = P[n - 1];
    auto circle = welzlHelper(P, R, n - 1);

    if (isInside(circle.first, circle.second, p)) {
        return circle;
    }

    R.push_back(p);
    return welzlHelper(P, R, n - 1);
}

// Thuật toán Welzl chính
pair<Point, double> welzl(vector<Point> &P) {
    random_shuffle(P.begin(), P.end());
    return welzlHelper(P, {}, P.size());
}

int main() {
    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    auto [center, radius] = welzl(points);

    cout << fixed << setprecision(6) << radius << "\n";

    return 0;
}
