#include<bits/stdc++.h>
using namespace std;
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int r = 0, l = 0, n = nums.size(), maxLen = 0, sum = 0;
        while(r<n){
            sum+=nums[r];
            while(l<=r && sum > goal){
                sum -= nums[l];
                l++;
            }
            maxLen+=r-l+1;
            r++;
        }
        return maxLen;
    }
int main(){
    vector<int>nums={1,0,1,0,1};
    int goal = 2;
    int ans = numSubarraysWithSum(nums,goal);
    cout << ans;
    return 0;
}
