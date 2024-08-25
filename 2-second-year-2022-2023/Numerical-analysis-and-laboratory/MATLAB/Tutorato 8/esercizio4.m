close all
clear all
clc

A=[2,-1,0;-1,3,1;0,1,5];
b=[1,3,6]';
x=[0,0,0]';
maxit=100;
tol=1e-2;

%metodo di Jacobi
[xj, kj] = jacobi(A, b, x, maxit, tol);
fprintf('Soluzione con jacobi %d\n',xj);
fprintf('Numero di iterazioni Jacobi=%d\n',kj);
%calcolo del raggio spettrale
invD=diag(1./diag(A)); %calcolo D^(-1)
%J=-D^(-1)(L+U) oppure J=D^(-1)(L-U)
J=-invD*(tril(A,-1)+ triu(A,1));
eigsJ=eig(J);
rhoJ=max(abs(eigsJ));
%velocità di convergenza
RinfJ=-log(rhoJ);
fprintf('Il raggio spettrale di Jacobi vale %d e la velocità di convergenza è %d\n\n',rhoJ,RinfJ);

%metodo di Gauss-Seidel
[xg, kg] = gaussSeidel(A, b, x, maxit, tol);
fprintf('Soluzione con Gauss-Seidel %d\n',xg);
fprintf('Numero di iterazioni Gauss-Seidel=%d\n',kg);
%calcolo del raggio spettrale
%G=-(D+L)^(-1)U
GS = -tril ( A ) \ triu (A ,1) ;
eigsGS=eig(GS);
rhoGS=max(abs(eigsGS));
%velocità di convergenza
RinfGS=-log(rhoGS);
fprintf('Il raggio spettrale di Gauss-Seidel vale %d e la velocità di convergenza è %d\n\n',rhoGS,RinfGS);

%metodo SOR
omega=1.2;
[ xs , ks ] = sor (A , b , x , maxit , tol , omega ) ;
fprintf('Soluzione con SOR %d\n',xs);
fprintf('Numero di iterazioni SOR=%d\n',ks);

%calcolo valore ottimale di omega
omegas=2/(1+sqrt(1-rhoJ^2));
%velocità di convergenza
RinfS=-log(omegas-1);
fprintf('Il valore ottimale di omega per SOR vale %d e la velocità di convergenza è %d\n',omegas,RinfS);