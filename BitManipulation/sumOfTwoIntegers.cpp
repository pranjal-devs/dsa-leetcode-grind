#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int getSum(int a, int b) {
            while(b!=0){
                int carry = a&b;
                a=a^b;
                b=carry<<1;
            }
            return a;
        }
};
int main(){
    int a=1;
    int b=1;
    int c=a<<b;
    cout << c;
    return 0;
}