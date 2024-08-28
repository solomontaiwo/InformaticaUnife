function [R]=invupper(R)
[m,n]=size(R);
if(isempty(find(diag(R)==0)))
    R(n,n)=1/R(n,n);
    for i=n-1:-1:1
        R(i,i)=1/R(i,i);
        for j=n:-1:i+1
            R(i,j)=-(R(i,i+1:j)*R(i+1:j,j))*R(i,i);
        end
    end
else
    error('La matrice è singolare');
end

