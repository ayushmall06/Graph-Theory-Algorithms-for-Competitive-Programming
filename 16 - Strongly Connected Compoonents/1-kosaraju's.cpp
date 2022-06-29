#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 1e5 + 1;

vector<int> gr[N], grr[N];

int vis[N], color[N];
vector<int> order;

/*-----------This is @ayushmall06 --------------*/

// topological sorting
void dfs1(int cur) {
	vis[cur] = 1;

	for(auto x : gr[cur]) {
		if(!vis[x]) dfs1(x);
	}
	order.push_back(cur);

}

void dfs2(int cur, int comp) {
	vis[cur] = 1;
	color[cur] = comp;

	for(auto x : grr[cur]) {
		if(!vis[x]) dfs2(x, comp);
	}

}

int main() {

	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		grr[y].push_back(x);
	}

	for(int i = 1; i<= n; i++) {
		if(!vis[i]) dfs1(i);
	}

	reverse(order.begin(), order.end());
	memset(vis, 0, sizeof(vis));

	int comp = 1;
	for(auto x: order) {
		if(!vis[x]) {
			dfs2(x, comp++);
		}
	}

	for(int i = 1; i <= n; i++) {
		cout << i << " " << color[i] << endl;
	}

	cout << "Total strongly components are " << --comp << endl;
	
	return 0;
}