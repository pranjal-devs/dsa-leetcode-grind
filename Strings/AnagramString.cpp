#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class StringManipulator{
    private : 
        string str;
    public :
        StringManipulator(){}
        StringManipulator(string s){
            str=s;
        }
        string getString(){
            return str;
        }
        void setString(string newStr){
            str=newStr;
        }
        bool isAnagram(string s, string t){ // this function is good for the working but it is just the brute force approach of the code 
            // we will find a better or optimal code for the same
            int n=s.size();
            int m=t.size();
            if(n!=m){
                return false;
            }
            sort(s.begin(),s.end());
            sort(t.begin(),t.end());
            // for(int i=0;i<m;i++){
            //     if(s==t){
            //         return true;
            //     }
            // }
            // instead of this for loop we can directly use return s==t
            return s==t;
        }
        bool isAnagramOptimal(string s, string t){
            int n=s.size();
            int m=t.size();
            if(n!=m){
                return false;
            }
            vector<int>freqarrs(26,0);
            vector<int>freqarrt(26,0);
            for(int i=0;i<n;i++){
                freqarrt[t[i]-'a']++;
                freqarrs[s[i]-'a']++;
            }
            for(int i=0;i<26;i++){
                if(freqarrs[i]!=freqarrt[i]){
                    return false;
                }
            }
            return true;
        }
};
int main(){
    string s;
    cout <<"Enter the string s";
    cin >> s;
    string t;
    cout <<"Enter the string t";
    cin >> t;
    StringManipulator strObj;
    if(strObj.isAnagramOptimal(s,t)){
        cout <<"The string is an anagram string ";
    }
    else{
        cout <<"The string is not an anagram string ";
    }
    
    return 0;
}