#include<bits/stdc++.h>
using namespace std;

int recur(int index, int target, vector<int>&nums, vector<vector<int>>&dp){
    if(index == 0){
        return target==nums[0];
    }
    if(dp[index][target]!=-1) return dp[index][target];
    if(target == 0) return 1;
    int pick = 0;
    int notpick = recur(index-1,target,nums,dp);
    if(nums[index]<=target){
        pick = recur(index-1,target-nums[index],nums,dp);
    }
    return dp[index][target] = pick || notpick;
}

int main(){
    int n;
    cin >> n;
    vector<int>nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];
    int total = accumulate(nums.begin(),nums.end(),0);
    if(total%2!=0) return 0;
    int target = total/2;
    vector<vector<int>>dp(n,vector<int>(target+1,-1));
    if(recur(n-1,target,nums,dp)) cout << "Yes";
    else cout << "No";
    return 0;
}