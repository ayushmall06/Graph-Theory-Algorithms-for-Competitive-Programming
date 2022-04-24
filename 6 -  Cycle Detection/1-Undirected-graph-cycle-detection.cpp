#include<iostream>
#include<list>
#include<vector>
using namespace std;

/*-----------This is @ayushmall06 --------------*/

class Graph{
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

	bool dfs(int source, vector<bool>& visited, int parent) {
		visited[source] = true;

		for(auto nbr: l[source]) {
			if(!visited[nbr]) {
				bool cycleFound = dfs(nbr, visited, source);
				if(cycleFound) return true;
			} 
			else if(nbr != parent) {
				return true;
			}
		}
		return false;
	}

	bool contains_cycle() {
		vector<bool> visited(V,0);
		return dfs(0, visited, 0);
	}


};

int main() {

	Graph g(3);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,0);
	cout << g.contains_cycle();
	
	return 0;
}