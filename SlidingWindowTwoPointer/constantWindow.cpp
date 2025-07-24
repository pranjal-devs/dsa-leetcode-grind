// we are given an array and a k we have to find the window of size k where the sum is the maximum

//[1,2,3,3,4,5,-1] k=4  output = 15

#include<bits/stdc++.h>
using namespace std;
int maximumSubarraySum(vector<int>&nums,int k){
    int left = 0;
    int right = k-1;
    int sum=nums[left]+nums[left+1]+nums[left+2]+nums[left+3];
    int maxSum=sum;
    while(right<nums.size()-1){
        sum-=nums[left];
        left++;
        right++;
        sum+=nums[right];
        maxSum=max(sum,maxSum);
    }
    return maxSum;
}
int main(){
    vector<int>nums={1,2,3,3,4,5,-1};
    int k = 4;
    int ans = maximumSubarraySum(nums,k);
    cout << ans;
}