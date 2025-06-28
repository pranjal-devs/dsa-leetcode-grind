#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Matrix{
    private : 
        vector<vector<int>>matrix;
        int rows;
        int cols;
    public :
        Matrix(int r,int c) : rows(r) , cols(c) {}
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
        int binarysearch(vector<int>arr,int target){
            int start=0;
            int end=arr.size();
            while(start<=end){
                int mid=start+(end-start)/2;
                if(arr[mid]==target){
                    return 1;
                }
                else if(arr[mid]>target){
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }
            return 0;
        }
        bool searchMatrix(vector<vector<int>>& matrix, int target){
            int m=matrix[0].size();
            int row=0;
            int col=m-1;
            while(row<m&&col>0){
                if(matrix[row][col]==target){
                    return true;
                }
                else if (matrix[row][col]>target){
                    col--;
                }
                else{
                    row++;
                }
            }
            return false;
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
    int target;
    cout << "Enter the target value that you want to find in the matrix : ";
    cin >> target;
    if(mat.searchMatrix(matrix,target)){
        cout<<"The given target is present in the matrix";
    }
    else{
        cout <<"The given target is not present in the matrix";
    }
    return 0;
}