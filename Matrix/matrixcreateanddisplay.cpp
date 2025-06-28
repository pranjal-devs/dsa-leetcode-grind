#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>


int main(){
    int rows,cols;
    // taking matrix dimensions as input
    cout<<"Enter the number of rows and cols that you want to enter in the matrix";
    cin >> rows >> cols;
    vector<vector<int>> matrix(rows, vector<int>(cols));
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cin >> matrix[i][j];
        }
    }
    // displaying the matrix 
    cout <<"The matrix is as follows : "<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout << matrix[i][j] <<"    ";
        }
        cout << endl;
    }
    return 0;
}