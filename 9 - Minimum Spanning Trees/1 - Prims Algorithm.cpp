#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*-----------This is @ayushmall06 --------------*/

class Graph{

	// Adjancency list
	vector<pair<int, int> > *l;
	int V;

public:
	Graph(int n) {
		V = n;
		l = new vector<pair<int,int> >[n];
	}

	void addEdge(int x, int y, int w) {
		l[x].push_back(make_pair(y,w));
		l[y].push_back(make_pair(x,w));
	} 

	int prim_mst() {
		// Initialize a min heap
		priority_queue<pair<int,int>, vector<pair<int, int> >, greater<pair<int,int> > > Q;

		// another array
		//visited array that denotes whether a node has been included in MST or not
		vector<bool> visited(V, false);
		int ans = 0;

		//begin
		Q.push(make_pair(0,0)); // wieght , node

		while(!Q.empty()) {
			// pick out the edge with min weight
			auto best = Q.top();
			Q.pop();

			int to = best.second;
			int weight = best.first;

			if(visited[to]) {
				// discard the edge, and continue
				continue;
			}

			// otherwise take the current edge
			ans += weight;
			visited[to] = 1;

			// add the new edges in the queue
			for(auto x: l[to]) {
				if(visited[x.first] == 0) {
					Q.push(make_pair(x.second, x.first));
				}
			}
		}
		return ans;

	}

};

int main() {

	int n, m;
	cin >> n >> m;

	Graph g(n);
	for(int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		g.addEdge(x-1,y-1,w);
	}
	
	cout << g.prim_mst() << endl;
	return 0;
}