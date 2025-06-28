#include<bits/stdc++.h>
using namespace std;
int recur(int index, int sum, vector<int>&coins, vector<vector<int>>&dp){
    if(index==0){
        if(sum%coins[index]==0) return 1;
        else return 0;
    }
    if(dp[index][sum]!=-1) return dp[index][sum];
    int pick = 0;
    int notpick = recur(index-1, sum, coins, dp);
    if(coins[index]<=sum){
        pick = recur(index, sum-coins[index], coins, dp);
    }
    return dp[index][sum] = pick+notpick;
}
int main(){
    int n;
    cin >> n;
    vector<int>coins(n);
    for(int i=0; i<n; i++) cin >> coins[i];
    int sum;
    cin >> sum;
    vector<vector<int>>dp(n,vector<int>(sum+1,-1));
    int ans = recur(n-1, sum, coins, dp);
    cout << ans;
    return 0;
}