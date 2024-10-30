#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

// Ý tưởng sử dụng DSU tạo đồ thị liên kết các link kiện lại với nhau thành một đồ thị,
//mỗi đỉnh là một linh kiện và mỗi cạnh giữa 2 đỉnh là tồn tại hiệu khối lượng giữa 2
//link kiện tương ứng
class setunion {
    private:
        vector<int> parent;             // lưu trữ gốc
        vector<int> rank;               // bậc
        vector<int> w;                  // Khối lượng
    public:
        setunion(int n) : rank(n, 0), w(n, 0) {
            for(int i = 0; i < n; ++i) parent.push_back(i);
        }
        // Tìm về góc của cây
        int find(int u){
            if(parent[u] != u){
                // gốc hiện tại của u
                int tmp = parent[u];            
                parent[u] = find(parent[u]);
                w[u] += w[tmp];
            }
            return parent[u];
        }
        // Gộp 2 cây
        // w_y - w_x = w
        void unionSet(int x, int y, int weight){
            int rootX = find(x), rootY = find(y);

            if(rootX == rootY) return;
            if(rank[rootX] > rank[rootY]){      //y --> x
                parent[rootY] = rootX;
                w[rootY] = w[x] - w[y] + weight;
            } else {                            // x --> y
                parent[rootX] = rootY;
                w[rootX] = w[y] - w[x] - weight;
            }
        }

        int getDiffWeight(int x, int y){
            if(find(x) != find(y)) return INT_MAX;
            return w[y] - w[x];
        }
};

int main(){
    int t;  cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        setunion dsu(n);
        while(m--){
            char type;
            int a, b; 
            cin >> type;
            if(type == '!'){
                int w;
                cin >> a >> b >> w;
                dsu.unionSet(a - 1, b - 1, w);
            }
            else {
                cin >> a >> b;
                int diff = dsu.getDiffWeight(a - 1, b - 1);
                if(diff == INT_MAX) cout << "UNKNOWN" << endl;
                else cout << diff << endl;
            }
        }
    }
}