#include<iostream>
#include<list>
#include<vector>
#include<unordered_map>
using namespace std;

/*-----------This is @ayushmall06 --------------*/

class Node{
public:
	string name;
	list<string> nbrs;

	Node(string name) {
		this->name = name;
	}
};

class Graph{
	// ALl Nodes
	// HashMaps (string, node*)
	unordered_map<string,Node*> m;

public:
	Graph(vector<string> cities) {
		for(auto city: cities) {
			m[city] = new Node(city);
		}
	}

	void addEdge(string x, string y, bool undir = false) {
		m[x]->nbrs.push_back(y);
		if(undir) {
			m[y]->nbrs.push_back(x);
		}
	}

	void printAdjList() {
		for(auto cityPair: m) {
			auto city = cityPair.first;
			Node* node = cityPair.second;
			cout << city << "--->";

			for(auto nbr: node->nbrs) {
				cout << nbr << " ,";
			}
			cout<< endl;
		}
	}

};

int main() {

	vector<string> cities; 
	cities.push_back("Delhi");
	cities.push_back("London");
	cities.push_back("Paris");
	cities.push_back("New York");
	Graph g(cities);

	g.addEdge("Delhi", "London");
	g.addEdge("New York","London");
	g.addEdge("Delhi", "Paris");
	g.addEdge("Paris", "New York");

	g.printAdjList();
	
	return 0;
}