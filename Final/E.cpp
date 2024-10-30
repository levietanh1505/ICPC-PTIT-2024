#include<bits/stdc++.h>

using namespace std;

struct edge {
	int u, v;
	long long cost;
	
	edge() : u(0), v(0), cost(0) {}
	edge(int u, int v, long long cost) : u(u), v(v), cost(cost) {}
};
bool cmp(const edge& a, const edge& b){ return a.cost - b.cost < 0; }

class dsu {
	private:
		vector<int> parent;
	public:
		dsu(int n){
			for(int i = 0; i < n; ++i)
				parent.push_back(i);
		}
		
		int find(int u){
			if(u == parent[u]) return u;
			return find(parent[u]);
		}
		bool unionSet(int u, int v){
			int root1 = find(u), root2 = find(v);
			if(root1 == root2) return false;
			parent[root2] = root1;
			return true;
		}
};

int main(){
	int n;	
	cin >> n;
	
	vector<pair<int, int> > p;
	for(int i = 1; i <= n; ++i){
		long long x, y;
		cin >> x >> y;
		p.push_back({x, y});	
	}
	sort(p.begin(), p.end());

	map<int, pair<int, int> > last;
	for(int i = 0; i < n; ++i)
		if(last.find(p[i].second) == last.end()) last[p[i].second] = {p[i].first, i};
		
	vector<edge> graph;
	for(int i = 0; i < n; ++i){
		for(auto it = last.begin(); it != last.end(); ++it){
			long long cost = 1LL * (p[i].first - (*it).second.first) * (p[i].first - (*it).second.first) 
						+ (p[i].second - (*it).first) * (p[i].second - (*it).first);
			graph.push_back({i, (*it).second.second, cost});
		}
		last[p[i].second] = {p[i].first, i};
	}
	sort(graph.begin(), graph.end(), cmp);
		
	dsu DSU(n);
	long long minCost = 0;
	for(edge& e : graph){
		if(!DSU.unionSet(e.u, e.v)) continue;
		minCost += e.cost;
	}
		
	cout << minCost;
}
