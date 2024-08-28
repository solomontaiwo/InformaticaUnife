% Cognome Nome
% Matricola 
% Esercizio 3 - Esame Calcolo Numerico del 2023.07.19

close all; clear all; clc;
disp("Esercizio 3 - Esame Calcolo Numerico del 2023.07.19");

A = [0.5 1.5 -0.5; 1 2 2; 4 7 -1]; 
b = [-1 -2 0]'; 
xTeoria = [10/3 -2 -2/3]';

[L, R, p, detA] = gauss2(A);
x1 = utrisol( R, ltrisol(L, b(p)) )
disp("Massima differenza in modulo della soluzione teorica: ");
disp( max( abs( x1 - xTeoria ) ) );
disp("Residuo normalizzato (in norma infinito):");
disp( (b - A*x1) / norm(b, inf) );
x2 = A \ b

B = A * A'; c = [3/5; -2/3; -1/7];

[L, flag] = chol(B, "lower");

if ( ~flag )
    fprintf("\nB è definita positiva");
    x3 = utrisol( L', ltrisol(L, c) )
else
    fprintf("\bB non è definita positiva");
end

