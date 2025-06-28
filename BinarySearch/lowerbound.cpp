#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
int lowerbound(vector<int>arr,int target){
    // we should be given a sorted array to perform this
    int n=arr.size();
    int hi=n-1;
    int lo=0;
    int ans=n; //initialising ans with an unidentified index which is the size of the array
    while(lo<=hi){
        int mid=lo+((hi-lo)/2);
        if(arr[mid]>=target){
            ans=arr[mid];
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }
    return ans;
}
int main(){
    vector <int> vec={1,2,3,3,7,8,8,12,11};
    int lb=lowerbound(vec,9);
    cout<<lb;
    return 0;
}