function [x]=sollupper(R,b)
[m,n] = size(R);

if (m~=n)
    error("matrice di coefficienti non quadrata");
elseif (any(find(diag(R)<eps*norm(R,inf))))
    error("Almeno un elemento diagonale di R è numericamente troppo piccolo");
else
    x = b;
    x(n) = x(n)/R(n,n);
    for i = n-1:-1:1
        x(i) = x(i)-R(i,i+1:n)*x(i+1:n);
        x(i) = x(i)/R(i,i);
    end
end