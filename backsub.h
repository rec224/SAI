//here, we will convert the backsub.m file to cpp so that we can use
//it in SAI_cpp
#include <vector>
//create a data structure to hold the values of the sparse matrix (x, y, val)
struct pointVal{
    int x;
    int y;
    double val;
};
vector<pointVal> backsub(vector<pointVal>A, vector<pointVal>x){
    vector<pointVal>soln;
    //get size of A
    int n = A.size();
    int m = x.size();
    //x(n,:) = B(n,:)/U(n,n);
    for(int i=n; i>0; i--){
        for(int j=n; j>0; j--){
            pointVal solved;
            solved.x=i;
            solved.y=j;
            double Ad=0.0;
            double xd=0.0;
            for(int w=0; w<n; w++){
                pointVal pvw = A.at(w);
                if(pvw.x==i && pvw.y==j){
                    Ad=pvw.val;
                }
            }
            for(int v=0; v<n; v++){
                pointVal pvv = x.at(v);
                if(pvv.x==j && pvv.y==j){
                    xd=pvv.val;
                }
            }
            solved.val = Ad/xd;
            soln.push_back(solved);
        }
    }
    vector<pointVal>mod_soln;
    int s_len = soln.size();
    for(int i=n; i>0; i--){
        for(int j=n; j>0; j--){
            pointVal s;
            pointVal a;
            pointVal x_1;
            pointVal x_2;
            pointVal x_3;
            for(int c=0; c<n; c++){
                pointVal pos_a = A.at(c);
                if(pos_a.x==i && pos_a.y==j){
                    a = pos_a;
                }
            }
            for(int d=0; d<m; d++){
                pointVal pos_x = x.at(d);
                if(pos_x.x==i && pos_x.y==j+1){
                    x_1 = pos_x;
                }
                else if(pos_x.x==j+1 && pos_x.y==i){
                    x_2 = pos_x;
                }
                else if(pos_x.x==j && pos_x.y==j){
                    x_3 = pos_x;
                }
            }
            for(int b=0; b<s_len; b++){
                pointVal pos_s = soln.at(b);
                if(pos_s.x==i && pos_s.y==j){
                    s = pos_s;
                }
            }
            s.val = (a.val - x_1.val*x_2.val)/x_3.val;
            mod_soln.push_back(s);
        }
    }
    return mod_soln;
}