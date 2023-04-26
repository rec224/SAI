#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "ProcessPattern.h"
#include "GS_QR_fac.h"
#include "backsub.h"
using namespace std;
vector<pointVal> pattern;
int main() {
    /*Step 1: first thing we want to do is load in the matricies
    do this using a text file with the information for 
    the matricies. 
    Parse from the file to find the nonzero locations as 
    well as the nonzero values
    */
    std::string fname = "FDnonlinearMat1_1.txt";
    int n=25;
    vector<pointVal>A;
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
        pointVal p;
        p.x=atoi(point.at(0));
        p.y=atoi(point.at(1));
        p.val = stod(point.at(2));
        A.push_back(p);
    }
    //close the file
    readFile.close();
    //we've made A, now we need to make the sparsity pattern
    //pattern is a global variable here, want to make sure not 
    //mess aroud with that too much
    pattern = processPattern1(A);
   /* Step 3: convert for loop into c++ (lines 37-64)
   */
    //initialize vectors we will need for QR fac and SAI computations
    vector<pointVal>vecE;
    vector<pointVal>R;
    vector<pointVal>Q;
    vector<pointVal>M;
    vector<pointVal>mk;
    //compute lease squares using QR factorization
    for(int i=0; i<n; i++){
        for(int j=0; j<A.size(); j++){
            double d = 0.0;
            pointVal m;
            m.x=i;
            m.y=j;
            m.val=d;
            vecE.push_back(m);
        }
        pointVal m =vecE.at(i);
        m.val=1;
        vecE.at(i)=m;
        //now we need to convert GS_QR into c++
        GS_QR_fac(A, Q, R);
        vector<pointVal>Qt;
        for(int a=0; a<Q.size(); a++){
            pointVal qpoint = Q.at(a);
            int x2 = qpoint.y;
            int y2= qpoint.x;
            qpoint.x=x2;
            qpoint.x=y2;
            Qt.push_back(qpoint);
        }
        vector<pointVal>vecY;
        //vecY= matrix_mult(Qt, vecE);
        for(int f=0; f<Qt.size(); f++){
            for(int g=0; g<vecE.size(); g++){
                pointVal p = Qt.at(f);
                int x1 = p.x;
                int y2 = p.y;
                pointVal q = vecE.at(g);
                int x2= q.x;
                int y2 = q.y;
                if (x1 == y2){
                    pointVal pq;
                    pq.x = x1;
                    pq.y = y2;
                    pq.val = (p.val)*(q.val);
                    vecY.push_back(pq);
                }
            }
        }
        //vecY is too large, need to sum up all of the values
        for(int f=0; f<vecY.size() -1; f++){
            pointVal p = vecY.at(f);
            for(int g=f+1; g < vecY.size(); g++){
                pointVal q = vecY.at(g);
                if((p.x == q.x) && (p.y ==q.y)){
                    double sum = p.val + q.val;
                    p.val = sum;
                    vecY.at(f)=p;
                    //erase the g-th element
                    vecY.erase(vecY.begin()+g,vecY.begin()+g+1);
                    g--;
                }
            }
        }
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