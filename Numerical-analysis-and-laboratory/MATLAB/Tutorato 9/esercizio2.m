close all
clear all
clc

x=[0.1,0.4,1.1,1.5];
% y=-log(2.*x);
y=[1.6094,0.2231,-0.7885,-1.0986]; % Valutazione della f nel vettore x
punto=1.2;

[p,coeff]=polyLagrange(x,y,punto);
fpunto=-log(2*punto);
fprintf("Il polinomio in 1.2 vale %g e l'errore rispetto alla funzione originale vale %g\n", p, fpunto-p);

punti=[0.2,0.9,2.7];
[p1,coeff]=polyLagrange(x,y,punti);
fpunti=-log(2*punti);
fprintf("Valore del polinomio nelle zi vale %g\n", p1);
fprintf("Errore commesso= %g\n", fpunti-p1);