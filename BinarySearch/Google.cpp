#include<bits/stdc++.h>
using namespace std;
int singleNonDuplicate(vector<int>& nums) {
    int s = 0;
    int e = nums.size()-1;
    int mid = s + ( e - s ) / 2 ;
    while(s<e){
        if(mid%2==0){
            if(nums[mid]==nums[mid-1]) e = mid - 1;
            else s = mid + 1;
        }
        else{
            if(nums[mid]==nums[mid-1]) s = mid + 1;
            else e = mid - 1;
        }
    }
    return s;
}
int main(){
    vector<int>nums = {1,1,2,3,3,4,4,8,8};
    cout << singleNonDuplicate(nums);
}