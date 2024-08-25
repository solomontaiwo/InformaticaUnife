close all
clear all
clc

a=-1;
b=2;
f=@(x)x^2*(x+2);
fp=@(x)x*(3*x+4);
x0=(a+b)/2;
tolx=1e-5;
tolf=tolx;
maxit=100;
m=2; % molteplicità calcolata a mano l'altra volta
[x,it]=newton_multipli(f,fp,tolx,tolf,maxit,m);
fprintf("Il valore di x = %g e ci mette %g iterazioni\n",x,it);
