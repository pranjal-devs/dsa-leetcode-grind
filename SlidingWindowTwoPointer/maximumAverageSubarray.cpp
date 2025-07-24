#include<bits/stdc++.h>
using namespace std;

    double findMaxAverage(vector<int>& nums, int k) {
        int left = 0;
        int right = k-1;
        double sum=0;
        for(int i=0; i<k&&i<nums.size(); i++){
            sum+=nums[i];
        }
        double maxSum=sum;
        while(right<nums.size()-1){
            sum-=nums[left];
            left++;
            right++;
            sum+=nums[right];
            maxSum=max(sum,maxSum);
        }
        return maxSum/k;
    }

int main(){
    vector<int>nums={1,12,-5,-6,50,3};
    int k = 4;
    double ans = findMaxAverage(nums,k);
    cout << ans;
}