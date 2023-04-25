/*Take a matrix A and return the Q value and the R value
found using Gram Schmidt QR factorization
*/
#include "matrix_mult.h"
#include <cmath>
#include <vector>
//create a data structure to hold the values of the sparse matrix (x, y, val)
struct pointVal{
    int x;
    int y;
    double val;
};
//function is void, assumes Q and R are null and stores 
//result of QR factorization in Q and R. 
void GS_QR_fac(vector<pointVal>, vector<pointVal>,vector<pointVal>);
void GS_QR_fac(vector<pointVal>A, vector<pointVal>Q, vector<pointVal>R){
    //get index values
    int n = A.size();
    //create 0 vectors both of length n
    vector<double>r;
    vector<double>q;
    for(int i=0; i<n; i++){
        r.at(i)=0;
        q.at(i)=0;
    }
    /*for j=1:n -- y = a(:,j)
     * now we know that A(:,j) means all rows 
     * and the jth column of A
    */
    //matlab .' means transpose
    vector<double>qVec;
    for(int j=1; j<n+1; j++){
        //y is the jth column of A
        //need every instance where A.at(i).y=
        vector<double>y_vec;
        for(int i=0; i<A.size(); i++){
            pointVal p = A.at(i);
            if(p.y ==j){
                y_vec.push_back(p.val);
            }
        }
        for(int k=0; k<n-1; k++){
            for(int i=0; i<n; i++){
                //qVec into row is the ith column of q
                qVec[0][i] = q[i][k];
            }
            for(int i=0; i<n-1; i++){
                for(int j=0; j<n; j++){
                    for (int k=0; k<n; k++){
                        //line 31? need some help with this possibly
                        r[k][j] += qVec[i][k]*y[k][0];
                        y[k][0] -= qVec[i][k]*r[k][j];
                    }
                }
            }
        }
        //getting the norm of y is as follows: 
        int sumOsqr = 0;
        for(int a=0; a<n; a++){
            int x = y[a][0];
            sumOsqr += x*x;
        }
        double norm = sqrt(sumOsqr);
        r[j][j] = norm;
        for(int z=0; z<n; z++){
            //element wise division y / norm(y,2)
            q[z][j] = y[z][0]/r[j][j];
        }
    }
    Q=q;
    R=r;
    //do we need the j+1:m? or can we always assume square
    //how do we return two values? add them as params and make
    //function void
}