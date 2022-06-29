#include<iostream>
#include<vector>
#include<set>
using namespace std;

/*-----------This is @ayushmall06 --------------*/

const int  N = 1e5;

vector<int> gr[N];

int vis[N], disc[N], low[N], tme = 1;

set<pair<int,int> > bridges;
set<int> articulationPoints;

void dfs(int cur, int par) {
	vis[cur] = 1;
	disc[cur] = low[cur] = tme++;
	

	int child = 0;
	for(auto nbr: gr[cur]) {
		if(vis[cur] == 0) {
			child++;
			dfs(nbr, cur);
			// we know low and disc of x 
			low[cur] = min(low[cur], low[nbr]);

			// bridges
			if(low[nbr] > disc[cur]) {
				bridges.insert(make_pair(cur, nbr));
			}

			//articulation points
			if(par != 0 && (low[nbr] >= disc[cur])) {
				articulationPoints.insert(cur);
			}

		} else if(nbr != par) {
			//backedge
			low[cur] = min(low[cur], disc[nbr]);
		}
	}

	if(par == 0 && child > 1) {
		articulationPoints.insert(cur);
	}

	return;
}


int main() {
	
	int n, m;
	cin >> n >> m;

	for(int i = 0; i < N; i++) {
		vis[i] = 0;
	}

	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}

	dfs(1,0);

	cout << "Number of articulation points " << articulationPoints.size() << endl;

	// Articulation Points
	for(auto x : articulationPoints) cout << x << " ";

	return 0;
}