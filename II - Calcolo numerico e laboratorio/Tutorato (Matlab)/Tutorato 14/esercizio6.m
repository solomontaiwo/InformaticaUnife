close all
clear all
clc

x=linspace(0,1.7,100);
f=@(x)x.^3-19*x.^2+29*x-20;
fp=@(x)3*x.^2-20*x+29;
plot(x,f(x));
title("Grafico di f");
c=(1.7-0)/2; % (a+b)/2 
toln=1e-9;
tol=1e-3;
maxit=100;
[xn,it]=newton(f,fp,c,toln,toln,maxit);
x0=0;
x1=c;
[xs,its]=secante(f,x0,x1,tol,tol,maxit);
fprintf("Con Newton x = %g e iter %d\n",xn,it);
fprintf("Con Secanti x = %g e iter = %d\n",xs,its);