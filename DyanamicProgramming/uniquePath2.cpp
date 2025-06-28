#include<bits/stdc++.h>
using namespace std;

int recur(int m, int n, vector<vector<int>>&obstacleGrid, vector<vector<int>>&dp){
    if(m==0 && n==0) return 1;
    if(m<0 || n<0) return 0;
    if(dp[m][n]!=-1) return dp[m][n];
    if(obstacleGrid[m][n]==1) return 0;
    int up = recur(m-1, n, obstacleGrid, dp);
    int left = recur(m, n-1, obstacleGrid, dp);
    return up+left;
}

int uniquePathWithObstacle(vector<vector<int>>&obstacleGrid){
    int m=obstacleGrid.size();
    int n=obstacleGrid[0].size();
    vector<vector<int>>dp(m,vector<int>(n,-1));
    if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1) return 0; // if the first or the last element is 0 then return 0;
    int ans = recur(m-1,n-1,obstacleGrid,dp);
    return ans;
}

int main(){
    vector<vector<int>>obstacleGrid={
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };
    int ans = uniquePathWithObstacle(obstacleGrid);
    cout << ans;
    return 0;
}