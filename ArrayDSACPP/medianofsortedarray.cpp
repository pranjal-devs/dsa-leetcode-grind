#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

float findMedianSortedArrays(vector<int>nums1,vector<int>nums2){
    vector<int>nums3;
    nums3.insert(nums3.end(),nums1.begin(),nums1.end());
    nums3.insert(nums3.end(),nums2.begin(),nums2.end());
    sort(nums3.begin(),nums3.end());
    int n=nums3.size();
    int mid=n/2;
    if (n%2==0){
        return(nums3[mid-1]+nums3[mid])/2.0;
    } else{
        return nums3[mid];
    }
}
int main(){
    vector<int>vec1={1,2};
    vector<int>vec2={3,4};
    float ans=findMedianSortedArrays(vec1,vec2);
    cout<<"The median of the sorted arrays is : " << ans << endl;
}