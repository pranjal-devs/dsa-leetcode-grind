#include<bits/stdc++.h>
using namespace std;

class Solution{
public : 
    int orangesRotting(vector<vector<int>>&grid){
        int n=grid.size(); // fetching the number of rows and column of the matrix
        int m=grid[0].size();
        int vis[n][m]; // creating a visited array later it will be initialised with 0
        queue<pair<pair<int,int>,int>>q;  // {{row,col},time}
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                } else{
                    vis[i][j]=0;
                }
            }
        }
        int tm=0;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            tm=max(tm,t);
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=r+delrow[i];
                int ncol=c+delcol[i];
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&grid[nrow][ncol]==1&&vis[nrow][ncol]==0){
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol]=2;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]!=2&&grid[i][j]==1){
                    return -1;
                }
            }
        }
        return tm;
    }
};

int main(){
    vector<vector<int>>grid={
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };
    Solution obj;
    int time = obj.orangesRotting(grid);
    cout<<"THe time required is : " << time <<" seconds";

    return 0;
}