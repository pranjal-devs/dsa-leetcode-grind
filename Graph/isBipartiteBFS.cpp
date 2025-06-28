#include<bits/stdc++.h>
using namespace std;

bool check(int start,int V,vector<int>adj[],int color[]){
    queue<int>q;
    q.push(start);
    color[start] = 0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it : adj[node]){
            if(color[it]==-1){
                color[it]=!color[node];
                q.push(it);
            }
            else if(color[it]==color[node]){
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(int V,vector<int>adj[]){
    int color[V];
    for(int i=0;i<V;i++) color[i] = -1;
    for(int i=0;i<V;i++){
        if(color[i]==-1){
            if(check(i,V,adj,color)==false){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int V = 8;
    vector<int> adj[V + 1];
    adj[1] = {2};
    adj[2] = {1,3,6};
    adj[3] = {2,4};
    adj[4] = {3,5,7};
    adj[5] = {4,6};
    adj[6] = {2,5};
    adj[7] = {4,8};
    adj[8] = {7}; 
    if(isBipartite(V,adj)){
        cout << "The graph is a bipartite";
    }else{
        cout << "The graph is not a bipartite";
    }
}