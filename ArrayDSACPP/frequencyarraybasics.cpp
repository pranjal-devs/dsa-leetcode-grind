#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
vector<int>frequencyarray(vector<int>&arr){
    int maxVal = *(max_element(arr.begin(), arr.end()));
    vector<int> freqarr(maxVal + 1); 
    for(int i=0;i<arr.size();i++){
        freqarr[arr[i]]++;
    }
    return freqarr;
}
void displayVector(const vector<int>& vec){
    for(auto it=vec.begin();it!=vec.end();++it){
        cout<<*it<<"\t"; 
    }
    cout<<endl;
}
int main(){
    vector<int>vec1={2,4,1,2,3,2};
    displayVector(vec1);
    vector<int>freqarr=frequencyarray(vec1);
    displayVector(freqarr);
    return 0;
}