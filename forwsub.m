% Arielle Grim McNally
% Math 4445: Project 1
% Summer I 2011
% Problem 1 (ii)

function [x] = forwsub(L,B)
%Input: L a lower triangular nxn matrix
%       B a matrix of length n
%Output: x a solution to Lx=B, x a vector of
%        length n

[n,m] = size(B);
x(1,:) = B(1,:)/L(1,1);
for i = 2:n
    x(i,:) = (B(i,:) - L(i,1:i-1)*x(1:i-1,:))/L(i,i);
end

end
