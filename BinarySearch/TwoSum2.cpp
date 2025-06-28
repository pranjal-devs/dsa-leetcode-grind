#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int>result;
    int start=0;
    int size=numbers.size();
    int end=size-1;
    while(start<=end){
        int sum=numbers[start]+numbers[end];
        if(sum==target){
            result.push_back(start+1);
            result.push_back(end+1);
            return result;
        }
        else if(sum>target){
            end--;
        }
        else{
            start++;
        }
    }
    return result;
}

int main(){
    vector<int>vec={2,7,11,15};
    vector<int>result;
    result=twoSum(vec,9);
    for(int i=0;i<result.size();i++){
        cout <<result[i] <<" ";
    }
    return 0;
}