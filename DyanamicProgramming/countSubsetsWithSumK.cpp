    #include<bits/stdc++.h>
    using namespace std;

    int helper(int index, int sum, vector<int>nums, vector<vector<int>>&dp){
        if (index == 0) {
            if (sum == 0 && nums[0] == 0) return 2;
            if (sum == 0) return 1;
            if (sum == nums[0]) return 1;
            return 0;
        }
        if(dp[index][sum]!=-1) return dp[index][sum];
        int pick = 0;
        int notpick = helper(index-1,sum,nums,dp);
        if(nums[index]<=sum){
            pick = helper(index-1,sum-nums[index],nums,dp);
        }
        return dp[index][sum] = pick + notpick;
    }

int main(){
    int n;
    cin >> n;
    vector<int>nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }
    int sum;
    cin >> sum;
    vector<vector<int>>dp(n,vector<int>(sum+1,-1));
    int ans = helper(n-1,sum,nums,dp);
    cout << ans;
    return 0;
}