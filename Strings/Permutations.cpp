#include<bits/stdc++.h>
using namespace std;

int main(){ // this is done using the direct function called next_permutation(s.begin(),s.end()); where s is the string entered by the user
    string str1="ab";
    string str2="eidbaooo";
    sort(str1.begin(),str1.end());
    do{
        if (str2.find(str1) != string::npos) {
            cout << "Yes";
    } else {
        cout << "str1 is NOT present in str2" << endl;
    }
    }while(next_permutation(str1.begin(),str1.end()));
    return 0;
}
