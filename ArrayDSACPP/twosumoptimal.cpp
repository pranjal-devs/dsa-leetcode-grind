#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

vector<int>twoSum(vector<int>arr,int target){
    vector<int>result;
    sort(arr.begin(),arr.end());
    int n=arr.size();
    int left=0;
    int right=n-1;
    while(left<right){
        int sum=arr[left]+arr[right];
        if(sum==target){
            result.push_back(arr[left]);
            result.push_back(arr[right]);
            break;
        }
        if(sum>target){
            left++;
        }
        else{
            right--;
        }
        
    }
    return result;
}

int main() {
    vector<int> arr = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(arr, target);
    
    if (!result.empty()) {
        cout << "The two numbers that add up to " << target << " are: "
             << result[0] << " and " << result[1] << endl;
    } else {
        cout << "No solution found!" << endl;
    }

    return 0;
}