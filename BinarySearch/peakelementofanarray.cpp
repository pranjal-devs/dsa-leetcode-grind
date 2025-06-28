#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
int findPeakElement(vector<int>nums){
    int start=0;
    int end=nums.size()-1;
    while(start<end){
        int mid=start+(end-start)/2;
        if(nums[mid]<nums[mid+1]){
            start=mid+1;
        }
        else{
            end=mid;
        }
    }
    return start;
}  
int main(){
    vector <int> vec={1,2,3,1};
    int peak=findPeakElement(vec);
    cout <<"The peak element of the array is : " << peak << endl;
}