#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

// Dùng BIT - Cây chỉ số nhị phân
struct Query {
    int i, j, type, id;
    /*
    i, j: chỉ số khoảng truy vấn
    type: loại truy vấn (-1: update, 0: đếm số lượng phần tử duy nhất)
    id: chỉ số truy vấn
    */
};

/*
lastPos: vị trí cuối cùng mỗi phần tử trong mảng
bit: lưu trữ tổng phần tử khác nhau trong đoạn 1 - x
*/
int n, q, result[500001], lastPos[500001], bit[500001];
Query a[500001 + 500001];

/*
So sánh truy vấn: sort theo j, nếu j bằng nhau thì sort theo type
*/
bool compare(Query a, Query b) {
    return ((a.j < b.j) || (a.j == b.j && a.type < b.type));
}

/*
-x: bù 2 của x
x and -x: chỉ số LSB có giá trị bằng 1
*/
void update(int x, int k) {
    for (x; x <= n; x += x & -x) bit[x] += k;
}

int get(int x) {
    int result = 0;
    for (x; x > 0; x -= x & -x) result += bit[x];
    return result;
}

int main() {
    std::cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i].i;
        a[i].j = i;
        a[i].type = -1;
    }

    for (int i = 1; i <= q; ++i) {
        std::cin >> a[i + n].i >> a[i + n].j;
        a[i + n].id = i;
    }

    std::sort(a + 1, a + n + q + 1, compare);

    for (int i = 1; i <= n + q; ++i) {
        if (a[i].type == -1) {
            if (lastPos[a[i].i] != 0) update(lastPos[a[i].i], -1);
            update(a[i].j, 1);
            lastPos[a[i].i] = a[i].j;
        } else {
            /*
            get(a[i].j): tổng số phần tử duy nhất từ vị trí 1 đến vị trí j.
            get(a[i].i - 1): tổng số phần tử duy nhất từ vị trí 1 đến vị trí i
            - 1.
            */
            result[a[i].id] = get(a[i].j) - get(a[i].i - 1);
        }
    }

    for (int i = 1; i <= q; ++i) {
        std::cout << result[i] << std::endl;
    }
}
