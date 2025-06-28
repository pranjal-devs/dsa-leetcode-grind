#include<bits/stdc++.h>
using namespace std;
int helper(int n,vector<int>&nums,vector<int>&dp){
    if(n<0) return 0;
    if(n==0) return nums[n];
    if(dp[n]!=-1) return dp[n];
    int pick = nums[n] + helper(n-2,nums,dp);
    int notpick = 0 + helper(n-1,nums,dp);
    return dp[n]=max(pick,notpick);
}
int rob(vector<int>nums){
    int n=nums.size();
    vector<int>dp(n,-1);
    return helper(n-1,nums,dp);
}
int main(){
    vector<int>nums={2,3,9,3,1};
    vector<int>dp(nums.size(),-1);
    cout << rob(nums);
    return 0;
}