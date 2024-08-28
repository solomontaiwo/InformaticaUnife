function [L,deter]=cholesky(A)

n=max(size(A));
deter=1;
for j=1:n
    for i=j:n
        s=A(j,i)-A(i,1:j-1)*A(j,1:j-1)';
        if(i==j)
            if(s<=0)
                error("Matrice non definita positiva");
            else
                deter=deter*s;
                p(j)=sqrt(s);
            end
        else
            A(i,j)=s/p(j);
        end
    end
end
L=diag(p)+tril(A)-diag(diag(A));