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
        string getString(){
            return str;
        }
        void setString(string newStr){
            str=newStr;
        }
};
int main(){
    string input;
    cout <<"Enter a string : ";
    cin >> input;
    StringManipulator strObj(input);
    cout <<"The string is as follows : " << strObj.getString() << endl;

    return 0;
}