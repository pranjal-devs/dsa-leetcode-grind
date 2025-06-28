#include<bits/stdc++.h>
using namespace std;

bool checkPallindrome(int i,string &arr){
    int n=arr.size();
    if(i>=n/2) return true;
    if(arr[i]!=arr[n-i-1]) return false;
    return checkPallindrome(i+1,arr);
}

int main(){
    int i=0;
    string arr="MADAM";
    if(checkPallindrome(i,arr)){
        cout << " Valid Pallindrome ";
    }else{
        cout << "Not a Valid Pallindrome ";
    }
    return 0;
}