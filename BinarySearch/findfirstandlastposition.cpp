#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
vector<int>searchRange(vector<int>nums,int target){
    int start=0;
    int end=nums.size()-1;
    vector<int>result;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(target==mid){
            result.push_back(mid);
        }
        else if(target>mid){
            start=mid+1;
        }
        else if(target<mid){
            end=mid-1;
        }
    } 
    return result;
}
int main(){
    vector<int>vec={5,7,7,8,8,10};
    vector<int>result=searchRange(vec,8);
    for(int i=0;i<result.size();i++){
        cout << result[i] <<" ";
    }
    return 0;
}