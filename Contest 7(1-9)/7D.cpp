// Các nhà khảo cổ mới phát hiện ra một khu Hoàng Thành được xây dựng từ nhiều thế kỷ trước. Theo nhận định ban đầu, Hoàng Thành gồm nhiều bức tường song song hoặc vuông góc với nhau. Để tiến hành nghiên cứu, các nhà khảo cổ đã xây dựng bản đồ các bức tường của khu Hoàng Thành. Cụ thể, bản đồ được mô tả trên mặt phẳng toạ độ Đề các vuông góc Oxy trong đó các bức tường là các đoạn thẳng song song với một trong hai trục tọa độ. Theo các dữ liệu thu thập được, có N bức tường được đánh số từ 1 đến N. Bức tường thứ i là đoạn thẳng nối từ điểm có tọa độ nguyên (x[i], y[i]) đến điểm có tọa độ nguyên (u[i], v[i]), i = 1, 2, …, N. Hai đoạn thẳng mô tả hai bức tường khác nhau có không quá một điểm chung.
//Để in bản đồ, các nhà khảo cổ dùng một máy vẽ chuyên dụng hoạt động theo nguyên tắc:
//- Bước 1: Chọn một điểm có tọa độ nguyên, bút vẽ của máy vẽ được kích hoạt để di chuyển và hạ đầu bút xuống điểm này;
// - Bước 2: Bút vẽ di chuyển liên tục song song với một trong hai trục để vẽ các đoạn thẳng mô tả các bức tường trong bản đồ;
// - Bước 3: Nếu đã vẽ xong toàn bộ các bức tường thì kết thúc công việc, trong trường hợp ngược lại, quay về Bước 1 để tiếp tục thực hiện việc vẽ.
// Hoạt động của máy vẽ được tối ưu hóa sao cho không có đoạn nào được vẽ quá một lần và số lần kích hoạt bút vẽ là ít nhất. 
// Yêu cầu: Cho biết các đoạn thẳng mô tả các bức tường, hãy tính số lần kích hoạt bút vẽ ít nhất vẽ được bản đồ mô tả các bức tường của Hoàng Thành.

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<list>

using namespace std;

const int N = 1002;     // max segment

struct point {
    int x, y;

    point(int x , int y): x(x), y(y) {}
};

struct edge{            // Đỉnh
    point src, tar;
    int id;
    bool isFake;

    edge(int x1, int y1, int x2, int y2, int id, bool fake = false): 
        src(x1, y1), tar(x2, y2), id(id), isFake(fake) {}
};

struct Graph {
    int edges;
    vector<vector<vector<edge> > > g;   //g[x][y] là các điểm liên kết với điểm (x, y)

    Graph(){
        edges = 0;
        g.clear();
        g.resize(N * 2);
        for(int i = 0; i < N * 2; ++i) g.at(i).resize(N * 2);
    }


    void addEdge(int x, int y, int u, int v, bool fake = false) {
        g[x][y].emplace_back(x, y, u, v, edges, fake);
        g[u][v].emplace_back(u, v, x, y, edges, fake);
        ++edges;
    }

    void addFakeEdges() {
        for (int i = 0; i < N * 2; ++i)
            for (int j = 0; j < N * 2; ++j) {
                if (g[i][j].size() % 2 != 0) {
                    // Nối đỉnh bậc lẻ với đỉnh ảo
                    addEdge(i, j, 0, 0, true);
                }
            }
    }

    void addSegment(int x1, int y1, int x2, int y2) {
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);

        if (x1 == x2) { // nếu đoạn thẳng song song với trục Oy
            for (int i = y1; i < y2; ++i) {
                addEdge(N + x1, N + i, N + x2, N + i + 1);
            }
        } else { // nếu đoạn thẳng song song với trục Ox
            for (int i = x1; i < x2; ++i) {
                addEdge(N + i, N + y1, N + i + 1, N + y2);
            }
        }
    }
};

int n;
vector<bool> isVisited;
Graph graph = Graph();
vector<vector<point> > res;

list<edge> euler(point str, Graph &graph){
    list<edge> path;

    // Duyệt qua các cạnh có đầu mút str
    while(!graph.g.at(str.x).at(str.y).empty()){
        edge e = graph.g.at(str.x).at(str.y).back();
        graph.g.at(str.x).at(str.y).pop_back();
        
        if(!isVisited[e.id]) continue;

        isVisited[e.id] = false;
        path.emplace_back(e);
        str = e.tar;
    }

    // Duyệt lại từ điểm bắt đầu các cạnh (không phải str) để tìm thêm chu trình euler
    list<edge>::iterator it = --path.end();
    while(it != path.begin()){
        list<edge>::iterator tmp = it;
        --tmp;
        path.splice(it, euler(it->src, graph));
        it = tmp;
    }

    return path;
} 

int main(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        graph.addSegment(x, y, u, v);
    }
    graph.addFakeEdges();

    isVisited.clear();
    isVisited.assign(graph.edges, true);
    res.clear();

    for(int i = 0; i < N * 2; ++i)
        for(int j = 0; j < N * 2; ++j)
            if(!graph.g.at(i).at(j).empty()){
                // Tìm chu trình euler bắt đầu tại (i, j)
                list<edge> path = euler(point(i, j), graph);
                // Loại bỏ cạnh ảo để xác định đường đi khác nha
                vector<point> tmp;
                for(list<edge>::iterator it = path.begin(); it != path.end(); ++it){
                    if(it->isFake){
                        if(!tmp.empty()){
                            res.push_back(tmp);
                            tmp.clear();
                        }
                    } else {
                        if(tmp.empty()) tmp.push_back(it->src);
                        tmp.push_back(it->tar);
                    }
                }
                if(!tmp.empty()) res.push_back(tmp);
            }
    
    cout << res.size();
    return 0;
}
