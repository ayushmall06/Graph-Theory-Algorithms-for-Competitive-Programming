#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*-----------This is @ayushmall06 --------------*/

class DSU {

	int *parent;
	int *rank;

public:
	DSU(int n) {
		parent = new int[n];
		rank = new int[n];

		// parent = -1, rank = 1
		for(int i =0; i <n; i++) {
			parent[i] = -1;
			rank[i] = 1;
		}
	}

	// Find Function
	int find(int i) {
		// base case
		if(parent[i] == -1) {
			return i;
		}

		return parent[i] = find(parent[i]);
	}

	// Unite function
	void unite(int x, int y) {
		int s1 = find(x);
		int s2 = find(y);

		if(s1 != s2) {
			// union by rank
			if(rank[s1] < rank[s2]) {
				parent[s1] = s2;
				rank[s2] += rank[s1];
			} else {
				parent[s2] = s1;
				rank[s1] += rank[s2];
			}
		}
	}
};


class Graph {

	vector<vector<int> > edgelist;
	int V;

public:
	Graph(int V) {
		this->V = V;
	}

	void addEdge(int x, int y, int w) {
		vector<int> edge;
		edge.push_back(w);
		edge.push_back(x);
		edge.push_back(y);
		edgelist.push_back(edge);
	}

	int kruskal_mst() {
		//1. Sort all edges based on their weight
		sort(edgelist.begin(), edgelist.end());

		int ans = 0;

		//Init a DSU
		DSU s(V);

		
		for(auto edge : edgelist) {
			int w = edge[0];
			int x = edge[1];
			int y = edge[2];


			// take the edge in MST if it doesn't form a cycle
			if(s.find(x) != s.find(y)) {
				s.unite(x,y);
				ans += w;
			}
		}
		return ans;
	}

};



int main() {
	Graph g(4);
	g.addEdge(0,1,1);
	g.addEdge(1,3,3);
	g.addEdge(3,2,4);
	g.addEdge(2,0,2);
	g.addEdge(0,3,2);
	g.addEdge(1,2,2);

	cout << g.kruskal_mst() << endl;
	
	return 0;
}
















