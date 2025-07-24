// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]

#include<bits/stdc++.h>
using namespace std;

vector<int>topKFrequent(vector<int>&nums,int k){
    unordered_map<int,int>freqMap;
    int n = nums.size();
    for(auto it : nums){
        freqMap[it]++;
    }
    vector<pair<int,int>>freqPair;
    for(auto it=freqMap.begin(); it!=freqMap.end(); it++){
        freqPair.push_back({it->second,it->first});
    }
    sort(freqPair.rbegin(),freqPair.rend());
    vector<int>result;
    for(int i=0; i<k&&i<freqPair.size(); i++){
        result.push_back(freqPair[i].second);
    }
    return result;
}

int main(){
    vector<int>nums={1,1,1,2,2,3};
    vector<int>ans=topKFrequent(nums,2);
    for(auto it : ans){
        cout << it << " ";
    }
    return 0;
}