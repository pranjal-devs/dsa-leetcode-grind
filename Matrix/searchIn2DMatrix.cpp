#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rows=matrix.size();
    int cols=matrix[0].size();
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(matrix[i][j]==target){
                return true;
            }
        }
    }
    return false;
}

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
    cout <<"Enter the target that you want to check : " << endl;
    int target;
    cin >> target;
    if(searchMatrix(matrix,target)){
        cout << "The target element is present in the matrix";
    }
    else{
        cout << "The targer element is not present in the matrix";
    }
    return 0;
}