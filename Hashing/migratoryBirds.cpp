#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

int migratoryBirds(vector<int>nums){
    unordered_map<int,int>freqMap;
    int n=nums.size();
    for(int i=0;i<n;i++){
        freqMap[nums[i]]++;
    }
    int maxCount=0;
    int ans;
    for(auto it=freqMap.begin();it!=freqMap.end();++it){
        if(it->second>maxCount){
            maxCount=it->second;
            ans=it->first;
        }
        else{
            if(it->second==maxCount&&it->first<ans){
                ans=it->first;
            }
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    int ans=migratoryBirds(nums);
    cout << ans;
    return 0;
}