close all
clear all
clc

a=2;
b=3;
tol=1e-4;
x=linspace(2,3,100);
f=@(x) (x.^3-25);
[xsb,itb]=bisezione(f,a,b,tol);
fprintf("Il numero di iterazioni per il metodo di bisezione sono %d e la soluzione vale %g\n",itb,xsb);
f1=@(x) (3*x.^2);
plot(x,f(x));
title("Grafico della funzione");
fprintf("Valore f(2) = %g\n",f(2));
fprintf("Valore f(3) = %g\n",f(3));
figure(2)
plot(x,f1(x));
title("Grafico di f primo");
fs=@(x) 6*x;
figure(3)
plot(x,fs(x));
title("Grafico di f secondo");
if abs(f(2))<=(3-2)*abs(f1(2))
    fprintf("Ho convergenza globale\n");
else
    fprintf("Non ho convergenza globale\n")
end