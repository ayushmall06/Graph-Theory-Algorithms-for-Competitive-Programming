#include<iostream>
#include<vector>
using namespace std;

/*-----------This is @ayushmall06 --------------*/

const int N = 1e5 + 1;

// Adjacency list
vector<int> gr[N];
int vis[N];

void dfs(int cur, int par) {
	cout << cur << "\n";
	vis[cur] = 1;
	for(auto x : gr[cur]) {
		if(!vis[x]) {
			dfs(x, cur);
		} else if(x != par){
			// backedge
			cout << cur << " " << x << "\n";
		}
	}
}

int main() {
	
	int n, m;
	cin >> n >> m;

	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;

		gr[x].push_back(y);
		gr[y].push_back(x);

	}

	for(int i = 1; i < n; i++) {
		if(!vis[i]) {
			dfs(i,-1);
		}
	}


	return 0;
}