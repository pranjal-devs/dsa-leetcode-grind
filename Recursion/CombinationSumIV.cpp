#include<bits/stdc++.h>
using namespace std;

void findCombinations(int ind, int target, vector<int>&candidates, vector<vector<int>>&ans,vector<int>&ds){
    if(target==0){
        ans.push_back(ds);
        return;
    }
    for(int i=ind;i<candidates.size();i++){
        if(candidates[i]==candidates[i-1]&&i>ind) continue;
        if(candidates[i]>target) break;
        ds.push_back(candidates[i]);
        findCombinations(i+1,target-candidates[i],candidates,ans,ds);
        ds.pop_back();
    }
}

vector<vector<int>>combinationSum(vector<int>candidates,int target){
    sort(candidates.begin(),candidates.end());
    vector<vector<int>>ans;
    vector<int>ds;
    findCombinations(0,target,candidates,ans,ds);
    return ans;
}

int main(){
    vector<int> candidates = {1,2,3};
    int target = 4;
    vector<vector<int>> ans = combinationSum(candidates, target);

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