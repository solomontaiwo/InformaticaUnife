% Cognome Nome
% Matricola
% --------
% Esercizio 3 - Esame Calcolo Numerico del 2023.02.08
% --------

close all; clear variables; clc;
disp("Esercizio 3 - Esame Calcolo Numerico del 2023.02.08");

% Prima parte

A = [1/3, 0, 0.5, -1; 0, 3, 0.25, 0; 0.5, 0, 2, 0; 1, 0, -1, 1/3]; 
b = [0, -1/3, 1, 0.25]';

[Q, R] = qr( A )
xQR = utrisol(R, Q'*b)
[L, U, p] = lu(A, "vector");
xLU = utrisol(U, ltrisol(L, b(p)) )
normraDiffSol = norm( xLU,  xQR, inf );
fprintf("\nNorma infinito differenza soluzioni: %g\n\n", normaDiffSol);
normaRelDiffSol = normaDiffSol / norm( xQR, inf )

% Seconda parte
[rankDiade, detDiade, normInfDiade] = miaDiade(Q(:,1), R(1,:)')