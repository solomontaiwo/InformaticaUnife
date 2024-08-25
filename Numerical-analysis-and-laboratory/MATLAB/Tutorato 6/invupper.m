function [R] = invupper(R)
% INVUPPER - Sovrascrive una matrice triang. sup. invert. con la propria inversa
% SYNOPSIS:
% [R] = invupper(R)
% INPUT:
% R (double array) - Matrice triangolare superiore da invertire
% OUTPUT:
% R (double array) - La matrice in input sovrascritta con la propria inversa
[m,n]=size(R);
if (isempty(find(diag(R)==0))) % oppure find( ~diag(R) )
    R(n,n)=1/R(n,n);
    for i=n-1:-1:1
        R(i,i)=1/R(i,i);
        for j=n:-1:i+1
            R(i,j)=-(R(i,i+1:j)*R(i+1:j,j))*R(i,i);
        end
    end
else
    error('la matrice e'' singolare');
end
end