#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class StringManipulator{
    private : 
        string str;
    public :
        StringManipulator(){}
        StringManipulator(string num){
            str=num;
        }
        string getString(){
            return str;
        }
        void setString(string newStr){
            str=newStr;
        }
        
        string largestOddNumber(string num) {
            int n=num.size();
            for(int i=n-1;i>=0;i--){
                if(num[i]%2!=0){
                    return num.substr(0,i+1);
                }
            }
            return "";
        }
};
int main(){
    string input;
    cout <<"Enter a string : ";
    cin >> input;
    StringManipulator strObj;
    string ans=strObj.largestOddNumber(input);
    cout<<"The largest odd number is : " <<  ans;
    return 0;
}