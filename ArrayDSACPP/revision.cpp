#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// find three indexes whose sum equals to zero

vector<vector<int>>threeSum(vector<int>nums){
    int n=nums.size();
    sort(nums.begin(),nums.end());
    vector<vector<int>>result;
    for(int i=0;i<n;i++){
        int j=i+1;
        int k=n-1;
        if(i>0&&nums[i]==nums[i-1]) continue;
        while(j<k){
            int sum=nums[i]+nums[j]+nums[k];
            if(sum==0){
                vector<int>temp;
                temp.push_back(nums[i]);
                temp.push_back(nums[j]);
                temp.push_back(nums[k]);
                result.push_back(temp);
                j++;
                k--;
                while(j<k&&nums[j]==nums[j-1]) continue;
                while(j<k&&nums[k]==nums[k-1]) continue;
            }
            else if(sum>0){
                k--;
            }
            else{
                j++;
            }
        }
    }
    return result;
}


int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    sort(nums.begin(), nums.end());
    vector<vector<int>> result = threeSum(nums);
    cout << "Triplets that sum to zero:" << endl;
    for (const auto& triplet : result) {
        cout << "[";
        for (int i = 0; i < triplet.size(); i++) {
            cout << triplet[i];
            if (i != triplet.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
    return 0;
}
