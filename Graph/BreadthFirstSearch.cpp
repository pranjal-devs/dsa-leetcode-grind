#include<bits/stdc++.h>
using namespace std;
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector<int> bfs;
    vector<int> vis(V + 1, 0); 
    queue<int> q;
    q.push(1); 
    vis[1] = 1;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for (auto it : adj[node]) {
            if (!vis[it]) {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}
int main() {
    int V = 9;
    vector<int> adj[V + 1];
    adj[1] = {2, 6};
    adj[2] = {1, 3, 4};
    adj[3] = {2};
    adj[4] = {2, 5};
    adj[5] = {4, 8};
    adj[6] = {1, 7, 9};
    adj[7] = {6, 8};
    adj[8] = {7, 5};
    adj[9] = {6}; 
    vector<int> result = bfsOfGraph(V, adj);
    for (int node : result) {
        cout << node << " ";
    }
    return 0;
}
