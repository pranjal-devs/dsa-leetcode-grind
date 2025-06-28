#include<iostream>
using namespace std;
#include<vector>
int middleindex(vector<int>nums){
    int size=nums.size();
    if(size==0){
        return 0;
    }
    int leftsum=0;
    int rightsum=0;
    for(auto num : nums){
        rightsum+=num;
    }
    for(int i=0;i<size;++i){
        rightsum-=nums[i];
        if(leftsum==rightsum){
            return i;
        }   
        leftsum+=nums[i];
    }
    return -1;
}
int main(){
    vector<int>vec={2,3,-1,8,4};
    int middle=middleindex(vec);
    cout <<"The middle index of the vector is : " << middle << endl;
    return 0;
}