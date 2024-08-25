% Congnome Nome
% Matricola
% --------
% Esercizio 3 - Esame Calcolo Numerico del 2023.01.19
% --------

close all; clear variables; clc;
disp("Esercizio 3 - Esame Calcolo Numerico del 2023.01.19");

A = [2 0 0 1; -1 0.5 0 0; 0.3 0 0.6 0; -3 0.2 -0.1 0.5]; 
b = [0, -2, -1, 0]';
xTeoria = [-38, -928, -336, 76]'/213;

[L, R, p, detA] = gauss2(A);
x1 = ltrisol( R, ltrisol(L, b(p)) )
disp("Massima differenza in modulo dalla soluzione teorica:");
disp( max( abs( x1 - xTeoria ) ) );
disp("Residuo normalizzato (in norma infinito):");
disp( ( b - A*x1 ) / norm(b, inf) );
x2 = A \ b

B = A * A';
disp("Fattorizzazione di Cholesky: ");
[Lchol, flag] = chol(B, "lower")
if ( ~flag )
    fprintf("\nB è definita positiva\n");
    c = [8/3 -1/5 3/10 -9/5]';
    x3 = rtrisol( Lchol', ltrisol(Lchol, c) )
else
    error("\nB non è definita positiva\n");
end
