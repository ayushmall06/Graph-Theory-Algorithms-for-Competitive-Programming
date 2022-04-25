#include<iostream>
#include<map>
#include<list>
#include<vector>
#include<queue>
#include<cstring>
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

	void addEdge(int x, int y) {
		l[x].push_back(y);
	}

	void dfs(int node, vector<bool>& visited, list<int>& ordering) {

		visited[node] = true;

		for(int nbr: l[node]) {
			if(!visited[nbr]) {
				dfs(nbr, visited, ordering);
			}
		}

		ordering.push_front(node);
		return;

	}


	void topological_sort_dfs() {

		vector<bool> visited(V, false);
		list<int> ordering;

		// we call dfs from every node if it is not visited
		for(int i = 0; i < V; i++) {
			if(!visited[i]) {
				dfs(i, visited, ordering);
			}
		}

		// Print the topological sort
		for(auto node: ordering) {
			cout << node << " ";
		}

	}

};

int main() {
	Graph g(6);
	g.addEdge(0,2);
	g.addEdge(2,3);
	g.addEdge(3,5);
	g.addEdge(4,5);
	g.addEdge(1,4);
	g.addEdge(1,2);
	
	g.topological_sort_dfs();

	
	return 0;
}