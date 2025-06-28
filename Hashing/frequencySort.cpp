#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<algorithm>
using namespace std;

string frequencySort(string s) {
    map<char,int>mpp;
    for(int i=0;i<s.size();i++){
        mpp[s[i]]++;
    }
    // put all the elements of the map to the vector using a pair vector
    vector<pair<int,char>>freqvec;
    for(auto &it : mpp){
        freqvec.push_back({it.second,it.first});
    }
    sort(freqvec.begin(),freqvec.end(),greater<pair<char,int>>());
    string result="";
    for(auto it : freqvec){
        result+=string(it.first,it.second);
    }
    return result;
}

int main(){
    string s="tree";
    string ans=frequencySort(s);
    cout << ans;
    return 0;
}