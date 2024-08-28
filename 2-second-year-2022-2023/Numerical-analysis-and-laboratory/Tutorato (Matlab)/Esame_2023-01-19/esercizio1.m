% Cognome nome
% Numero di matricola
% --------------------
%   esercizio 1 - prova scritta e pratica del 19/01/2023
% --------------------
close all; clear all; clc;
disp("Esercizio 1");

p7 = zeros(8,1);
p7(1) = abs(tan(4.2*pi - 2.8));
p7(2) = log2(acos(1.64 - exp(0.7)));
p7(4) = 0.25*max(exp(pi), pi^exp(1));
p7(6) = min([sin(5.7), 71.6*exp(-4), 2.3/pi^2]);
p7(7) = 9.0534;
p7(8) = -sqrt(-log(3/10^5));

x0 = input("Inserisci il punto x0 (double) in cui valutare il polinimio: x0 = ");

[r, q] = ruffiniHorner(p7, x0);
[derivataprima, q1] = ruffiniHorner(q, x0);
[derivataseconda, q2] = ruffiniHorner(q1, x0);

fprintf("\nValore del polinomio p7(x) = %g\n", r);
fprintf("Derivata prima p'(x) = %g\n", derivataprima);
fprintf("Derivata seconda p''(x) = %g\n", derivataseconda * 2);
ph = fplot(@(x)(polyval(p7, x)), [-2.5, 1.1]);

