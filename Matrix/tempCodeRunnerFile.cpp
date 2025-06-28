
        void markrow(int i,int m,vector<vector<int>>&matrix){
            for(int j=0;j<m;j++){
                if(matrix[i][j]!=0)
                    matrix[i][j]=-1;
            }
        }
        void markcol(int j,int n,vector<vector<int>>&matrix){
            for(int i=0;i<n;i++){
                if(matrix[i][j]!=0)
                    matrix[i][j]=-1;
            }
        }
        void setZeroes(vector<vector<int>>& matrix) {
            int m=matrix.size();
            int n=matrix[0].size();
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(matrix[i][j]==0){
                        markrow(i,m,matrix);
                        markcol(j,n,matrix);
                    }
                }
            }
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(matrix[i][j]==-1){
                        matrix[i][j]=0;
                    }
                }
            }
        }