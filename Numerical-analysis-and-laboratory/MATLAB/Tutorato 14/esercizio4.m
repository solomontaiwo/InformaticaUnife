close all
clear all
clc

x0=0;
x=linspace(-1,1,100);
f=@(x)x.^2+2*x.*exp(x)+exp(2*x);
fp=@(x)2.*(exp(x)+1).*(x+exp(x));
fs=@(x)2.*exp(x).*(x+2)+4.*exp(2.*x)+2;

plot(x,f(x));
title("Grafico della f");
tol=1e-10;
maxit=100;
[xh,ith]=halley(f,fp,fs,x0,tol,tol,maxit);
fprintf("Metodo di Halley x0 = %g e numero di iter = %d\n", xh, ith);
m=2;
[xn,itn]=newton_multipli(f,fp,x0,tol,tol,maxit,m);
fprintf("Metodo di Newton multipli x = %g e numero di iter = %d\n", xn,itn);