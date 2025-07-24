#include<bits/stdc++.h>
using namespace std;
int maxConsecutiveOnes(vector<int>&nums, int k){
    int r = 0, l = 0;
    int maxLen = 0, zero = 0;
    int n = nums.size();
    while(r<n){
        if(nums[r]==0) zero++;
        while(zero>k){
            if(nums[l]==0) zero--;
            l++;
        }
        maxLen = max(maxLen, r-l+1);
        r++;
    }
    return maxLen;
}
int main(){
    vector<int>nums={1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    int ans = maxConsecutiveOnes(nums,k);
    cout << ans;
    return 0;
}