#include<bits/stdc++.h>
using namespace std;

// making a recursive function in order to get the highest value
int recur(int index, int W, vector<int>&weights, vector<int>&values, vector<vector<int>>&dp){
    if(index == 0){
        if(weights[0]<=W) return values[0];
        else return 0;
    }
    if(dp[index][W]!=-1) return dp[index][W];
    int notPick = recur(index-1, W, weights, values, dp);
    int pick = 0;
    if(weights[index]<=W){
        pick = values[index]+recur(index-1,W-weights[index],weights,values,dp);
    }
    return dp[index][W]=max(pick,notPick);
}

void findSelectedItems(int n, int W, vector<int>&weights, vector<int>&values, vector<vector<int>>&dp){
    int i=n-1;
    vector<int>selectedWeights;
    vector<int>selectedValues;
    while(i>0){
        if(dp[i][W]==dp[i-1][W]){
            i--; 
        }
        else {
            selectedValues.push_back(values[i]);
            selectedWeights.push_back(weights[i]);
            W-=weights[i];
            i--;
        }
    }
    if(i==0 && weights[0] <= W){
        selectedValues.push_back(values[0]);
        selectedWeights.push_back(weights[0]);
    }
    reverse(selectedValues.begin(),selectedValues.end());
    reverse(selectedWeights.begin(),selectedWeights.end());
    for(int wt : selectedValues){
        cout << wt << " ";
    }
    for(int wt : selectedWeights){
        cout << wt << " ";
    }
    cout << endl;
}

int main(){
    int n;
    cin >> n;
    vector<int>weights(n);
    vector<int>values(n);
    for(int i=0; i<n; i++) cin >> weights[i];
    for(int i=0; i<n; i++) cin >> values[i];
    int W;
    cin >> W;
    vector<vector<int>>dp(n,vector<int>(W+1,-1));
    int ans= recur(n-1,W,weights,values,dp);
    cout << ans;
    cout << endl;
    findSelectedItems(n,W,weights,values,dp);
    return 0;
}