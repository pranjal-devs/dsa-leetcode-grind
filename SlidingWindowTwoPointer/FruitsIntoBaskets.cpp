#include<bits/stdc++.h>
using namespace std;

int totalFruits(vector<int>&nums){
    int n = nums.size(), l=0, r=0, maxLen=0;
    unordered_map<int,int>mpp; // map to store the <value,frequency>
    while(r<n){
        mpp[nums[r]]++;
        if(mpp.size()>2){
            while(mpp.size()>2){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0) mpp.erase(nums[l]);
                l++;
            }
        }
        if(mpp.size()<=2){
            maxLen = max(maxLen, r-l+1);
        }
        r++;
    }
    return maxLen;
}

int main(){
    vector<int>nums={1,2,3,2,2};
    int ans = totalFruits(nums);
    cout << ans;
    return 0;
}