#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>

using namespace std;

void displayFrequency(string nums){
    map<char,int>freqMap;
    int n=nums.size();
    for(int i=0;i<n;i++){
        freqMap[nums[i]]++;
    }
    for(auto it=freqMap.begin();it!=freqMap.end();it++){
        cout << it->first << " - " << it->second << endl;
    }
}
    
int main(){
    string str;
    cin >> str;
    displayFrequency(str);
    return 0;
}