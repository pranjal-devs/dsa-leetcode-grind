#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

vector<vector<int>> transpose(vector<vector<int>>& matrix){
    int rows=matrix.size();
    int cols=matrix[0].size();
    vector<vector<int>>transposed(cols,vector<int>(rows));
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            transposed[i][j]=matrix[j][i];
        }
    }
    return transposed;
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

    cout <<"The matrix is as follows : "<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout << matrix[i][j] <<"    ";
        }
        cout << endl;
    }

    matrix=transpose(matrix);
    // displaying the matrix 
    cout <<"The transposed matrix is as follows : "<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout << matrix[i][j] <<"    ";
        }
        cout << endl;
    }
    return 0;
}