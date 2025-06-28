// using the classes and objects in cpp is very necessary
// matrix rotation using classes and objects


#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Matrix{
    private : // here wwe are inititalising a matrix as private 
        vector<vector<int>> matrix;
        int rows,cols;
    public :
        // constructor to initialise matrix dimensions
        Matrix(int r,int c) : rows(r), cols(c){}
        // function to take input for the matrix
        void inputMatrix(vector<vector<int>>&matrix){
            cout<<"Enter the element of the matrix :  " << endl;
            for(int i=0;i<rows;i++){
                for(int j=0;j<cols;j++){
                    cin >> matrix[i][j];
                }
            }
        }
        void displayMatrix(vector<vector<int>>&matrix){
            cout << "The matrix is as follows : " << endl;
            for(int i=0;i<rows;i++){
                for(int j=0;j<cols;j++){
                    cout << matrix[i][j] << " ";
                }
                cout << endl;
            }
        }
        int diagonalSum(vector<vector<int>>& mat) {
            int sum=0;
            int n=mat.size();
            for(int i=0;i<n;i++){
                sum+=mat[i][i];
                sum+=mat[i][n-i-1];
            }
            if((n%2)!=0){
                sum-=mat[n/2][n/2];
            }
            return sum;
        }
};


int main(){
    int rows,cols;
    // taking matrix dimensions as input
    cout<<"Enter the number of rows and cols that you want to enter in the matrix";
    cin >> rows >> cols;
    if(rows!=cols){
        cout << "Matrix must me square to rotate " << endl;
        return 0;
    }
    Matrix mat(rows,cols);
    vector<vector<int>> matrix(rows, vector<int>(cols));
    mat.inputMatrix(matrix);
    mat.displayMatrix(matrix);
    int sum=mat.diagonalSum(matrix);
    cout <<"The diagonal sum of the matrix is : " << sum;    
    return 0;
}
