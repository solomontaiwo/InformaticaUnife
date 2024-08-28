% Cognome Nome
% Matricola
% -----
% Esercizio 3 - Esame Calcolo Numerico del 2023.09.08
% -----

close all; clear all; clc;

A = [ 3.4 1.4 -1.8 2.7; 1.4 1.9 -0.4 -1.0; -1.8 -0.4 2.2 -3.4; 
    2.7 -1.0 -3.4 7.8 ];
b = [1.1 -0.5 2.3 0.9]';
xTeoria = [-0.6290, 4.2476, 8.1496, 4.4301]';

[L, flag] = chol(A, "lower");
x1 = utrisol( L', ltrisol(L, b) )

disp("Massima differenza in modulo della soluzione teorica: ");
disp( max( abs( x1 - xTeoria) ) );
disp("Residuo normalizzato (in norma infinito): ");
disp( (b - A*x1) / norm(b, inf) );

x2 = A \ b

B = -L' * L; c = [-1.5, 0.8, 3.1, -0.6]';
disp("Fattorizzazione di Cholesky di B:");
[L1, p] = chol(B, "lower");
if ( ~p )
    fprintf("\nB è definita positiva\n");
    x3 = utrisol( L1', ltrisol(L1, c) )
else
    fprintf("\nB non è definita positiva\n");
    x3 = B \ c
end