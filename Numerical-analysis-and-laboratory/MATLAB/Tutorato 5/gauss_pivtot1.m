function [L,U,P,Q,rango]=gauss_pivtot1(A)
[n,m]=size(A);
p = 1:n;
q = 1:m;
tempr = zeros(1,m);
tempc = zeros(n,1);
tol = eps*norm(A,inf);
r = min([n-1,m]);
rango = min([m,n]);
for k = 1:r
    [maxc,rowind] = max(abs(A(k:n,k:m)));
    [~,colind] = max(maxc);
    row = rowind(colind)+k-1;
    col = colind+k-1;
    if k~=row
        %% Scambio
        tempr = A(k,:);
        A(k,:) = A(row,:);
        A(row,:) = tempr;
        aux = p(k);
        p(k) = p(row);
        p(row) = aux;
    end
    if k~=col
        %% Scambio
        tempc = A(:,k);
        A(:,k) = A(:,col);
        A(:,col) = tempc;
        aux = q(k);
        q(k) = q(col);
        q(col) = aux;
    end
    if abs(A(k,k)) < tol
        rango = k - 1;
        break
    end
    A(k+1:n,k) = A(k+1:n,k)/A(k,k);
    A(k+1:n,k+1:m) = A(k+1:n,k+1:m) - A(k+1:n,k)*A(k,k+1:m);
end

L = tril(A,-1) + eye(n);
U = triu(A);
P = eye(n);
P = P(p,:);
Q = eye(n);
Q = Q(:,q);
