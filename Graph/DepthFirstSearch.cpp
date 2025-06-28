#include<bits/stdc++.h>
using namespace std;
// starting node, adjacency list, visited array, dfss vector to store the final result
void dfs(int node,vector<int>adj[],int vis[],vector<int>&dfss){
    vis[node]=1;
    dfss.push_back(node);
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis,dfss);
        }
    }
}
vector<int>dfsOfGraph(int V,vector<int>adj[]){
    int vis[V+1]={0};
    int start=1;
    vector<int>dfss;
    dfs(start,adj,vis,dfss);
    return dfss;

}
using namespace std;
int main(){
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
    vector<int> result = dfsOfGraph(V, adj);
    for (int node : result) {
        cout << node << " ";
    }
    return 0;
}
