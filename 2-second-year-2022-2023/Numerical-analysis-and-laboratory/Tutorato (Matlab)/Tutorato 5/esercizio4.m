close all
clear all
clc

A=[1 3 -1; 2 4 1; 3 6 -2];
b = [2, 7, 7]';
[L,R,P,Q] = gauss_pivtot1(A)
fprintf("La soluzione vale: ")
y = sollower(L,P*b);
z = solupper(R,y);
x = Q*z

fprintf("\nResiduo normalizzato: %g", (b-A*x)/norm(b,inf));
[L,R,P] = lu(A);
fprintf("\nSoluzione con nativa:");
y = sollower(L,P*b);
x1 = solupper(R,y);
fprintf("\nResiduo normalizzato: %g", (b-A*x1)/norm(b,inf));
