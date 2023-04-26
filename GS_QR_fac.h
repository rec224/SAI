/*Take a matrix A and return the Q value and the R value
found using Gram Schmidt QR factorization
*/
#include <cmath>
#include <vector>
//create a data structure to hold the values of the sparse matrix (x, y, val)
struct pointVal{
    int x;
    int y;
    double val;
};
vector<pointVal>r_vec;
vector<pointVal>q;
pointVal pv;
vector<pointVal>qVec;
vector<pointVal>part_r;
vector<pointVal>part_y;
vector<pointVal>f_q;
//function is void, assumes Q and R are null and stores 
//result of QR factorization in Q and R. 
void GS_QR_fac(vector<pointVal>A, vector<pointVal>Q, vector<pointVal>R){
    //get index values
    int n = A.size();
    //create 0 vectors both of length n
    for(int i=0; i<n; i++){
        pointVal p;
        p.x=0;
        p.y=0;
        p.val=0.0;
        r_vec.at(i)=p;
        q.at(i)=p;
    }
    /*for j=1:n -- y = a(:,j)
     * now we know that A(:,j) means all rows 
     * and the jth column of A
    */
    //matlab .' means transpose
    for(int j=0; j<n; j++){
        //y is the jth column of A
        //need every instance where A.at(i).y=
        vector<pointVal>y_vec;
        for(int i=0; i<n; i++){
            pointVal p = A.at(i);
            if(p.y ==j){
                y_vec.push_back(p);
            }
        }
        //y_vec is the jth column of A
        for(int k=0; k<n-1; k++){
            for(int i=0; i<n; i++){
                //qVec into row is the ith column of q
                //qVec[0][i] = q[i][k];
                pointVal p = q.at(k);
                qVec.at(i) = p;
            }
            for(int i=0; i<n-1; i++){
                for(int j=0; j<n; j++){
                    for (int k=0; k<n; k++){
                        //line 31? need some help with this possibly
                        pointVal pv = r_vec.at(k);
                        int x = pv.x;
                        int y= pv.y;
                        if(x==k && y==j){
                            double qd = (qVec.at(i)).val;
                            double yd = (y_vec.at(k)).val;
                            pointVal newPV = r_vec.at(k);
                            newPV.val = qd*yd;
                            part_r.push_back(newPV);
                            double rd = qd*yd;
                            pointVal part_y_pv = y_vec.at(k);
                            double yval = part_y_pv.val;
                            yval = yval - qd*rd;
                            part_y_pv.val = yval;
                            part_y.push_back(part_y_pv);
                        }
                        for(int z=0; z<part_r.size() -1; z++){
                            pointVal p = part_r.at(i);
                            for(int w=z+1; w < part_r.size(); w++){
                                pointVal q = part_r.at(w);
                                if((p.x == q.x) && (p.y ==q.y)){
                                    double sum = p.val + q.val;
                                    p.val = sum;
                                    part_r.at(z)=p;
                                    //erase the w-th element
                                    part_r.erase(part_r.begin(), w+1);
                                    w--;
                                }
                            }
                        }
                        for(int z=0; z<part_y.size() -1; z++){
                            pointVal p = part_y.at(i);
                            for(int w=z+1; w < part_y.size(); w++){
                                pointVal q = part_y.at(w);
                                if((p.x == q.x) && (p.y ==q.y)){
                                    double sum = p.val + q.val;
                                    p.val = sum;
                                    part_y.at(z)=p;
                                    //erase the w-th element
                                    part_y.erase(part_y.begin(), w+1);
                                    w--;
                                }
                            }
                        }
                    }
                }
            }
        }
        //getting the norm of y is as follows: 
        double sumOsqr = 0.0;
        int len = part_y.size();
        for(int a=0; a<len; a++){
            pointVal x = part_y.at(a);
            double d = x.val;
            sumOsqr += d*d;
        }
        double norm = sqrt(sumOsqr);
        pointVal last;
        last.x=j;
        last.y=j;
        last.val =norm;
        part_r.push_back(last);
        for(int z=0; z<n; z++){
            //element wise division y / norm(y,2)
            pointVal qpv;
            int qpvx = z;
            int qpvy = j;
            double y_d=0.0;
            double r_d=0.0;
            for(int m=0; m<part_y.size(); m++){
                pointVal pvm = part_y.at(m);
                if(pvm.x==z){
                    y_d=pvm.val;
                }
            }
            for(int m=0; m<part_r.size(); m++){
                pointVal pvr = part_r.at(m);
                if(pvr.x==j && pvr.y==j){
                    r_d=pvr.val;
                }
            }
            qpv.x=qpvx;
            qpv.y=qpvy;
            qpv.val = y_d/r_d;
            f_q.push_back(qpv);
        }
    }
    for(int p=0; p<f_q.size(); p++){
        pointVal last_pv=f_q.at(p);
        Q.push_back(last_pv);
    }
    for(int p=0; p<part_r.size(); p++){
        pointVal last_pv=part_r.at(p);
        R.push_back(last_pv);
    }
    //do we need the j+1:m? or can we always assume square
    //how do we return two values? add them as params and make
    //function void
    return;
}