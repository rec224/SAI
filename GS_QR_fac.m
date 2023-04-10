function [ q,r ] = GS_QR_fac( A )
%GramSchmidtQR: Gram Schmidt method for Full QR factorization
%   A cannot be e.g. [a 0;0 b;0 0]   
    [m,n]=size(A);
    %if rank(A)<n
        %error('A not linearly independent');
    %end
    
    r=zeros(m,n);
    q=zeros(m,m);
    
    for j=1:n
        y=A(:,j);
        for i=1:j-1
            r(i,j)=q(:,i)'*A(:,j);
            y=y-q(:,i)*r(i,j);
        end
        r(j,j)=norm(y,2);
        q(:,j)=y./r(j,j);
    end
    
    a=eye(m); % make q square matrix m*m
    fakeA=[A a(:,1:m-n)];
    %if rank(fakeA)<m
        %error('Default vectors not linearly independent to A');
    %end
    
    for j=n+1:m
        y=a(:,j-n);
        for i=1:j-1
            y=y-q(:,i)*(q(:,i)'*a(:,j-n));
        end
        q(:,j)=y./norm(y,2);
    end
    
    %disp('Plz check q*r equals A!')
    
end
% Citation: Jialei Xin (2023). GramSchmidtQR 
% (https://www.mathworks.com/matlabcentral/fileexchange/74379-gramschmidtqr), MATLAB Central File Exchange. 
% Retrieved March 20, 2023.
