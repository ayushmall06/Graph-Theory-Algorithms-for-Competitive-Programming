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

	void bfs(int source, int dest = -1) {
		vector<bool> visited(V, false);
		queue<int> q;
		int *dist = new int[V];
		int *parent = new int[V];

		for(int i = 0; i < V; i++) {
			dist[i] = 0;
			parent[i] = -1;
		}

		parent[source] = source;
		visited[source] = true;
		q.push(source);
		while(!q.empty()) {
			int f = q.front();
			//cout << f << endl;
			q.pop();


			for(int nbr: l[f]) {
				if(!visited[nbr]) {
					q.push(nbr);
					visited[nbr] = true;
					parent[nbr] = f;
					dist[nbr] = dist[f]+1;
				}
			}
		}
		// Print the shortest distance from souce to dest
		for(int i = 0; i < V; i++) {
			cout << "Shortest Distance to "<< i << " is " << dist[i] << endl;
		} 


		// Shortest path
		if(dest != -1) {
			int temp = dest;
			while(temp != source) {
				cout << temp << "--";
				temp = parent[temp];
			}
			cout << source;
		}
	}



};

int main() {
	Graph g(7);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(3,5);
	g.addEdge(5,6);
	g.addEdge(4,5);
	g.addEdge(0,4);
	g.addEdge(3,4);
	g.bfs(1,6);
	
	return 0;
}