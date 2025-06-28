#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
#include<algorithm>

vector<int>topKFrequent(vector<int>nums,int k){
    unordered_map<int,int>freqMap; // the first stores the element and the second stores the frequency
    for(int i=0;i<nums.size();i++){
        freqMap[nums[i]]++;
    }
    vector<pair<int,int>>freqVec;
    for(auto it=freqMap.begin();it!=freqMap.end();it++){
        freqVec.push_back({it->second,it->first});
    }
    sort(freqVec.rbegin(),freqVec.rend());
    vector<int>result;
    for(int i=0;i<k&&i<freqVec.size();i++){
        result.push_back(freqVec[i].second);
    }
    return result;
}

int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    int k;
    cin >>k;
    vector<int>ans=topKFrequent(nums,k);
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        cout << ans[i] <<" ";
    }
    return 0;
}