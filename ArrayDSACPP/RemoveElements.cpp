#include<bits/stdc++.h>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    int j = 0;
    vector<int>ans;
    while(j<nums.size()){
        if(nums[j]==val){
            j++;
        }else{
            ans.push_back(nums[j]);
            j++;
        }
    }
    for(auto it : ans){
        cout << it << " ";
    }
    cout << endl;
    return ans.size();
}

int main(){
    vector<int>nums = {3,2,2,3};
    int op = removeElement(nums,3);
    cout << op << endl;
}