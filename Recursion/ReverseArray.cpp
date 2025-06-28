#include<bits/stdc++.h>
using namespace std;

void reverse(int i,vector<int>&arr){
    int n=arr.size();
    if(i>=n/2){
        return;
    }
    swap(arr[i],arr[n-i-1]);
    reverse(i+1,arr);
}

int main(){
    vector<int>arr={1,2,3,4,5,6,7,8};
    reverse(0,arr);
    for(auto it : arr){
        cout << it << " ";
    }
    return 0;
}