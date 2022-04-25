#include<iostream>
#include<vector>
using namespace std;

/*-----------This is @ayushmall06 --------------*/

bool dfs_helper(vector<int> graph[], int node, vector<int>& visited,int parent, int color) {
	// come to node
	visited[node] = color;  // 1 or 3 both mean visited

	for(auto nbr: graph[node]) {
		if(visited[nbr] == 0) {
			int subProblem = dfs_helper(graph, nbr, visited, node, 3 - color);

			if(subProblem == false) {
				return false;
			}
		}
		else if(nbr != parent && color == visited[nbr]) 
		{
			return false;
		}
	}
	return false;
}

bool dfs(vector<int> graph[], int N) {
	vector<int> visited(N, 0);  // 0 - Not Visited, 1 - Visited Color is 1, 2 - Visited COlor 2

	int color = 1;
	bool ans = dfs_helper(graph, 0, visited, 0, color); 
	return ans;
}

int main() {


	int N, M;

	cin >> N >> M;

	vector<int> graph[N];
	while(M--) {
		int x, y;

		cin >> x >> y;

		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	if(dfs(graph, N)) cout << "Yes";
	else cout << "No";
	return 0;
}