#include<bits/stdc++.h>
using namespace std;
vector<string>topKFrequent(vector<string>words, int k){
    unordered_map<string,int>freqMap;
    for(auto it : words){
        freqMap[it]++;
    }
    vector<pair<int,string>>freqPair;
    for(auto it=freqMap.begin(); it!=freqMap.end(); it++){
        freqPair.push_back({it->second,it->first});
    }
    // this is the main step of sorting the freqPair array in the lexicographical order 
    sort(freqPair.begin(), freqPair.end(), [](pair<int,string>&a,pair<int,string>&b){
        if(a.first==b.first) return a.second < b.second; // lexicographically similar
        return a.first > b.first; // higher frequency first
    });
    vector<string>result;
    for(int i=0; i<freqPair.size()&&i<k; i++){
        result.push_back(freqPair[i].second);
    }
    return result;
}
int main(){
    vector<string>words={"i","love","leetcode","i","love","coding"};
    vector<string>ans=topKFrequent(words,2);
    for(auto it : ans){
        cout << it << " ";
    }
    return 0;
}