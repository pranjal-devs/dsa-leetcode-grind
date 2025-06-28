#include<bits/stdc++.h>
using namespace std;
bool detect(int src,vector<int>adj[],int vis[]){ // this function takes arguement source node, a vector adjacency list and a visited array 
    vis[src] = 1; // we mark the source node as 1 in the visited array
    queue<pair<int,int>>q; // ({node,parent}) where the node is the current node and the parent is the node from where it is coming from
    q.push({src,-1}); // we push the source and parent in the queue here the first source is -1(let)
    while(!q.empty()){ // loop for the bfs traversal 
        int node=q.front().first;  // fetching the node and the parent 
        int parent=q.front().second;
        q.pop(); // post storing clear the queue so that at last it becomes empty
        for(auto adjacentNode : adj[node]){ // a loop to traverse the adjacency list
            if(!vis[adjacentNode]){  // if the node is not visited
                vis[adjacentNode]=1; // mark it as visited
                q.push({adjacentNode,node}); // push it to the queue
            }
            else if(parent!=adjacentNode){ // this is the condition when the previous node might be visited but the next node is also visited
                return true; // we say that there is a cycle present
            }
        }
    }
    return false;
}
bool isCycle(int V,vector<int>adj[]){
    int vis[V]={0};
    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(detect(i,adj,vis)){
                return true;
            }
        }
    }
    return false;
}
int main(){
    int V=7;
    vector<int>adj[V+1];
    adj[1]={2,3};
    adj[2]={1,5};
    adj[3]={1,4,6};
    adj[4]={3};
    adj[5]={2,7};
    adj[6]={3,7};
    adj[7]={5,6};
    int src=1;
    if(isCycle(V,adj)){
        cout << " The cycle is present in the graph ";
    }
    else{
        cout << " The cycle is not present in the graph ";
    }
    return 0;
}