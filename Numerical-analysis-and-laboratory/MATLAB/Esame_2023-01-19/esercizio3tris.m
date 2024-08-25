% Cognome Nome
% Matricola
% -------
% Esercizio 3 - Esame Calcolo Numerico del 2023.01.19
% -------

close all; clear all; clc;
disp("Esercizio 3 - Esame Calcolo Numerico del 2023.01.19");

A = [2 0 0 1; 
    -1 0.5 0 0;
    0.3 0 0.6 0;
    -3 0.2 -0.1 0.5]; 
b = [0, -2, -1, 0]';
xTeoria = [-38, -928, -336, 76]'/213;

[L, R, p, deter] = gauss2(A);
x1 = rtrisol(R, ltrisol(L, b(p)) )
disp("Massima differenza in modulo della soluzione teorica:");
disp( max( abs( x1 - xTeoria) ));
disp("Residuo normalizzato (in norma infinito):");
disp( (b - A*x1) / norm(b, inf) );
x2 = A \ b

B = A * A';
c = [8/3; -1/5; 3/10; -9/5];

[L, flag] = chol(B, "lower");

if ( ~flag )
    fprintf("\nB è definita positiva");
    x3 = rtrisol(L', ltrisol(L, c) )
else
    fprintf("\nB non è definita positiva");
end

