#include<map>
#include<unordered_map>
#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    char arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    map<char,int>mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }
    int q;
    cin >> q;
    while(q--){
        char number;
        cin >> number;
        cout << mpp[number] << endl;
    }

    return 0;
}