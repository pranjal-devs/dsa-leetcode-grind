// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]

#include<bits/stdc++.h>
using namespace std;

void findCombination(int ind, int target, vector<int>&candidates, vector<vector<int>>&ans, vector<int>&ds){
    if(ind==candidates.size()){
        if(target==0){
            ans.push_back(ds);
        }
        return;
    }
    if(target>=candidates[ind]){
        ds.push_back(candidates[ind]);
        findCombination(ind,target-candidates[ind],candidates,ans,ds);
        ds.pop_back();
    }
    findCombination(ind+1,target,candidates,ans,ds);
}

vector<vector<int>>combinationSum(vector<int>&candidates,int target){
    vector<vector<int>>ans;
    vector<int>ds;
    findCombination(0,target,candidates,ans,ds);
    return ans;
}

int main(){
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
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