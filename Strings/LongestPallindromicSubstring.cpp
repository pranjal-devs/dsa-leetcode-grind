#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool isPallindrome(string s){
    int left=0;
    int n=s.size();
    int right=n-1;
    while(left<right){
        if(s[left]==s[right]){
            left++;
            right--;
        }
        else{
            return false;
        }
    }
    return true;
}

string bruteforcelongestPallindome(string s){  //TLE TIME LIMIT EXCEEDED because this is brute force code 
    int n = s.length();
    string output;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            string p=s.substr(i,j-i+1);
            if(isPallindrome(s.substr(i, j - i + 1))){
                if(p.size()>output.size()){
                    output=p;
                }
            }
        }
    }
    return output;
}

int expand(string &s,int left,int right){
    while(left>=0&&right<s.size()&&s[left]==s[right]){
        left++;
        right--;
    }
    return right-left-1;
}

string longestPallindome(string s){
    int start=0;
    int end=0;
    for(int i=0;i<s.size();i++){
        int len1=expand(s,i,i); // getting for the odd length pallindrome
        int len2=expand(s,i,i+1); // getting for the even length pallindrome
        int len=max(len1,len2);
        if(len>(end-start)){
            start=i-(len-1)/2;
            end=i+len/2;
        }
    }
    return s.substr(start,end-start+1);
}

int main(){
    string s="babad";
    string ans=longestPallindome(s);
    cout << ans;
}

