#include<bits/stdc++.h>
using namespace std;
int recur(int index1, int index2, string &text1, string &text2, vector<vector<int>>&dp){
    if(index1<0 || index2<0) return 0;
    if(dp[index1][index2]!=-1) return dp[index1][index2];
    if(text1[index1]==text2[index2]) return dp[index1][index2] = 1+recur(index1-1,index2-1,text1,text2,dp);
    return dp[index1][index2] = max(recur(index1-1,index2,text1,text2,dp),recur(index1,index2-1,text1,text2,dp));
}
void printLCS(string &text1, string &text2, vector<vector<int>>&dp){
    string lcs = "";
    int i=text1.size()-1;
    int j=text2.size()-1;  
    while(i>=0 && j>=0){
        if(text1[i]==text2[j]){
            lcs.push_back(text1[i]);
            i--;
            j--;
        }
        else if(dp[i][j]==dp[i-1][j]){
            i--;
        }else{
            j--;
        }
    }
    reverse(lcs.begin(),lcs.end());
    cout << lcs;
}
int main(){
    string text1;
    string text2;
    cin >> text1;
    cin >> text2;
    int index1=text1.size();
    int index2=text2.size();
    vector<vector<int>>dp(index1,vector<int>(index2,-1));
    int ans = recur(index1-1,index2-1,text1,text2,dp);
    cout << ans << endl;
    printLCS(text1,text2,dp);
    cout << endl;
    return 0;
}