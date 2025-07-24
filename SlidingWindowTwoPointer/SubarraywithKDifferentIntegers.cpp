#include<bits/stdc++.h>
using namespace std;
int subarraysWithKDistinct(vector<int>& nums, int k) {
    unordered_map<int,int>mpp;
    int count = 0;
    for(int i=0; i<nums.size(); i++){
        mpp.clear();
        for(int j=i; j<nums.size(); j++){
            mpp[nums[j]]++;
            if(mpp.size()==k) count++;
            else if(mpp.size()>k) break;
        }
    }
    return count;
}
int main(){
    vector<int>nums={1,2,1,2,3};
    int k = 2;
    int ans = subarraysWithKDistinct(nums,k);
    cout << ans;
    return 0;
}