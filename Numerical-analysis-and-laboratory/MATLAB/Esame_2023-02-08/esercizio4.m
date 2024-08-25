% Cognome Nome
% Matricola
% ---------
% Esercizio 4 - Esame Calcolo Numerico del 2023.02.08
% ---------

close all; clear variables; clc;
disp("Esercizio 4 - Esame calcolo Numerico del 2023.02.08");

n = 4;
M = [9/4, 0, -1/3, 1/2; 0, -3/2, 0, 3/2; -1/2, 1/3, 7/4, 0; 1/2, 0, 0 -3/2]; 
z = cos((2 : (n+1))') ./ (1 : n)';
d = diag(M);

if any( ~d )
    error("Presenza di elementi diagonali nulli in M");
end
invD = diag( 1 ./ d);
J = -invD * (tril(M, -1) + triu(M, 1));
cJ = z ./ d;
GS = tril(M) \ [-triu(M,1) z];
cGS = GS(:, end); GS(:, end) = [];

x0 = [1; -1; 1; -1]; maxit = 50; tol = 10^-5;
iterJ = 0;  xJ = x0; stop = 0;
while ( ~stop )
    xJold = xJ; iter = iterJ + 1;
    xJ = J * xJ + cJ;
    stop = ( (norm(xJ - xJold, inf) < tol * norm(xJold, inf) ) ...
        || ( iterJ >= maxit ) );
end
xJ, iterJ

% Metodo SOR con omega = 1.03
omega = 1.03;
[xSOR, iterSOR] = sor(M, z, x0, maxit, tol, omega) % Funzione sor allegata
xs = M \ z;

rJ = norm( xJ - xs, inf ) / norm( xs, inf );
rSOR = norm( xSOR - xs, inf ) / norm( xs, inf );

fprintf("\nDistanze relative in norma infinito dalla soluzione:");
fprintf("\n Jacobi: %g,\n SOR: %g\n\n", rJ, rSOR);
