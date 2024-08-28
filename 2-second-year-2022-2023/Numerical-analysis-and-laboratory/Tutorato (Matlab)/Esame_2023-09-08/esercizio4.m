% Cognome Nome
% Matricola
% -----
% Esercizio 4 - Esame Calcolo Numerico del 2023.09.08
% -----

close all; clear all; clc;
disp("Esercizio 4 - Esame Calcolo Numerico del 2023.09.08");

M = [3 -1/3 0; -0.5 2 1/6; 0 -1/5 -3];
z = [ -1.5; 0.7; 1/6];
x0 = 2 * ones(size(z));

disp("Metodo di Jacobi");
d = 1 ./ diag(M);
J = -diag( d ) * (tril(M, -1) + triu(M, 1));
cJ = z .* d;
rhoJ = abs(eigs(J, 1));
RinfJ = -log( rhoJ )

disp("Metodo di Gauss-Seidel:");
GS = tril(M) \ [-triu(M, 1), z];
cGS = GS(:, end), GS(:, end) = []
rhoGS = abs(eigs(GS, 1));
RinfGS = -log( rhoGS )

xJk = x0;
for k = 1 : 5
    xJk = J * xJk + cJ;
end
fprintf("\nAppross. a 5 iterazioni con il metodo di Jacobi: ");
xJk

xGSk = x0;
for k = 1 : 5
    xGSk = GS * xGSk + cGS
end
fprintf("\nAppross. a 5 iterazioni con il metodo di Gauss-Seidel: ");
xGSk

fprintf("\nSoluzione del sistema e differenze relative con xJk e xGSk: ");
xs = M \ z

errRelJ = norm(xJk - xs) / norm(xs)
errRelGS = norm(xGSk - xs) / norm(xs)