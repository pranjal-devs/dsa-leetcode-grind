#include<iostream> 
using namespace std;
#include<vector>

int findMaxConsecutiveOnes(vector<int>arr){
    int max=0;
    int count=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==1){
            count++;
        }
        if(arr[i]==0){
            if(count>max) max=count;
            count=0;
        }
    }
    if(count>max) max=count; // this is the case for the last if the largest sequence is in the last 
    return max;
}

int main(){
    vector<int>vec1={1,1,0,1,1,1};
    int max=findMaxConsecutiveOnes(vec1);
    cout <<"The maximum number of consecutive ones are : " << max << endl;   
}