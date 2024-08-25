function [x, k] = jacobi(A, b, x, maxit, tol)
% JACOBI - Metodo iterativo di Jacobi per sistemi lineari
n = size(A,1);
if ( issparse(A) )
    d = spdiags(A, 0);
else
    d = diag( A );
end
if ( any(abs(d)<eps*norm(d,inf)))
    error('Elementi diagonali troppo piccoli.');
end
b = b./d;
k = 0; stop = 0;
while ( ~stop )
    k = k + 1;
    xtemp = x;
    x = x - (A*x)./d + b; % istruzione vettoriale
    stop = ( norm(xtemp-x,inf)<tol*norm(x, inf) ) || ( k == maxit );

end
if ( k == maxit )
    warning('Raggiunto numero max di iterazioni maxit = %d', maxit);
end
end % fine della M-function jacobi.m