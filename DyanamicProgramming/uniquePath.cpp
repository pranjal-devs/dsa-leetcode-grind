#include<bits/stdc++.h>
using namespace std;

int recur(int m, int n, vector<vector<int>>&dp){
    if(m==0 && n==0) return 1;
    if(m<0 || n<0) return 0;
    if(dp[m][n]!=-1) return dp[m][n];
    int up = recur(m-1,n,dp);
    int left = recur(m,n-1,dp);
    return up + left;
}

int main(){
    int m = 3, n = 7;
    vector<vector<int>>dp(m,vector<int>(n,-1));
    int ans = recur(m-1,n-1,dp);
    cout << ans;
    return 0;
}