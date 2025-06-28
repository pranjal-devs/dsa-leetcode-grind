#include<iostream>
using namespace std;
#include<vector>
void merge(vector<int>arr,int start,int mid, int end){
    vector<int>temp;
    int i=start,j=end;
    while(i<=mid&&j<=end){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        } else{
            temp.push_back(arr[j]);
            j++;
        }
        while(i<=mid){
            temp.push_back(arr[i]);
            i++;
        }
        while(j<=end){
            temp.push_back(arr[j]);
            j++;
        }
        for(int idx=0;idx<temp.size();idx++){
            arr[start+idx]=temp[idx];
        }
    }
}
void mergeSort(vector<int>arr,int start,int end){
    if(start<end){
        int mid=start+(end-start)/2;
        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }
}

void sortanarray(vector<int>vec){
    mergeSort(vec, 0, vec.size() - 1);
}

int main(){
    return 0;
}