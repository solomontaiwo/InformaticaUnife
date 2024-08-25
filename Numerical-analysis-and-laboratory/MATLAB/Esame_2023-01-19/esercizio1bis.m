% Cognome nome
% Matricola
% Esercizio 1 - esame del 2023.01.19
close all; clear all; clc

disp("Esercizio 1 - esame del 2023.01.19")

p7 = zeros(8,1);
p7(1) = abs(tan(4.2*pi-2.8));
p7(2) = log2(acos(1.64-exp(0.7)));
p7(4) = (1/4)*max(exp(pi), pi^exp(1));
p7(6) = min([sin(5.7), 71.6*exp(-4), 2.3/pi^2]);
p7(7) = 9.0534;
p7(8) = -sqrt(-log(3/10^5));

x0 = input("\nInserisci il punto in cui valutare il polinomio p7: x0 = ");

[r, q] = ruffiniHorner(p7, x0);
[derp, q1] = ruffiniHorner(q, x0);
[ders, q2] = ruffiniHorner(q1, x0);

fprintf("\nIl valore del polinomio p7(x) nel punto %g è %g\n", x0, r);
fprintf("La derivata prima p'7(x) è pari a %g\n", derp);
fprintf("La derivata seconda p''7(x) è pari a %g\n", ders*2);

ph = fplot(@(x)(polyval(p7, x)), [-2.5,1.1]);