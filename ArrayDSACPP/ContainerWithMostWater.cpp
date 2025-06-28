#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int maxArea(vector<int>& height) {
    int n=height.size();
    int i=0;
    int j=n-1;
    int area=0;
    while(i<j){
        int currentArea=min(height[i],height[j])*(j-i);
        area=max(currentArea,area);
        if(height[i]<height[j]){
            i++;
        }
        else{
            j--;
        }
    }
    return area;
}

int main(){
    vector<int>vec={1,8,6,2,5,4,8,3,7};
    int ans=maxArea(vec);
    cout<<ans;
    return 0;
}