close all
clear all
clc

f=@(x)x^3-x-1;
gname=@(x)x-(x^3-x-1)/(3*x^2-1);
x0=1.6;
tol=1e-3;
maxit=10;
[x,it]=iterazione(gname,x0,tol,maxit);
fprintf("La soluzione vale %g\n",x);
fprintf("Il numero di iterazioni vale %d\n",it);

gn1=@(x)x-x^3+x+x;
maxit=15;
[x,it]=iterazione(gname,x0,tol,maxit)