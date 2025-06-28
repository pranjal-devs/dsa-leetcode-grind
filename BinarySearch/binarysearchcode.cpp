#include<iostream>
#include<vector>
using namespace std;

int BinarySearch(vector<int>&nums,int k){
    int n=nums.size()-1;
    int start=0;
    int end=n;
    while(start<=end){
        cout << "Currently the range of the binary seaerch is : " << start <<"<-->" << end <<endl;
        int mid=start+(end-start)/2;
        if(k==nums[mid]){
            return mid;
        }
        if(k<nums[mid]){
            end=mid-1;
        }
        else if(k>nums[mid]){
            start=mid+1;
        }
    }
    return -1;
}
int main(){
    vector<int>vec={1,2,3,5,7,11,15,19,45};
    int index = BinarySearch(vec,5);
    cout<<"The index of 5 is : " << index;
    return 0;
}