#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int hash[13]={0}; // creating a hash array of size 13 and initialise with 0
    for(int i=0;i<n;i++){
        hash[a[i]]++;
    }
    int q;
    cin >> q;
    while (q--){
        // getting the output
        int num;
        cin >> num;
        cout << hash[num] << " ";

    }
    
    return 0;
}