//matrix multiplication 
int ** matrix_mult(int **A, int** B){
    int m = sizeof(A)/sizeof(A[0]);
    int n = sizeof(A[0])/sizeof(A[0][0]);
    int n_b = sizeof(B)/sizeof(B[0]);
    int p = sizeof(B[0])/sizeof(B[0][0]);
    if(n != n_b){
        return nullptr;
    }
    int **C;
    for(int i=0; i<m; i++){
        for(int j=0; j<p; j++){
            C[i][j]=0;
            for (int k=0; k<n; k++){
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }
    return C;
}