//here, we will convert the backsub.m file to cpp so that we can use
//it in SAI_cpp

double** backsub(double **A, double **x){
    double **soln;
    //get size of A
    int m = sizeof(A)/sizeof(A[0]);
    int n = sizeof(A[0])/sizeof(A[0][0]);
    //x(n,:) = B(n,:)/U(n,n);
    for(int i=n; i>0; i--){
        for(int j=n; j>0; j--){
            soln[i][j] = A[i][j]/x[j][j];
        }
    }
    for(int i=n; i>0; i--){
        for(int j=n; j>0; j--){
            soln[i][j] = (A[i][j] -x[i][j+1]*(x[j+1][i]))/x[j][j];
        }
    }
    return soln;
}