#include<bits/stdc++.h>
using namespace std;

int bfs(int row,int col,vector<vector<int>>&vis,vector<vector<int>>&grid){
    vis[row][col]=1;
    queue<pair<int,int>>q;
    q.push({row,col});
    int n=grid.size();
    int m=grid[0].size();
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};
    int count=1;
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                grid[nrow][ncol] == 1 && !vis[nrow][ncol]) {
                vis[nrow][ncol] = 1;
                q.push({nrow, ncol});
                count++;
            }
        }
    }
    return count;
}
int maxAreaOfIsland(vector<vector<int>>&grid){
    int n=grid.size(); // to get the size of the rows
    int m=grid[0].size(); // to get the size of the cols
    vector<vector<int>>vis(n,vector<int>(m,0)); // created a matrix of size cols    initialised to 0 which is visited array
    int maxArea=0;
    for(int row=0;row<n;row++){
        for(int col=0;col<m;col++){
            if(!vis[row][col]&&grid[row][col]==1){
                int area=bfs(row,col,vis,grid);
                maxArea=max(area,maxArea);
            }
        }
    }
    return maxArea;
}

int main(){
    vector<vector<int>> isConnected = {
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,1,1,0,1,0,0,0,0,0,0,0},
        {0,0,1,0,0,1,1,0,0,0,0,0,0},
        {0,0,1,0,0,1,1,0,0,1,0,1,0},
        {0,0,0,0,0,0,0,0,0,1,1,1,0},
        {0,0,0,0,0,0,0,0,0,0,0,1,0},
        {0,0,0,0,0,0,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,1,1,0,0,0}
    };
    int isle = maxAreaOfIsland(isConnected);
    cout << "Maximum area of the island : " << isle << endl;
    return 0;
}