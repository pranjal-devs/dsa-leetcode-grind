#include<iostream>
#include<algorithm>
using namespace std;
#include<vector>
int BinarySearch(vector<int>arr,int k){
    int start=0;
    int end=arr.size()-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==k){
            return mid;
        }
        if(k>arr[mid]){
            start=mid+1;
        }
        if(k<arr[mid]){
            end=mid-1;
        }
    }
    return -1;
}
bool twosum(vector<int>arr,int k){
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size();i++){
        int target=k-arr[i];
        if(BinarySearch(arr,target)!=-1){
            return true;
        }  
    }
    return false;
}
int main(){
    vector<int>vec={-1,1,2,3,5,8};
    if(twosum(vec,100)){
        cout << "True";
    }
    else{
        cout <<"False";
    }
    return 0;
}