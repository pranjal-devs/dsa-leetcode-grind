#include<bits/stdc++.h>
using namespace std;

void recur(vector<int>&ds, vector<vector<int>>&ans, vector<int>&freq, vector<int>&nums){
    if(ds.size()==nums.size()){
        ans.push_back(ds);
        return;
    }
    for(int i=0;i<nums.size();i++){
        if(freq[i]) continue;
        if(i>0 && nums[i]==nums[i-1] && !freq[i-1]) continue;
        freq[i]=1;
        ds.push_back(nums[i]);
        recur(ds, ans, freq, nums);
        freq[i]=0;
        ds.pop_back();
    }
}

vector<vector<int>>permute(vector<int>&nums){
    vector<vector<int>>ans;
    vector<int>ds;
    vector<int>freq(nums.size(),0);
    recur(ds,ans,freq,nums);
    return ans;
}

int main(){
    vector<int>nums={1,1,2};
    vector<vector<int>>ans=permute(nums);
    for(auto it : ans){
        for(auto r : it){
            cout << r << " ";
        }
        cout << endl;
    }
    return 0;
}