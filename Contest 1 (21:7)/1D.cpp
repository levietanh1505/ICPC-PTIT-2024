#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int maxN = 1e6 + 2;             // kích thước tối đa của mảng

int n, st, en, u, d;
bool vis[maxN];                   // đánh dấu các đỉnh đã đi qua
int num[maxN];                    // số lần di chuyển để đến tầng ...        

void bfs(){
    fill_n(num, n + 1, 0);
    fill_n(vis, n + 1, false);

    queue<int> q;                  // chứa các đỉnh sẽ được duyệt

    q.push(st);
    vis[st] = true;
    
    while(!q.empty()){
        int x = q.front();
        q.pop();

        if(x == en) return;

        int temp[] = {x - d, x + u};
        for(int y : temp){
            if(y > n || y < 1) continue;

            if(!vis[y]){            // v chưa được duyệt
                vis[y] = true;
                num[y] = num[x] + 1;
                q.push(y);          // v đã được duyệt, loại v
            }
        }
    }

    num[en] = -1;
}

int main(){
    cin >> n >> st >> en >> u >> d;

    bfs();

    cout << num[en];
    return 0;
}
