#include<iostream>
#include<list>
using namespace std;

/*-----------This is @ayushmall06 --------------*/
/* 
 	OTPIMIZATIONS:-
 		1. Path Compression Optimization in DSU (Find Fn)
 		2. Union By Rank (Union Fn)
*/

class Graph{
	int V;
	list<pair<int,int> > l;

public:
	Graph(int V) {
		this->V = V;
	}

	void addEdge(int x, int y) {
		l.push_back(make_pair(x,y));
	}

	// Find Set
	int findSet(int x, int parent[]) {
		// base case
		if(parent[x] == -1) {
			return x;
		} 

		// Path Compression Optimization
		return parent[x] = findSet(parent[x], parent);
	}

	//Union Set
	void union_set(int x, int y, int parent[], int rank[]) {
		int s1 = findSet(x, parent);
		int s2 = findSet(y, parent);

		if(s1 != s2) {
			if(rank[s1] < rank[s2]) {
				parent[s1] = s2;
				rank[s2] += rank[s1];
			}
			else {
				parent[s2] = s1;
				rank[s1] += rank[s2];
			}
		}
	}

	bool contains_cycle() {
		int *parent = new int[V];
		int *rank = new int[V];

		for(int i = 0; i < V; i++) {
			parent[i] = -1;
			rank[i] = 1;
		}

		for(auto edge: l) {
			int x = edge.first;
			int y = edge.second;

			int s1 = findSet(x, parent);
			int s2 = findSet(y, parent);

			if(s1 != s2) {
				union_set(s1, s2, parent, rank);
			} else {
				return true;
			}
		}
	}

};

int main() {
	Graph g(4);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	//g.addEdge(3,0);
	cout << g.contains_cycle();
	return 0;
}