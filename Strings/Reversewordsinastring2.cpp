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
        StringManipulator(string s){
            str=s;
        }
        string getString(string str){
            return str;
        }
        void setString(string newStr){
            str=newStr;
        }
        string reverseWords(string s) {
            int start=0;
            for(int end=0;end<=s.length();end++){
                if(end==s.length()|| s[end]==' '){
                    reverse(s.begin() + start, s.begin() + end);
                    start=end+1;
                }
            }
            return s;
        }
};
int main(){
    string input;
    cout <<"Enter a string : ";
    cin >> input;
    StringManipulator strObj;
    cout <<"The string is as follows : " << strObj.getString(input) << endl;
    cout <<"The reversed string is as follows : " << strObj.reverseWords(input) << endl;
    return 0;
}