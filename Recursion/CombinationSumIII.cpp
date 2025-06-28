#include<bits/stdc++.h>
using namespace std;

void findCombinations(int start, int k, int n, vector<vector<int>>&ans,vector<int>&ds){
    if(ds.size()==k){
        if(n==0){
            ans.push_back(ds);
        }
        return;
    }
    for(int i=start;i<9;i++){
        if(i>n) break;
        ds.push_back(i);
        findCombinations(i+1,k,n-i,ans,ds);
        ds.pop_back();
    }
}

vector<vector<int>>combinationSum(int k,int n){
    vector<vector<int>>ans;
    vector<int>ds;
    findCombinations(1,k,n,ans,ds);
    return ans;
}

int main(){
    int k=3;
    int n=7;
    vector<vector<int>> ans = combinationSum(k,n);

    // Print the result
    cout << "[\n";
    for (const auto& row : ans) {
        cout << "  [ ";
        for (int num : row) {
            cout << num << " ";
        }
        cout << "]\n";
    }
    cout << "]\n";

    return 0;
}