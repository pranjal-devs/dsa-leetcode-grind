#include<bits/stdc++.h>
using namespace std;

void thirdMax(vector<int>& nums) {
    unordered_map<int,int>mpp;
    for(auto it : nums){
        mpp[it]++;
    }
    vector<int>final;
    for(auto it : mpp){
        final.push_back(it.first);
    }
    sort(final.begin(),final.end());
    for(auto it : final){
        cout << it << " ";
    }
    cout << endl;
    int ans = final.size()-3;
    cout << ans;
}

int main(){
    vector<int>nums={2,2,3,1};
    thirdMax(nums);
    cout << endl;
    return 0;
}