#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;

int MaxOccuringElement(vector<int>nums){
    unordered_map<int,int>freqmap;
    for(int num : nums){
        freqmap[num]++;
    }
    int mostFreq=nums[0];
    int maxCount=0;
    for(auto it=freqmap.begin();it!=freqmap.end();++it){
        if(it->second>maxCount){
            maxCount=it->second;
            mostFreq=it->first;
        }
        else if(it->second==maxCount&&it->first<mostFreq){
            mostFreq=it->first;
        }
    }
    return mostFreq;

}

int main(){
    vector<int>nums={1,1,2,2,3,3};
    int ans=MaxOccuringElement(nums);
    cout<<ans;
    return 0;
}