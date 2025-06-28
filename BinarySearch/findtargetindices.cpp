#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
vector<int>targetIndices(vector<int>arr,int target){
    sort(arr.begin(),arr.end());
    vector<int>result;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==target){
            result.push_back(i);
        }
    }
    return result;
}
int main(){
    vector<int>vec={1,2,5,2,3};
    vector<int>result=targetIndices(vec,2);
    for(int i=0;i<result.size();i++){
        cout << result[i] << " ";
    }
    return 0;
}