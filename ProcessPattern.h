//header file for process Pattern=1
int** processPattern1(int**A){
    int **logicalA;
    int **logAsq;
    //heres PP
    for(int i=0; i<25; i++){
        for(int j=0; j<25; j++){
            if(A[i][j]!=0){
                logicalA[i][j]= 1;
            }
            else{
                logicalA[i][j]=0;
            }
        }
    }
    //calculate logical(A)^2
    for(int i=0; i<25; i++){
        for(int j=0; j<25; j++){
            logAsq[i][j]=0;
            for (int k=0; k<25; k++){
                logAsq[i][j] += logicalA[i][k]*logicalA[k][j];
            }
        }
    }
    //recalculating logical(input) to get PP2
    for(int i=0; i<25; i++){
        for(int j=0; j<25; j++){
            if(logicalA[i][j]!=0){
                logicalA[i][j]= 1;
            }
            else{
                logicalA[i][j]=0;
            }
        }
    }
    return logicalA;
}