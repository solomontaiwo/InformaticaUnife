function [x, k] = gaussSeidel(A, b, x, maxit, tol)
% GAUSSSEIDEL - Metodo iterativo di Gauss-Seidel per sistemi lineari
n = size(A,1);
k = 0; stop = 0;
while ( ~stop )
k = k + 1; xtemp = x;
for i = 1 : n
x(i) = ( -A(i,[1:i-1, i+1:n]) * x([1:i-1, i+1:n]) + b(i) ) / A(i,i);

end
stop = ( norm(xtemp - x, inf) < tol*norm(x, inf) )|| ( k == maxit );

end
if ( k == maxit )
warning('Raggiunto numero max di iterazioni maxit = %d', maxit);

end
end % fine della M-function gaussSeidel.m