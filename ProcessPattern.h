//header file for process Pattern=1
#include "matrix_mult.h"
#include <vector>
//create a data structure to hold the values of the sparse matrix (x, y, val)
struct pointVal{
    int x;
    int y;
    double val;
};
vector<pointVal> processPattern1(vector<pointVal>B); 
vector<pointVal> processPattern1(vector<pointVal>B) {
    //heres PP for pattern =1
    vector<pointVal> logical_A;
    for(int i=0; i<B.size(); i++){
        pointVal p =B.at(i);
        p.val=1;
        logical_A.push_back(p);
    }
    vector<pointVal> logical_A2;
    //calculate logical(A)^2
    for(int i=0; i<logical_A.size(); i++){
        for(int j=0; j<logical_A.size(); j++){
            pointVal p = logical_A.at(i);
            int x1 = p.x;
            int y2 = p.y;
            pointVal q = logical_A.at(j);
            int x2= q.x;
            int y2 = q.y;
            if (x1 == y2){
                pointVal pq;
                pq.x = x1;
                pq.y = y2;
                pq.val = (p.val)*(q.val);
                logical_A2.push_back(pq);
            }
        }
    }
    //logical_A2 is too large, need to sum up all of the values
    for(int i=0; i<logical_A2.size() -1; i++){
        pointVal p = logical_A2.at(i);
        for(int j=i+1; j < logical_A2.size(); j++){
            pointVal q = logical_A2.at(j);
            if((p.x == q.x) && (p.y ==q.y)){
                double sum = p.val + q.val;
                p.val = sum;
                logical_A2.at(i)=p;
                //erase the j-th element
                logical_A2.erase(logical_A2.begin()+j+1);
                j--;
            }
        }
    }
    //logAsq = matrix_mult(logicalA, logicalA);
    //recalculating logical(input) to get PP2
    /*for(int i=0; i<25; i++){
        for(int j=0; j<25; j++){
            if(logicalA[i][j]!=0){
                logicalA[i][j]= 1;
            }
            else{
                logicalA[i][j]=0;
            }
        }
    }*/
    return logical_A2;
}