% Cognome Nome
% Matricola
% -----------
% Esercizio 3 - 19/01/2023
% -----------

close all; clear all; clc;
disp("Esercizio 3");

A = [2 0 0 1; -1 0.5 0 0; 0.3 0 0.6 0; -3 0.2 -0.1 0.5]; 
b = [0, -2, -1, 0]';
xTeoria = [-38, -928, -336, 76]'/213;

% Prima parte
[L, R, p, detA] = gauss2(A);
x1 = rtrisol(R, ltrisol(L, b(p)) )

disp("Massima differenza in modulo della soluzione teorica: ");
disp( max( abs( x1 - xTeoria) ) );
disp("Residuo normalizzato (in norma infinito): ");
disp( (b - A*x1) / norm(b, inf) );
x2 = A \ b % soluzione calcolata dalla funzione standard di Matlab

% seconda parte
B = A * A';
disp("Fattorizzazione di Cholesky:");
[Lchol, flag] = chol(B, "lower");

if ( ~flag )
    fprintf("\nB è definita positiva\n");
    c = [8/3, -0.2, 0.3, -9/5]';
    x3 = rtrisol(Lchol', ltrisol(Lchol, c) );
else
    error("\nB non è definita positiva\n");
end

