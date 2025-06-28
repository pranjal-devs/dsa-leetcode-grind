#include<bits/stdc++.h>
using namespace std;

bool dfsCheck(int node,vector<int>adj[],int vis[],int pathVis[]){
    vis[node]=1;
    pathVis[node]=1;
    for(auto it : adj[node]){
        if(!vis[it]){
            if(dfsCheck(it,adj,vis,pathVis)==true){
                return true;
            }
        }else if(pathVis[it]){
            return true;
        }
    }
    pathVis[node]=0;
    return false;
}

bool isCyclic(int V,vector<int>adj[]){
    int vis[V]={0};
    int pathVis[V]={0};
    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(dfsCheck(i,adj,vis,pathVis)) return true;
        }
    }
    return false;
}

int main(){
    int V=11;
    vector<int> adj[V];
    adj[1]={2};
    adj[2]={3};
    adj[3]={4,7};
    adj[4]={5};
    adj[5]={6};
    adj[6]={};
    adj[7]={5};
    adj[8]={2,9};
    adj[9]={10};
    adj[10]={8};
    if(isCyclic(V,adj)){
        cout <<"A cycle is present in the graph";
    }else{
        cout << "A Cycle is not present in the graph";
    }
    return 0;
}