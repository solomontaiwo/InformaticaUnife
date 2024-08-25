close all
clear all
clc

A = [2,-1,0;-1,3,1;0,1,5];
b = [1,3,6]';
maxit = 100;
tol = 1e-2;
x = [0,0,0]';
[x_sol,k] = jacobi(A,b,x,maxit,tol);
fprintf("La soluzione vale %g\n", x_sol);
fprintf("Il numero di iterazioni effettuate è %g\n", k);

%%% Calcolo la matrice J
invD = diag(1./diag(A));
J = -invD*(tril(A,-1) + triu(A,1));

%% Calcolo autovalori
eigsJ = eig(J);

%% Raggio spettrale
rhoJ = max(abs(eigsJ));

%% Velocità di convergenza = -log(raggio spettrale)
RinfJ = -log(rhoJ);

fprintf("Raggio spettrale = %g\n", rhoJ);
fprintf("Velocità di convergenza = %g\n", RinfJ);