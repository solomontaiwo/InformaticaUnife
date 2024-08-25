close all
clear all
clc

f=@(x) exp(3*x);
fder=@(x) 3*exp(3*x);

x=[0 0.05 0.1 0.15]';
fnodi=f(x);
fpnodi=fder(x);
xstar=0.12;
[pxstar]=poliherm(x,fnodi,fpnodi,xstar);
fesatta=f(xstar);
errore=abs(fesatta-pxstar);
fprintf("Valore dell'errore = %g\n", errore);