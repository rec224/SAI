% Arielle Grim McNally
% Math 4445: Project 1
% Summer I 2011
% Problem 1 (i)

function [x, opCount]=backsub(U,B)
%Input: U an upper triangular nxn matrix
%       B a matrix of length n
%Output: x a solution to Ux=B, x a vector of 
%        length n

[n,m] = size(B); 
x(n,:) = B(n,:)/U(n,n);
opCount = 1;
for i = n-1:-1:1    
    x(i,:) = (B(i,:) - U(i,i+1:n)*(x(i+1:n,:)))/U(i,i);  
    opCount = opCount + 2;
end

end

