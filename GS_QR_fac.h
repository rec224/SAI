/*Take a matrix A and return the Q value and the R value
found using Gram Schmidt QR factorization
*/

int* GS_QR_fac(int**A){
    //get index values
    int m = sizeof(A)/sizeof(A[0]);
    int n = sizeof(A[0])/sizeof(A[0][0]);
    //create 0 vectors. r mxn q mxm
    int **r;
    int **q;
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            q[i][j]=0;
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            r[i][j]=0;
        }
    }
    /*for j=1:n -- y = a(:,j)
     * now we know that A(:,j) means all rows 
     * and the jth column of A
    */
    //matlab .' means transpose
    int **y;
    for(int j=0; j<n; j++){
        for(int i=0; i<n; i++){
            y[i][1] = A[i][j];
        }
        for(int k=0; k<n-1; k++){
            
        }
    }
}