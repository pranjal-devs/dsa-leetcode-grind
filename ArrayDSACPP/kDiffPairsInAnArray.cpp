#include<iostream>
#include<vector>
using namespace std;

int findPairs(vector<int>& nums, int k) {
    int n=nums.size();
    int i=0;
    int j=1;
    int pair=0;
    while(i<n&&j<n){
        int diff=nums[j]-nums[i];
        if(diff==k){
            pair++;
        }
    }
}

int main(){
    vector<int>vec={3,5,4,1,1};
    cout << findPairs(vec,2); // expected 2
    return 0;
}