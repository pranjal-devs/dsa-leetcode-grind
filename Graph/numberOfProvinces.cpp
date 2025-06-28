#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<vector<int>>&adjLs,vector<int>&vis){
    vis[node]=1;
    for(auto it : adjLs[node]){
        if(!vis[it]){
            dfs(it,adjLs,vis);
        }
    }
}
int findCircleNum(vector<vector<int>>& adj) {
    int V=adj.size();
    vector<vector<int>>adjLs(V);
    // code to change the adjacency matrix to a list in cpp
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(adj[i][j]==1&&i!=j){
                adjLs[i].push_back(j);
                adjLs[j].push_back(i);
            }
       }
    }
    // now we have an adjacency list adjLs to get the dfs
    vector<int>vis(V,0);
    int cnt=0;
    for(int i=0;i<V;i++){
       if(!vis[i]){
            dfs(i,adjLs,vis);
            cnt++;
        }
    }
    return cnt;
}
int main(){  
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };
    int provinces = findCircleNum(isConnected);
    cout << "Number of provinces: " << provinces << endl;
    return 0;
}