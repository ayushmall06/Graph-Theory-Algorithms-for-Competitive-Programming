#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int x, y, dist;
    
   
    Node(int x, int y, int dist) {
        this->x = x;
        this->y = y;
        this->dist = dist;
    }
    
};


class Compare{
    public:
    bool operator()(const Node &a, const Node &b) {
        return a.dist <= b.dist;
    }
};
int shortest_path(vector<vector<int> > grid){
    //return the shortest path len
    int m = grid.size();
    int n = grid[0].size();
    
    int i = 0;
    int j = 0;
    
    // 2-D vector to denote each cell
    vector<vector<int>> dist(m+1, vector<int>(n+1, INT_MAX));
    
    dist[i][j] = grid[0][0];
    
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    
    set<Node,Compare> s;
    s.insert(Node(0,0,dist[i][j]));
    
    while(!s.empty()) {
        
        auto it = s.begin();
        int cx = it->x;
        int cy = it->y;
        int cd = it->dist;
        s.erase(it);
        
        for(int k = 0; k < 4; k++) {
            int nx = cx + dx[k];
            int ny = cy + dy[k];
            
            if(nx >= 0 && nx < m && ny >= 0 && ny < n && cd + grid[nx][ny] < dist[nx][ny]) {
                // Remove the current if exits
                auto f = s.find(Node(nx, ny, dist[nx][ny]));
                if(f != s.end()) {
                    s.erase(Node(nx, ny, dist[nx][ny]));
                }
                
                
                int nd = cd + grid[nx][ny];
                dist[nx][ny] = nd;
                s.insert(Node(nx, ny, dist[nx][ny]));
            }
        }
    }
    return dist[m-1][n-1];
    
    
}