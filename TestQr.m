load('Matrices_n25.mat');
A = FDnonlinearMats{1,1};
n = size(A,2);

I = speye(n);

% Set sparsity pattern (here, that of powers of the coefficient matrix)
% Play with varying sparsity patterns to investigate the accuracy of the
% SAI
[PP,PP2] = ProcessPattern(A,1);
[ q,r ] = GS_QR_fac( A );
B = q*r;
% at this point I was thinking of usinig isequal with a tolerance to make 
% sure B=A in the inmportant spots, do you think I need it?
