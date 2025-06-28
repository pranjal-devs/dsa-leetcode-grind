#include<bits/stdc++.h>
using namespace std;

bool dfsCheck(int node,vector<int>adj[],int vis[],int pathVis[],int check[]){
    vis[node]=1;
    pathVis[node]=1;
    check[node]=0;
    for(auto it : adj[node]){
        if(!vis[it]){
            if(dfsCheck(it,adj,vis,pathVis,check)==true){
                check[node]=0;
                return true;
            }
        }else if(pathVis[it]){
            check[node]=0;
            return true;
        }
    }
    check[node]=1;
    pathVis[node]=0;    
    return false;
}

vector<int> safeNode(int V,vector<int>adj[]){
    int vis[V]={0};
    int check[V]={0};
    int pathVis[V]={0};
    vector<int>safeNodes;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            dfsCheck(i,adj,vis,pathVis,check);
        }
    }
    for(int i=0;i<V;i++){
        if(check[i]==1) safeNodes.push_back(i);
    }
    return safeNodes;
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
    vector<int>ans=safeNode(V,adj);
    for(auto it : ans){
        cout << it << " ";
    }
}