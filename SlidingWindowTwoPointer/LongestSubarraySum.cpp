// Longest Subarray with sum<=k

#include<bits/stdc++.h>
using namespace std;

// This was the brute force approach

int LongestSubarray(vector<int>&nums, int k){
    int maxLen = 0;
    for(int i=0; i<nums.size(); i++){
        int sum=0;
        for(int j=i; j<nums.size(); j++){
            sum += nums[j];
            if(sum<=k) maxLen = max(maxLen,j-i+1);
            else if(sum>k) break; 
        }
    }
    return maxLen;
}

// The optimal one using the sliding window technique

int longestSubarray(vector<int>&nums, int k){
    int l = 0;
    int r = 0;
    int sum = 0;
    int maxLen = 0;
    int n = nums.size();
    while(r<n){
        sum += nums[r];
        if(sum<=k) maxLen = max(maxLen,r-l+1);
        while(sum>k){
            sum -= nums[l];
            l+=1;
        }
        r+=1;
    }
    return maxLen;
}

int main(){
    vector<int>nums={2,5,1,7,10};
    int k = 14;
    int ans = LongestSubarray(nums,k);
    vector<int>nums2={2,5,1,10,10};
    int ans2 = longestSubarray(nums2,k);
    cout << ans << endl << ans2 << endl;
    return 0;
}