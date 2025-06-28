#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int findMaxLength(vector<int>&nums){
    int maxVal = *(max_element(nums.begin(), nums.end()));
    vector<int> freqarr(maxVal + 1);
    for(int num : nums){
        freqarr[nums[num]]++;
    } 
    return freqarr.size();
}
int main(){
    vector<int>vec={0,1,1};
    int maxlength=findMaxLength(vec);
    cout << "The contigous length of the vector is : " << maxlength;
}