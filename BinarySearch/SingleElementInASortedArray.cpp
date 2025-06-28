#include<iostream>
#include<vector>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int n=nums.size();
    int start=0;
    int end=n-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(mid%2==0){ // this is the condition for the even index of the middle element
            if(nums[mid]==nums[mid+1]){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        else{
            if(nums[mid]==nums[mid-1]){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
    }
    return nums[start];
}

int main(){
    vector<int>vec={1,1,2,3,3,4,4,5,5};
    int index = singleNonDuplicate(vec);
    cout<<"The index is : " << index;
    return 0;
}