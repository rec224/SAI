#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include<vector>
#include "ProcessPattern.h"
#include "GS_QR_fac.h"
#include "backsub.h"
using namespace std;
double **pattern;
int main() {
    /*Step 1: first thing we want to do is load in the matricies
    do this using a text file with the information for 
    the matricies. 
    Parse from the file to find the nonzero locations as 
    well as the nonzero values
    */
    std::string fname = "FDnonlinearMat1_1.txt";
    int n=25;
    double** A;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            A[i][j]=0;
        }
    }
    //read from file fname
    ifstream readFile(fname);
    std::string file_line;
    while(getline(readFile, file_line)){
        vector<char*> point;
        //convert string to char *
        const int length = file_line.length();
        char *str = new char[length +1];
        strcpy(str, file_line.c_str());
        //go through string to get points and store each 
        //in a temporary vector
        char *token = strtok(str,", ");
        while(token){
            point.push_back(token);
            token = strtok(NULL, ", ");
        }
        //cast values from the points to ints (indicies)
        //and doubles (vals)
        int i = (int)(point.at(0));
        int j = (int)(point.at(1));
        double val = std::stod(point.at(2));
        //overwrite values of 0 based on value from the file
        A[i][j] = val;
    }
    //close the file
    readFile.close();
    //we've made A, now we need to make the sparsity pattern
    //pattern is a global variable here, want to make sure not 
    //mess aroud with that too much
    pattern = processPattern1(A);
   /* Step 3: convert for loop into c++ (lines 37-64)
   */
    //initialize that column of all 0s
    double **vecE;
    double **R;
    double **Q;
    double **M;
    double **mk;
    //compute lease squares using QR factorization
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            vecE[j][0]=0;
        }
        vecE[i][0] =1;
        //now we need to convert GS_QR into c++
        GS_QR_fac(A, Q, R);
        double **Qt;
        for(int a=0; a<n; a++){
            for(int b=0; b<n; b++){
                //get the transpose of Q
                Qt[b][a] = Q[a][b];
            }
        }
        double **vecY;
        vecY= matrix_mult(Qt, vecE);
        //mk = backsub(R, y)
        //have to write the C++ file for backsub first!
        mk = backsub(R, vecY);
        //put into a double ** --> record all the calculated columns
        for(int k=0; k<n; k++){
            M[i][k] = mk[k][0];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << M[i][j];
        }
    }
    return 0;
}