#include<bits/stdc++.h>
using namespace std;

int longestSubstring(string s){
    int l = 0, r = 0, cnt = 0, n = s.size();
    unordered_map<char,int>mpp;
    while(r<n){
        mpp[s[r]]++;
        while(mpp.size()==3){
            cnt+=n-r;
            mpp[s[l]]--;
            if(mpp[s[l]]==0) mpp.erase(s[l]);
            l++;
        }
        r++;
    }
    return cnt;
}

int main(){
    string s = "bbacba";
    int ans = longestSubstring(s);
    cout << ans;
    return 0;
}