#include<iostream>
#include<vector>
using namespace std;

int search(vector<int>arr,int target){
    int start=0;
    int end=arr.size()-1;
    while(start<=end){
        int mid=start+((end-start)/2);
        if(arr[mid]==target){
            return mid;
        }
        // the condition to check left half sorted
        if(arr[start]<=arr[mid]){
            if(arr[start]<=target&&arr[mid]>=target){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        // the condition to check right half sorted
        else{
            if(arr[mid]<=target&&arr[end]>=target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }

        }
    }
    return -1;
}

int main(){
    vector<int>vec={4,5,6,7,0,1,2};
    int index = search(vec,0);
    cout<<"The index of 0 is : " << index;
    return 0;
}