#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
void displayarray(vector<char>vec){
    for(int i=0;i<vec.size();i++){
        cout << vec[i] << " ";
    }
    cout << endl;
}
char mostfrequentcharacter(vector<char>vec){
    for(int i=0;i<vec.size();i++){
        vec[i]-='a';
    }
    int maxval=*(max_element(vec.begin(),vec.end()));
    vector<int>freqarr(maxval+1,0);
    for(int i=0;i<vec.size();i++){
        freqarr[vec[i]]++;
    }
    int maxfreq=-1;
    int mostFreqindex=-1;
    for(int i=0;i<=maxval;i++){
        if(freqarr[i]>maxfreq){
            maxfreq=freqarr[i];
            mostFreqindex=i;
        }
    }
    return mostFreqindex+'a';
    

}
int main(){
    vector<char>vec1={'h','e','l','l','o'};
    displayarray(vec1); 
    cout <<"The character with the most frequency is : " << mostfrequentcharacter(vec1) << endl;
    return 0;
}
