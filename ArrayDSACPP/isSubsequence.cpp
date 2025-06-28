#include<bits/stdc++.h>
using namespace std;

bool isSubsequence(string s, string t){
    if(s.empty()) return false;
    int start=0;
    int n=t.size();
    for(int i=0;i<n;i++){
        if(s[start]==t[i]){
            start++;
        }
    }
    if(start<s.size()-1) return false;
    return true;
}

int main(){
    string s="abc";
    string t="ahbgdc";
    if(isSubsequence(s,t)){
        cout << "Yes";
    }else{
        cout <<"NO";
    }
    return 0;
}