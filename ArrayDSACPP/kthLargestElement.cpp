#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void findKthLargest(vector<int>& nums, int k){
    sort(nums.begin(),nums.end());
    int n=nums.size();
    cout<<nums[n-k];
}

int main(){
    vector<int>nums={3,2,3,1,2,4,5,5,6};
    findKthLargest(nums,4);
    return 0;
}