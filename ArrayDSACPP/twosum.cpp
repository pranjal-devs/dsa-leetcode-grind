#include<iostream>
using namespace std;
#include<vector>

vector<int>twoSum(vector<int>arr,int target){
    vector<int>result;
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if(arr[i]+arr[j]==target){
                result.push_back(i);
                result.push_back(j);
            }
        }
    }
    return result;
}

void printvector(vector<int>vec){
    for(int i=0;i<vec.size();i++){
        cout << vec[i] << " ";
    }
    cout << endl;
}
int main(){
    vector<int>vec1={2,7,11,15};
    vector<int>result=twoSum(vec1,9);
    printvector(result);   
}