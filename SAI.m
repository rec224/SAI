
load('Matrices_n25.mat');
A = FDnonlinearMats{1,1};
n = size(A,2);

I = speye(n);

% Set sparsity pattern (here, that of powers of the coefficient matrix)
% Play with varying sparsity patterns to investigate the accuracy of the
% SAI
[PP,PP2] = ProcessPattern(A,1);

% Initialize the data structures to store row, col, val info for the map
% (will eventually be used to create a 'sparse' data structure)
nnzMM = nnz(PP2);
rowM = zeros(2*nnzMM,1);
colM = zeros(2*nnzMM,1);
valM = zeros(2*nnzMM,1);

% Determine the size of the least squares problem for each column of the
% SAI
for k = 1:n
    nz_M{k} = find(PP(:,k)); 
    nnz_M(k) = length(nz_M{k});
    nz_LS{k} = find(PP2(:,k));
    nnz_LS(k) = length(nz_LS{k});
end

% Initialize the counter (for storing row, col, val data in the sparse data
% structure)
cntrM = 0;

%Initiallize a working vector (for each column of the SAI)
max_row = max(nnz_LS);
M = zeros(max_row,1);

for k = 1:n
    % Computes the small least squares problem defined by the sparsity 
    % pattern for each column of the SAI
    % (To do:Replace the backslash operator with a QR factorization)
    e = zeros(n,1);
    e(k) = 1;
    %could also replace with matlab qr func, but not sure I know how to
    %convert that into c++
    [Q,R] = GS_QR_fac( A );
    y = transpose(Q)*e;
    mk = backsub(R, y);
    % now that I have the QR fac, how do I use it to replace the \
    % operator? should I be pulling columns from I and then multiplying by
    % R inv and Q trans?
    %shows the values of mk and e
    disp(mk);
    disp(e);
    %is this line equivalent to calcuating mk?
    M(1:nnz_M(k)) = A(nz_LS{k},nz_M{k})\I(nz_LS{k},k);
    
    % The following puts the nonzero values and their row and column
    % indices into row, col, val arrays to eventually create the sparse
    % matrix format (which is the same as coordinate format)
    rowM(cntrM+1:cntrM+nnz_M(k)) = nz_M{k};
    colM(cntrM+1:cntrM+nnz_M(k)) = k;
    valM(cntrM+1:cntrM+nnz_M(k)) = M(1:nnz_M(k));
    cntrM = cntrM+nnz_M(k);
end

MM = sparse(rowM(1:cntrM),colM(1:cntrM),valM(1:cntrM));

%Investigate the accuracy of the SAI 
residual = norm(MM*A-I,'fro');





