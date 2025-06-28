#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    int len1=nums1.size();
    int len2=nums2.size();
    int i=0;
    int j=0;
    vector<int>result;
    while(i<len1&&j<len2){
        if(nums1[i]==nums2[j]){
            result.push_back(nums1[i]);
            i++;
            j++;
        }
        else{
            i++;
            j++;
        }
    }
    return result;
}

int main(){
    vector<int>vec1={1,2,2,1};
    vector<int>vec2={2,2};
    vector<int>result = intersect(vec1,vec2);
    for(int i=0;i<result.size();i++){
        cout << result[i] << " ";
    }
    return 0;
}