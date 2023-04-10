/*Take a matrix A and return the Q value and the R value
found using Gram Schmidt QR factorization
*/
#include "matrix_mult.h"
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
    int **qVec;
    for(int j=0; j<n; j++){
        for(int i=0; i<n; i++){
            //y is the jth column of A
            y[i][1] = A[i][j];
        }
        for(int k=0; k<n-1; k++){
            for(int i=0; i<n; i++){
                //qVec into row is the ith column of q
                qVec[1][i] = q[i][k];
            }
            for(int i=0; i<n-1; i++){
                for(int j=0; j<n; j++){
                    for (int k=0; k<n; k++){
                        r[k][j] += qVec[i][k]*y[k][j];
                    }
                }
            }
    }
}