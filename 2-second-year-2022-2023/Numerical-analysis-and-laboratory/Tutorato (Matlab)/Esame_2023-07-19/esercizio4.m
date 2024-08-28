% Congnome Nome
% Matricola
% Esercizio 4 - Esame Calcolo Numerico del 2023.07.19

close all; clear all; clc;
disp("Esercizio 4 - Esame Calcolo Numerico del 2023.07.19");

A = [2 0 1/2; 0 4/3 -5/4; 2/3 0 1];
b = [1/3, -2, -1]';

d = diag(A);
invD = diag( 1 ./ d );
J = -invD * ( tril(A, -1) + triu(A, 1));
GS = -tril(A) \ triu(A, 1);
eigsJ = eig( J )
eigsGS = eig( GS )
rhoJ = max(abs(eigsJ)); RinfJ = -log( rhoJ );
rhoGS = max(abs(eigsGS)); RinfGS = -log( rhoGS );
fprintf("\nrho(J) = %e, rho(GS) = %e", rhoJ, rhoGS);
fprintf("\nRinf(J) = %f, Rinf(GS) = %f\n", RinfJ, RinfGS);

tol = 10e-5; maxit = 50; x0 = ones(size(b));
[xJ, iterJ] = jacobi(A, b, x0, maxit, tol);
fprintf("\nNumero dii iterazioni di Jacobi: iterJ = %d", iterJ);
fprintf("\nSoluzione calcolata con il metodo di Jacobi:");
xJ

% Soluzione con il metodo di SOR
omega = 0.82;
SOR = (diag(d) + omega*tril(A, 1)) ...
    \ [( (1-omega)*diag(d) - omega*triu(A,1) ), omega*b]
cSOR = SOR(:, end); SOR(:,end) = []; xSOR = x0;
for k = 1 :6, xSOR = SOR*xSOR + cSOR; end
xSOR