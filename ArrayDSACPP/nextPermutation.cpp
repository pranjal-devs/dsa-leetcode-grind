#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

vector<int> nextPermutation(vector<int>nums){
    int n=nums.size();
    int index=-1;
    for(int i=n-2;i>=0;i--){
        if(nums[i]<nums[i+1]){
            index=i;
        }
    }
    if(index==-1){
        reverse(nums.begin(),nums.end());
        return nums;
    }
    for(int i=n-1;i>0;i--){
        if(nums[i]>nums[index]){
            swap(nums[i],nums[index]);
            break;
        }
    }
    reverse(nums.begin()+index+1,nums.end());
    return nums;
}

int main(){
    vector<int>vec={2,1,5,4,3,0,0};
    vec=nextPermutation(vec);
    for(int i=0;i<vec.size();i++){
        cout << vec[i] << " ";
    }
    return 0;
}