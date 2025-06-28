#include<iostream>
using namespace std;
#include<vector>

int highestAltitude(vector<int>&gain){
    int currentAltitude=0;
        int maxAltitude=0;
        for(int i=0;i<gain.size();i++){
            currentAltitude+=gain[i];
            if(currentAltitude>maxAltitude){
                maxAltitude=currentAltitude;
            }
        }
        return maxAltitude;
}

void displayVector(const vector<int>& vec){
    for(auto it=vec.begin();it!=vec.end();++it){
        cout<<*it<<"\t"; 
    }
    cout<<endl;
}

int main(){
    vector<int>vec1={-5,1,5,0,-7};
    displayVector(vec1);
    cout << "The highest altitude is : " << highestAltitude(vec1);
}