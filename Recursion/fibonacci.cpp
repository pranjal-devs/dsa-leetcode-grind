#include<bits/stdc++.h>
using namespace std;
int fibonacci(int x){
    if(x<=1) return x;
    return (fibonacci(x-1) + fibonacci(x-2));
}
int main(){
    cout << fibonacci(5);
    cout << endl;
    cout << fibonacci(4);
    return 0;
}