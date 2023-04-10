function [PP,PP2] = ProcessPattern(A,pattern)

[I,J] = find(A);
findA = sparse(I,J,1);
n = size(A);
if pattern == -1
    %disp('Start diagonal pattern')
    PP = diag(diag(ones(n)));
    PP2 = PP;

elseif pattern == 0
    %disp('Start tridiagonal pattern')
    PP = sparse(gallery('tridiag',n,1,1,1));
    PP2 = PP;

elseif pattern == 1
    %disp('Start Pattern of A0')
    PP = logical(findA);
    PP2 = logical(sparse(double(PP)*double(PP))); % PP^2

elseif pattern == 2
    %disp('Start Pattern of A0^2')
    PP = logical(findA);
    PP2 = logical(sparse(double(PP)*double(PP))); % PP^2
    HoldPP2 = PP2;
    PP2 = logical(sparse(double(PP)*double(PP2))); % PP^3
    PP = HoldPP2;

elseif pattern == 3
    %disp('Start Pattern of A0^3 Map')
    PP = logical(findA);
    PP2 = logical(sparse(double(PP)*double(PP))); % PP^2
    PP3 = logical(sparse(double(PP)*double(PP2))); % PP^3
    PP2 = logical(sparse(double(PP)*double(PP3))); % PP^4
    PP = PP3;

elseif pattern == 4
    %disp('Start Pattern of A0^4 Map')
    PP = logical(findA);
    PP2 = logical(sparse(double(PP)*double(PP))); % PP^2
    PP3 = logical(sparse(double(PP)*double(PP2))); % PP^3
    PP4 = logical(sparse(double(PP)*double(PP3))); % PP^4
    PP2 = logical(sparse(double(PP)*double(PP4))); %PP^5
    PP = PP4;

elseif pattern == 5
    %disp('Start Pattern of A0^5 Map')
    PP = logical(findA);
    PP2 = logical(sparse(double(PP)*double(PP))); % PP^2
    PP3 = logical(sparse(double(PP)*double(PP2))); % PP^3
    PP4 = logical(sparse(double(PP)*double(PP3))); % PP^4
    PP5 = logical(sparse(double(PP)*double(PP4))); % PP^5
    PP2 = logical(sparse(double(PP)*double(PP5))); % PP^6
    PP = PP5;

elseif pattern == 6
    %disp('Start Pattern of A0^6 Map')
    PP = logical(findA);
    PP2 = logical(sparse(double(PP)*double(PP)));
    PP3 = logical(sparse(double(PP)*double(PP2)));
    PP4 = logical(sparse(double(PP2)*double(PP3)));
    PP5 = logical(sparse(double(PP3)*double(PP4)));
    PP6 = logical(sparse(double(PP4)*double(PP5)));
    PP2 = logical(sparse(double(PP5)*double(PP6)));
    PP = PP5;
    
elseif pattern == 7
    %disp('Start Pattern of A0^7 Map')
    PP = logical(findA);
    PP2 = logical(sparse(double(PP)*double(PP)));
    PP3 = logical(sparse(double(PP)*double(PP2)));
    PP4 = logical(sparse(double(PP2)*double(PP3)));
    PP5 = logical(sparse(double(PP3)*double(PP4)));
    PP6 = logical(sparse(double(PP4)*double(PP5)));
    PP7 = logical(sparse(double(PP5)*double(PP6)));
    PP2 = logical(sparse(double(PP6)*double(PP7)));
    PP = PP7;
    
elseif pattern == 8
    %disp('Start Pattern of A0^8 Map')
    PP = logical(findA);
    PP2 = logical(sparse(double(PP)*double(PP)));
    PP3 = logical(sparse(double(PP)*double(PP2)));
    PP4 = logical(sparse(double(PP2)*double(PP3)));
    PP5 = logical(sparse(double(PP3)*double(PP4)));
    PP6 = logical(sparse(double(PP4)*double(PP5)));
    PP7 = logical(sparse(double(PP5)*double(PP6)));
    PP8 = logical(sparse(double(PP6)*double(PP7)));
    PP2 = logical(sparse(double(PP7)*double(PP8)));
    PP = PP8;
    
elseif pattern == 9
    %disp('Start Pattern of A0^9 Map')
    PP = logical(findA);
    PP2 = logical(sparse(double(PP)*double(PP)));
    PP3 = logical(sparse(double(PP)*double(PP2)));
    PP4 = logical(sparse(double(PP2)*double(PP3)));
    PP5 = logical(sparse(double(PP3)*double(PP4)));
    PP6 = logical(sparse(double(PP4)*double(PP5)));
    PP7 = logical(sparse(double(PP5)*double(PP6)));
    PP8 = logical(sparse(double(PP6)*double(PP7)));
    PP9 = logical(sparse(double(PP7)*double(PP8)));
    PP2 = logical(sparse(double(PP8)*double(PP9)));
    PP = PP9;
    
elseif pattern == 10
    %disp('Start Pattern of A0^10 Map')
    PP = logical(findA);
    PP2 = logical(sparse(double(PP)*double(PP)));
    PP3 = logical(sparse(double(PP)*double(PP2)));
    PP4 = logical(sparse(double(PP2)*double(PP3)));
    PP5 = logical(sparse(double(PP3)*double(PP4)));
    PP6 = logical(sparse(double(PP4)*double(PP5)));
    PP7 = logical(sparse(double(PP5)*double(PP6)));
    PP8 = logical(sparse(double(PP6)*double(PP7)));
    PP9 = logical(sparse(double(PP7)*double(PP8)));
    PP10 = logical(sparse(double(PP8)*double(PP9)));
    PP2 = logical(sparse(double(PP9)*double(PP10)));
    PP = PP10;
    
end