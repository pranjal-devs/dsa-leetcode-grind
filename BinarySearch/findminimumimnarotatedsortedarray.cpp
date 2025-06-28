#include<iostream>
#include<vector>
using namespace std;

int findminimum(vector<int>arr){
    int start=0;
    int end=arr.size()-1;
    int small=arr[0];
    while(start<=end){
        int mid=start+((end-start)/2);
        if(arr[mid]<small){
            small=arr[mid];;
        }
        // the condition to check left half sorted
        if(arr[start]<=arr[mid]){
            if(arr[start]<=small){
                small=arr[start];
            }
            start=mid+1;
        }
        // the condition to check right half sorted
        else{
            if(arr[mid]<small){
                small=arr[mid];
            }
            end=mid-1;
        }
    }
    return small;
}

int main(){
    vector<int>vec={3,4,5,1,2};
    int index = findminimum(vec);
    cout<<"The index of 0 is : " << index;
    return 0;
}