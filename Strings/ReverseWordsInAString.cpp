#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class StringManipulator {
    private: 
        string str;
    public:
        StringManipulator() {}
        StringManipulator(string s) {
            str = s;
        }

        // Get the string from the private member 'str'
        string getString() {
            return str;
        }

        // Set the string to the private member 'str'
        void setString(string newStr) {
            str = newStr;
        }

        // Function to reverse each word in the string
        string reverseWords(string s) {
            reverse(s.begin(),s.end());
            int n=s.length();
            string ans="";
            for(int i=0;i<n;i++){
                string word="";
                while(i<n&&s[i]!=' '){
                    word+=s[i];
                    i++;
                }
                reverse(word.begin(),word.end());
                if(word.length()>0)
                    ans+=' '+word;
            }
            return ans.substr(1);
        } 
};

int main() {
    string input;
    // Get the entire line including spaces
    cout << "Enter a string: ";
    getline(cin, input);  // Use getline to read the entire input with spaces

    // Create an object of StringManipulator and pass the input string
    StringManipulator strObj(input);

    // Output the original string
    cout << "The string is as follows: " << strObj.getString() << endl;

    // Output the string with reversed words
    cout << "The reversed string is as follows: " << strObj.reverseWords(input) << endl;

    return 0;
}
