#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
int maxfrequencyelements(vector<int>&nums){
    int maxVal = *(max_element(nums.begin(), nums.end()));
    vector<int> freqarr(maxVal + 1); 
    for(int i=0;i<nums.size();i++){
        freqarr[nums[i]]++;
    }   // this is the code for the frequncy array 
    int maxfreq=*max_element(freqarr.begin(),freqarr.end());
    int count=0;
    for(int i=0;i<freqarr.size();i++){
        if(maxfreq==freqarr[i]){
            count+=freqarr[i];
        }
    }
    return count;
}
void displayVector(const vector<int>& vec){
    for(auto it=vec.begin();it!=vec.end();++it){
        cout<<*it<<"\t"; 
    }
    cout<<endl;
}
int main(){
    vector<int>vec1={1,2,3,4,5};
    displayVector(vec1);
    int count=maxfrequencyelements(vec1);
    cout <<"The highest frequency elements are : " << count << endl;
    return 0;
}