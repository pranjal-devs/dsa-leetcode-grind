#include<iostream>
using namespace std;

int main(){
    string s;
    cin >>s;
    int hash[26]={0}; // creating a hash array of size 13 and initialise with 0
    for(int i=0;i<s.size();i++){
        hash[s[i]-'a']++;
    }
    int q;
    cin >> q;
    while (q--){
        // getting the output
        char c;
        cin >> c;
        cout << hash[c-'a'] << " ";

    }
    
    return 0;
}