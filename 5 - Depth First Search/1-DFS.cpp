#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;

/*-----------This is @ayushmall06 --------------*/

class Graph {
	int V;
	list<int> *l;

public:
	Graph(int v) {
		V = v;
		l = new list<int>[V];
	}

	void addEdge(int x, int y, bool undir = true) {
		l[x].push_back(y);
		if(undir) {
			l[y].push_back(x);
		}
	}

	void dfsHelper(int node, vector<bool>& visited) {
		visited[node] = true;

		cout << node << "-->";

		// make a dfs call to all its unvisited neighbours
		for(int nbr: l[node]) {
			if(!visited[nbr]) {
				dfsHelper(nbr, visited);
			}
		}
	}

	void dfs(int source) {
		vector<bool> visited(V, false);
		dfsHelper(source, visited);
	}
};

int main() {
	Graph g(7);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,5);
	g.addEdge(5,6);
	g.addEdge(4,5);
	g.addEdge(0,4);
	g.addEdge(3,4);
	g.dfs(1);
	
	return 0;
}