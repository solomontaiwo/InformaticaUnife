% Cognome Nome
% Matricola
% ---------
% Esercizio 4 - Esame Calcolo Numerico del 2023.01.19
% ---------

close all; clear variables; clc;
disp("Esercizio 4 - Esame Calcolo Numerico del 2023.01.19");

A = [8/3 -1 1/2; 2/5 7/3 1/2; 3/5 -1/3 4]; 
b = [1, -5, -2]';

d = diag( A );
if any( ~d )
    error("Presenza i elementi diagonali nulli in A");
end

invD = diag( 1./ d);
J = -invD * (tril(A, -1) + triu(A, 1));
cJ = b ./ d;
GS = -tril(A) \ triu(A,1);

eigsJ = eig( J ); rhoJ = max( abs(eigsJ) ); velJ = -log( rhoJ );
eigsGS = eig( GS ); rhoGS = max( abs(eigsGS) ); velGS = -log( rhoGS );

fprintf("\nAutovalor della matrice J di Jacobi:\n"); disp(eigsJ);
fprintf("Raggio spettrale di J e velocità asintotica di convergenza:\n");
fprintf("\trhoJ = %g,\t\tRinftyJ = %g\n", rhoJ, velJ);

fprintf("\nAutovalor della matrice GS di Gauss-Seidel:\n"); disp(eigsGS);
fprintf("Raggio spettrale di GS e velocità asintotica di convergenza:\n");
fprintf("\trhoGS = %g,\t\tRinftyGS = %g\n", rhoGS, velGS);

x0 = [1; -2; 1]; maxit = 50; tol = 10^-5;

% Soluzione con il metodo di Jacobi, utilizzando la M-function fornita
fprintf("\nAppros. xJ calcolata con il metodo di Jacobi e numero" + ...
    "di iterazioni:")
[xJ, iter] = jacobi(A, b, x0, maxit, tol)

% Metodo SOR con omega = 1.27
omega = 1.27;
SOR = (diag(d) + omega*tril(A, -1)) \ [((1 - omega)*diag(d) - omega* ...
    triu(A, 1)), b];
cSOR = SOR(:, end); SOR(:, end) = [];
fprintf("\nMatrice del metodo SOR con omega = %g:\n", omega); disp(SOR);
for k = 1 : 2
    xSOR = SOR*x0 + cSOR;
    x0 = xSOR;
end
fprintf("\nSecondo iterato del metodo SOR:\n");
disp(xSOR)