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
        // void markrow(int i, int m, vector<vector<int>>& matrix) {
        //     for (int j = 0; j < m; j++) {
        //         if (matrix[i][j] != 0)
        //             matrix[i][j] = -1;  // Mark the row
        //     }
        // }
        
        // void markcol(int j, int n, vector<vector<int>>& matrix) {
        //     for (int i = 0; i < n; i++) {
        //         if (matrix[i][j] != 0)
        //             matrix[i][j] = -1;  // Mark the column
        //     }
        // }
        
        // void setZeroes(vector<vector<int>>& matrix) {
        //     int m = matrix.size();
        //     int n = matrix[0].size();
            
        //     // Step 1: Traverse the matrix to find zeros and mark rows and columns
        //     for (int i = 0; i < m; i++) {
        //         for (int j = 0; j < n; j++) {
        //             if (matrix[i][j] == 0) {
        //                 markrow(i, m, matrix);
        //                 markcol(j, n, matrix);
        //             }
        //         }
        //     }
            
        //     // Step 2: Traverse again to set marked elements to zero
        //     for (int i = 0; i < m; i++) {
        //         for (int j = 0; j < n; j++) {
        //             if (matrix[i][j] == -1) {
        //                 matrix[i][j] = 0;  // Set marked elements to 0
        //             }
        //         }
        //     }
        // } // this was the brute force approach
        
        // now comes the better one

        // The idea behind the better approach is that i will set 2 arrays each for row and col
        // will iterate the matrix in O(n^2) complexity and if the element is 0 then mark that row and col as 1
        // reiterate the matrix and set all the marked one as 0 in the matrix

        
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>row(m,0);// creating an array of m size initialised with 0 to mark
        vector<int>col(n,0);// creating an array of n size initialised with 0 to mark
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){  // traversing the matrix in O(n^2) complexity
                if(matrix[i][j]==0){ // getting the 0 element of the matrix
                    row[i]=1;  // set the row[i] element and col[j] element to 0 when find a 0 in the matrix
                    col[j]=1;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){ // again traverse the matrix in O(n^2) complexity
                if(row[i]||col[j]){ // if the row or col element is 0
                    matrix[i][j]=0; // mark the element as 0
                }
            }
        }
    }
        
};


int main(){
    int rows,cols;
    // taking matrix dimensions as input
    cout<<"Enter the number of rows and cols that you want to enter in the matrix";
    cin >> rows >> cols;
    Matrix mat(rows,cols);
    vector<vector<int>> matrix(rows, vector<int>(cols));
    mat.inputMatrix(matrix);
    mat.displayMatrix(matrix);
    mat.setZeroes(matrix);
    mat.displayMatrix(matrix);
    return 0;
}
