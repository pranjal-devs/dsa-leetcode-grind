#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int n=nums.size();
    int maxSum=nums[0];
    int currSum=nums[0];
    for(int i=1;i<n;i++){
        currSum=max(nums[i],currSum+nums[i]);
        maxSum=max(currSum,maxSum);
    }
    return maxSum;
}

int main(){
    vector<int>nums={-2,1,-3,4,-1,2,1,-5,4};
    cout << "The maximum sum is : " << maxSubArray(nums);
    return 0;
}