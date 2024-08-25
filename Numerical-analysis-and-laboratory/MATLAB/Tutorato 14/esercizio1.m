close all
clear all
clc

x=linspace(0,3,100);
f=@(x) 2*cos(x)-exp(x)+5/2;

plot(x,f(x),"r");
title("Grafico della funzione");

x0=-0.3; % punto iniziale
tol=1e-6;
maxit=100;
fp=@(x)-exp(x)-2*sin(x); % derivata prima
[x,it]=newton(f,fp,x0,tol,tol,maxit);

fprintf("Valore della radice = %g\n",x);
fprintf("Numero di iterazioni = %g\n",it);
alpha=1.1814639003600901;
err=abs(alpha-x);
fprintf("Errore assoluto = %g\n",err);