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

	void addEdge(int x, int y, bool undir = false) {
		l[x].push_back(y);
		if(undir) {
			l[y].push_back(x);
		}
	}

	bool dfs(int source, vector<bool>& visited, vector<bool>& stack) {
		visited[source] = true;
		stack[source] = true;

		for(auto nbr : l[source]) {
			if(stack[nbr] == true) {
				return true;
			}
			else if(!visited[nbr]) {
				bool foundCycle = dfs(nbr, visited, stack);
				if(foundCycle) return true;
			}
		}
		stack[source] = false;
		return false;
	}

};

int main() {

	Graph g(3);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,0);
	vector<bool> visited(3,0);
	vector<bool> stack(3,0);
	cout << g.dfs(0, visited, stack);
	
	return 0;
}