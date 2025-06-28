#include<bits/stdc++.h>
using namespace std;
// void printN(int i,int n){
//     if(i<n){
//         return;
//     }
//     cout << i;
//     printN(i-1,n);
// }
// int main(){
//     int n;
//     cin >> n;
//     printN(n,1);
//     return 0;
// }


// void printN(int i,int sum){
//     if(i<1){
//         cout << sum;
//         return;
//     }
//     printN(i-1,sum+i);
// }
// int main(){
//     int sum=0;
//     int i=10;
//     printN(i,sum);
//     return 0;
// }

int fnc(int n){
    if(n==0) return 0;
    return (n+fnc(n-1));
}
int main(){
    int ans=fnc(6);
    cout << ans;
    return 0;
}