% Cognome Nome
% Matricola
% Esercizio 3 - 19.07.2023

close all; clear all; clc;
disp("Esercizio 3");

A = [0.5 1.5 -0.5; 1 2 2; 4 7 -1]; b = [-1 -2 0]';
xTeoria = [10/3 -2 -2/3];

[L, R, p, detA] = gauss2(2);
x1 = utrisol(R, ltrisol(L, b(p)))
disp("Massima differenza in modulo dalla soluzione teorica: ");
disp(max(abs(x1 - xTeoria)));
disp("Residuo normalizzato (in norma infinito): ");
disp((b - A*x1) / norm(b, inf));
x2 = A \ b

B = A * A';
disp("Fattorizzazione di Cholesky: ");
[Lchol, p] = chol(B, "lower");
if (~p)
    fprintf("\nB è definita positiva\n");
else
    error("\nB non è definita positiva\n");
end

c = [3/5, -2/3, -1/7]';
x3 = utrisol(Lchol', ltrisol(Lchol, c))