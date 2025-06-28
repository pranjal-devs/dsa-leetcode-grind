#include<iostream>
using namespace std;
#include<numeric>
#include<cmath>
#include <climits>
#include<vector>
#include<algorithm>
int threeSumClosest(vector<int>& nums, int target) {
    int n=nums.size();
    sort(nums.begin(),nums.end());
    int closestSum=INT_MAX;
    for(int i=0;i<n;i++){
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int j=i+1;
        int k=n-1;
        int sum=nums[i]+nums[j]+nums[k];
        if(abs(sum-target)<abs(closestSum-target)){
            closestSum=sum;
        }
        else if(sum>target){
            j++;
        }
        else if(sum<target){
            k--;
        }
        else{
            return sum;
        }
    }
    return closestSum;
}
int main(){
    vector<int>nums={-1,2,1,-4};
    int ans=threeSumClosest(nums,1);
    cout<<"The closest sum is : " << ans;
    return 0;
}