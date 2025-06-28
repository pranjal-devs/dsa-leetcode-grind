#include<bits/stdc++.h>
using namespace std;
void recursion(int i,int n){
    if(i>n){
        return;
    }
    cout << "Pranjal Kandpal";
    recursion(i+1,n);
}
int main(){
    int n;
    cout <<"Enter n";
    cin >> n;
    recursion(1,n);
    return 0;
}